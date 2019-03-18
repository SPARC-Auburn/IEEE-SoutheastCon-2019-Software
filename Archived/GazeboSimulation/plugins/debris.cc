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

#include "build/msgs/scoreinfo.pb.h"
namespace gazebo
{
  class DebrisPlugin : public ModelPlugin
  {
    
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
    {
      // Store the pointer to the model
      this->model = _parent;
      srand(time(NULL));
      std::string name = this->model->GetName();
      int index = name.back()-48;

      if(name.find("cube")!=std::string::npos){
        sdf::ElementPtr pS = _parent->GetSDF()->GetElement("link")->GetElement("visual")->GetElement("geometry")->GetElement("mesh")->GetElement("uri");
        pS->GetValue()->SetFromString(this->colorCubes[index/2]);       //0 is 48, cause ascii or something
        this->color = static_cast<scoreinfomsgs::ScoreInfo::Color>(index/2);
        this->type = scoreinfomsgs::ScoreInfo::CUBE;
      }
      else{
        sdf::ElementPtr pS = _parent->GetSDF()->GetElement("link")->GetElement("visual")->GetElement("geometry")->GetElement("mesh")->GetElement("uri");
        pS->GetValue()->SetFromString(this->colorSpheres[index]);       //0 is 48, cause ascii or something
        this->color = static_cast<scoreinfomsgs::ScoreInfo::Color>(index);
        this->type = scoreinfomsgs::ScoreInfo::SPHERE;
      }
      

      this->node = transport::NodePtr(new transport::Node());
      this->node->Init(this->model->GetWorld()->Name());
      this->pub = node->Advertise<scoreinfomsgs::ScoreInfo>("~/scoring/info");
      this->sub = node->Subscribe("~/scoring/command", &DebrisPlugin::evalScore,this);
    }

    // Called by message publication
    public: void evalScore(ConstIntPtr &_msg)
    {
        scoreinfomsgs::ScoreInfo scoreMsg;
        scoreMsg.set_color(this->color);
        scoreMsg.set_type(this->type);
        const ignition::math::Pose3d pose = this->model->WorldPose();
        const ignition::math::Vector3d position = pose.Pos();
        float x = position.X();
        float y = position.Y();
        if(pow(x,2)+pow(y,2) < 1){
          scoreMsg.set_loc(scoreinfomsgs::ScoreInfo::CENTER);
        }
        else if(x>0){
          if(y>0){
            scoreMsg.set_loc(scoreinfomsgs::ScoreInfo::B);
          }
          else{
            scoreMsg.set_loc(scoreinfomsgs::ScoreInfo::G);
          }
        }
        else{
          if(y>0){
            scoreMsg.set_loc(scoreinfomsgs::ScoreInfo::Y);
          }
          else{
            scoreMsg.set_loc(scoreinfomsgs::ScoreInfo::R);
          }
        }
        scoreMsg.set_corner(1.22-abs(x)<.3 && 1.22-abs(y) < .3);
        this->pub->Publish(scoreMsg);
    }
    
    // Pointer to the model
    private: physics::ModelPtr model;
    
    public:  scoreinfomsgs::ScoreInfo::Color color;
    public:  scoreinfomsgs::ScoreInfo::Type  type;
    private: transport::NodePtr node;
    private: transport::PublisherPtr pub;
    private: transport::SubscriberPtr sub;
    private: std::string colorCubes[4] = {"model://debrisCube/meshes/cubeRed.dae", "model://debrisCube/meshes/cubeGreen.dae","model://debrisCube/meshes/cubeBlue.dae","model://debrisCube/meshes/cubeYellow.dae"};
    private: std::string colorSpheres[4] = {"model://debrisSphere/meshes/sphereRed.dae", "model://debrisSphere/meshes/sphereGreen.dae","model://debrisSphere/meshes/sphereBlue.dae","model://debrisSphere/meshes/sphereYellow.dae"};
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(DebrisPlugin)
}
