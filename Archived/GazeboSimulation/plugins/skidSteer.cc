#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <ignition/math/Pose3.hh>
#include <sdf/sdf.hh>
#include <iostream>
#include <fstream>

namespace gazebo
{
  class SkidSteer : public ModelPlugin
  {
    private: double wheelSeparation;
    private: double wheelRadius;
    private: common::PID pidLeft;
    private: common::PID pidRight;
    private: physics::JointPtr joints[4];
    private: physics::ModelPtr model;
    private: physics::WorldPtr world;
    public: enum {RIGHT_FRONT, RIGHT_REAR, LEFT_FRONT, LEFT_REAR};
    private: double maxTorque;
    private: double maxSpeed;
    private: double efficiency;//of gearbox etc
    private: double encoderFidelity;
    private: double equilibriumMax;//determined via experimentation
    private: double lastTime = 0;
    private: double curTime = 0;
    private: double lastPosLeft = 0;
    private: double lastPosRight = 0;
    private: std::ofstream myfile;
    
    private: double rotationSpeed = 0.3;//radius of the curvature desired
    private: double forwardSpeed = 0.5;//should be a scalar zero to one
    
    private: double theta = 0.0;//all three of these are estimated by algortihms below
    private: double x;//both of these are initialized by the loader to ensure proper placement of the ghost
    private: double y;
    
    private: physics::EntityPtr ghost;
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
    {
        this->model = _parent;
        this->world = this->model->GetWorld();
        this->joints[RIGHT_FRONT] = this->model->GetJoint("right_front");//this setup is blatantly stolen from the default skidsteer plugin
        this->joints[RIGHT_REAR]  = this->model->GetJoint("right_rear");
        this->joints[LEFT_FRONT]  = this->model->GetJoint("left_front");
        this->joints[LEFT_REAR]   = this->model->GetJoint("left_rear");

        this->wheelSeparation = this->joints[RIGHT_FRONT]->Anchor(0).Distance(this->joints[LEFT_FRONT]->Anchor(0)); //assumes the joints are located in the dead middle of the wheel
        physics::EntityPtr wheelLink = boost::dynamic_pointer_cast<physics::Entity>(this->joints[LEFT_FRONT]->GetChild());
        if (wheelLink)
        {
          ignition::math::Box bb = wheelLink->CollisionBoundingBox();
          this->wheelRadius = bb.Size().Max() * 0.5;
        }
        printf("wheel radius detected as:%f\n",this->wheelRadius);
        printf("wheel seperation detected as:%f\n",this->wheelSeparation);
        this->node = transport::NodePtr(new transport::Node());
        this->node->Init(_parent->GetWorld()->Name());
        this->velSub = this->node->Subscribe(std::string("~/") + this->model->GetName() + std::string("/vel_cmd"), &SkidSteer::OnVelMsg, this);
        this->updateConnection = event::Events::ConnectWorldUpdateEnd(std::bind(&SkidSteer::onUpdate, this));
        getParam(&maxTorque,"skidsteer_motor_max_torque",_sdf,0.71*12);//vex775 pro with a 30 to one gearbox
        getParam(&maxSpeed,"skidsteer_motor_max_speed",_sdf,18730/12);//vex775 pro with a 30 to one gearbox
        getParam(&efficiency,"skidsteer_gear_efficiency",_sdf,0.95);//random value, seemed good enough, flat torque losses from friction should be in the sdf, not here
        getParam(&encoderFidelity,"skidsteer_encoder_fidelity",_sdf,1024*12);//assuming 1024 pings per revolution and 30:1 ratio, there would be 30720 pings per wheel revolution
        getParam(&equilibriumMax,"skidsteer_equilibrium_max",_sdf,1.5);
        this->maxSpeed = this->maxSpeed*2*M_PI/60; //converion to rads/s
        

        ghost = this->model->GetLink("ghost");
        
        
        pidLeft.Init(9,1,-0.0001,-6);
        pidRight.Init(9,1,-0.0001,-6);
        myfile.open("data.csv");

    }
    private: void getParam(double *val, std::string name, sdf::ElementPtr _sdf, double def){
        if (!_sdf->HasElement(name))
        {
            printf("Missing parameter <%s> in  plugin SkidSteer for %s, defaulting to %f\n",name.c_str(),this->model->GetName().c_str(),def);
            *val = def;
        }
        else *val = std::stod(_sdf->GetElement(name)->GetValue()->GetAsString());
    }
    /*private: double adjustedVelocity(double timeDif, double lastPos, double curPos){//essentially rounds the position sensing to equal to what a encoder would read rather than the physics engine. Shouldnt make much difference with high quality encoders
        double curPos2 = sgn(curPos)*(std::abs(curPos) - (floor((std::abs(curPos)/(2*M_PI))*encoderFidelity)/encoderFidelity)*2*M_PI);
        double lastPos2 = sgn(lastPos)*(std::abs(lastPos) - (floor((std::abs(lastPos)/(2*M_PI))*encoderFidelity)/encoderFidelity)*2*M_PI);
        double ret = (curPos2-lastPos2)/timeDif;
        //printf("%f       %f       %f\n",curPos,lastPos,ret);
        return ret;
    }
    template <typename T> int sgn(T val) {
      int ret = (T(0) < val) - (val < T(0));
      if(ret==0)ret=1;
      //printf("%i\n",ret);
      return ret;
    }*/
    public: void onUpdate()
    {
        curTime = this->world->SimTime().Double();
        if(lastTime == 0){
            ignition::math::Pose3d pose = this->model->WorldPose();
            this->x = pose.Pos().X();
            this->y = pose.Pos().Y();
            lastTime = curTime;
            printf("x:%f\ny%f",x,y);
        }
        driveRadius(curTime);
        estimatePosition(curTime);
        
        
        ignition::math::Pose3d pose(this->x,this->y,this->model->WorldPose().Pos().Z(),0,0,theta);
        ghost->SetWorldPose(pose);

        pose = this->model->WorldPose();
        myfile<<pose.Pos().X()<<","<<pose.Pos().Y()<<","<<pose.Rot().Euler().Z()<<"\n";
        
        lastTime = curTime;
        lastPosRight = this->joints[RIGHT_FRONT]->Position(0);//unused rn
        lastPosLeft  = this->joints[LEFT_FRONT ]->Position(0);
    }
    private: void estimatePosition(double time){//a lot of math incoming. Ask roppel if you want a book explaining the math behind diff drive position estimation
      double tinc = time-lastTime;
      double rightSpeed  = -this->joints[RIGHT_FRONT]->GetVelocity(0);
      double leftSpeed   = -this->joints[LEFT_FRONT ]->GetVelocity(0);
      double inV[3][3] = {{cos(theta), -sin(theta), 0}, {sin(theta), cos(theta), 0},{0, 0, 1}};
      
      double xsi_R_dot[3][1] = {{wheelRadius*rightSpeed/2 + wheelRadius*leftSpeed/2},{0},{wheelRadius*rightSpeed/(2*wheelSeparation)-wheelRadius*leftSpeed/(2*wheelSeparation)}};
      double xsi_I_dot[3][1];
      mul_arr(inV,xsi_R_dot,xsi_I_dot);
      
      this->x     += xsi_I_dot[0][0]*tinc;
      this->y     += xsi_I_dot[1][0]*tinc;
      this->theta += xsi_I_dot[2][0]*tinc;
      printf("Stuff: %f      %f          %f         %f\n",xsi_I_dot[0][0]*tinc,xsi_I_dot[1][0]*tinc,xsi_I_dot[2][0]*tinc,tinc);
      myfile<<x<<","<<y<<","<<theta<<",";
    }
    
    
    private: void mul_arr(double m1[3][3],double m2[3][1],double m3[3][1]){
      int i,j,k;
      for(i=0;i<3;i++){
        for(j=0;j<1;j++){
          for (k=0;k<3;k++){
            m3[i][j] = m3[i][j] + (m1[i][k] * m2[k][j]);
          }
        }  
      }
    } 
    private: void driveRadius(double time){
        //eqautions for turning from here: http://robotsforroboticists.com/drive-kinematics/
        //this is assuming that the two wheels on each side are chained together and thus their speeds must be indentical.
        //To account for this,half the torque availabe from the motor will be applied to the front wheels and the physics engine will be told that the back wheels velocity is identical to that of the front
        double rightTorque = (this->maxTorque/this->maxSpeed)*(this->maxSpeed - std::abs(this->joints[RIGHT_FRONT]->GetVelocity(0)))*efficiency; //this is a basic model for max torque available but its not the worst and it uses readily available motor stats
        double leftTorque  = (this->maxTorque/this->maxSpeed)*(this->maxSpeed - std::abs(this->joints[LEFT_FRONT ]->GetVelocity(0)))*efficiency; //these are derived for accuracy of physical system and thus dont need to use adjusted wheelspeed value
        double rightSpeed  = -this->joints[RIGHT_FRONT]->GetVelocity(0);//adjustedVelocity(curTime-lastTime,this->lastPosRight,this->joints[RIGHT_FRONT]->Position(0));
        double leftSpeed   = -this->joints[LEFT_FRONT ]->GetVelocity(0);//adjustedVelocity(curTime-lastTime,this->lastPosLeft,this->joints[LEFT_FRONT ]->Position(0));
        /*
        double vel_lin = this->forwardSpeed / this->wheelRadius;
        double vel_rot = this->rotationSpeed * (this->wheelSeparation / this->wheelRadius);
        double rightDesired = vel_lin + vel_rot; // this is a twist command system, aka the value rotationSpeed speed dictates the angular velocity
        double leftDesired  = vel_lin - vel_rot;*/
        
        double rightDesired = 0;
        double leftDesired  = 0;
        if(rotationSpeed > 0){
          rightDesired = forwardSpeed*equilibriumMax/wheelRadius;
          leftDesired = ((rotationSpeed - wheelSeparation/2)/(rotationSpeed + wheelSeparation/2))*rightDesired;
        }
        else{
          leftDesired = forwardSpeed*equilibriumMax/wheelRadius;
          rightDesired = ((abs(rotationSpeed) - wheelSeparation/2)/(abs(rotationSpeed) + wheelSeparation/2))*leftDesired;
        }
        
        
        double rerror = rightSpeed-rightDesired;
        double lerror = leftSpeed-leftDesired;
        
        pidRight.SetCmdMax(rightTorque);
        pidRight.SetCmdMin(-rightTorque);
        pidLeft.SetCmdMax(leftTorque);
        pidLeft.SetCmdMin(-leftTorque);
        
        double rapply = -pidRight.Update(rerror,curTime-lastTime);
        double lapply = -pidLeft.Update(lerror,curTime-lastTime);
        printf("Right:%f       %f       %f    %f        \n",rightTorque,rightSpeed,rightDesired,rapply);
        printf("Left: %f       %f       %f    %f        \n",leftTorque,leftSpeed,leftDesired,lapply);
        
        myfile<<rightSpeed<<","<<rightDesired<<","<<rapply<<","<<rightTorque<<","<<leftSpeed<<","<<leftDesired<<","<<lapply<<","<<leftTorque<<",";
        //synchronization of wheel speeds
        this->joints[RIGHT_REAR]->SetVelocity(0, this->joints[RIGHT_FRONT]->GetVelocity(0));
        this->joints[LEFT_REAR ]->SetVelocity(0, this->joints[LEFT_FRONT ]->GetVelocity(0));
        //printf("stuf: %f       %f       %f    %f       %f\n",vel_lin,vel_rot,forwardSpeed,wheelRadius,this->wheelSeparation);
        this->joints[RIGHT_FRONT]->SetForce(0,rapply/2);
        this->joints[RIGHT_REAR ]->SetForce(0,rapply/2);
        this->joints[LEFT_FRONT ]->SetForce(0,lapply/2);
        this->joints[LEFT_REAR  ]->SetForce(0,lapply/2);
    }
    // Called by message publication
    public: void OnVelMsg(ConstPosePtr &_msg)
    {
      this->forwardSpeed  = _msg->position().x();
      this->rotationSpeed = msgs::ConvertIgn(_msg->orientation()).Euler().Z();
    }
    private: transport::NodePtr node;
    private: transport::SubscriberPtr velSub;
    private: event::ConnectionPtr updateConnection;

  };
  
  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(SkidSteer)
}
