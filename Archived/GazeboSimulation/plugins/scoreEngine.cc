#include <ignition/math/Pose3.hh>
#include "gazebo/physics/physics.hh"
#include "gazebo/common/common.hh"
#include "gazebo/gazebo.hh"
#include "build/msgs/scoreinfo.pb.h"
namespace gazebo
{
  class ScoreEngine : public WorldPlugin
  {
    private: int score;
    private: bool scoreStarted = false;
    private: int scoresReceived;
    public: void Load(physics::WorldPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      this->parent = _parent;
      this->node = transport::NodePtr(new transport::Node());
      this->node->Init(_parent->Name());
      this->pub = node->Advertise<gazebo::msgs::Int>("~/scoring/command");
      this->sub = node->Subscribe("~/scoring/info", &ScoreEngine::recv,this);
      this->updateConnection = event::Events::ConnectWorldUpdateEnd(std::bind(&ScoreEngine::onUpdate, this));
      this->resetConnection = event::Events::ConnectWorldReset(std::bind(&ScoreEngine::onReset, this));
    }
    public: void recv(const boost::shared_ptr<const scoreinfomsgs::ScoreInfo> &_msg)
    {
      std::string output = "";
      this->scoresReceived+=1;
      switch(_msg->color()){
        case scoreinfomsgs::ScoreInfo::RED:
          output+="Red ";
          break;
        case scoreinfomsgs::ScoreInfo::BLUE:
          output+="Blue ";
          break;
        case scoreinfomsgs::ScoreInfo::YELLOW:
          output+="Yellow ";
          break;
        case scoreinfomsgs::ScoreInfo::GREEN:
          output+="Green ";
          break;
      }
      switch(_msg->type()){
        case scoreinfomsgs::ScoreInfo::CUBE:
          output+="Cube ";
          break;
        case scoreinfomsgs::ScoreInfo::SPHERE:
          output+="Sphere ";
          break;
      }
      output+="in ";
      switch(_msg->loc()){
        case scoreinfomsgs::ScoreInfo::R:
          output+="Red Quadrant ";
          score += 10;
          if(_msg->color() == scoreinfomsgs::ScoreInfo::RED){
            score += 10;
          }
          break;
        case scoreinfomsgs::ScoreInfo::B:
          output+="Blue Quadrant ";
          score += 10;
          if(_msg->color() == scoreinfomsgs::ScoreInfo::BLUE){
            score += 10;
          }
          break;
        case scoreinfomsgs::ScoreInfo::Y:
          output+="Yellow Quadrant ";
          score += 10;
          if(_msg->color() == scoreinfomsgs::ScoreInfo::YELLOW){
            score += 10;
          }
          break;
        case scoreinfomsgs::ScoreInfo::G:
          output+="Green Quadrant ";
          score += 10;
          if(_msg->color() == scoreinfomsgs::ScoreInfo::GREEN){
            score += 10;
          }
          break;
        case scoreinfomsgs::ScoreInfo::CENTER:
          output+="Center";
          break;
      }
      if(_msg->corner()){
        output+="corner";
        score+=10;
      }
      printf("%s\n",output.c_str());
      
      if(this->scoresReceived == 12){
        printf("Scoring complete. Calculated score is:%d\n\n\n",this->score);
        this->parent->Reset();
        this->parent->SetPaused(false);
        this->score = 0;
        this->scoreStarted = false;
        this->scoresReceived = 0;

      }
    }
    
    public: void onReset()
    {

      std::vector<std::array<double,2>> taken;
      std::vector<physics::ModelPtr> models = this->parent->Models();
      for(auto mod : models){
        std::string temp = "debris";
        if (mod->GetName().compare(0, temp.length(), temp) == 0) {
          double r;
          double angle;
          bool f = true;
          while(f){
            f = false;
            r = sqrt((((double)rand() / RAND_MAX)*pow(0.835,2)))+0.165; //radius position between .165 and 1m, so the area inside of the main circle and outside of the central tower
            angle = (((double)rand() / RAND_MAX)*2*M_PI); //angular position between 0 and 2pi
            for(std::array<double,2> pos : taken){
              if(pow(r*cos(angle)-pos[0],2)+pow(r*sin(angle)-pos[1],2)<pow(0.04,2)){//if another object's center is within 4 cm then find a new spot. Should be just enough margin for all the debris
                f = true;
              }
            }
          }
          std::array<double,2> pos = {r*cos(angle),r*sin(angle)};
          taken.push_back(pos);
          double orient = (((double)rand() / RAND_MAX)*2*M_PI);
          mod->SetWorldPose(ignition::math::Pose3d(r*cos(angle), r*sin(angle), 0,0,0,orient));
        }
      }
    }
    public: void onUpdate()
    {
      if(this->parent->SimTime().Double() >= 180 && !scoreStarted){
        gazebo::msgs::Int msg;
        msg.set_data(1);
        this->scoreStarted = true;
        this->parent->SetPaused(true);
        this->pub->Publish(msg,true);
      }
    }
    private: physics::WorldPtr parent;
    private: event::ConnectionPtr updateConnection;
    private: event::ConnectionPtr resetConnection;
    private: transport::NodePtr node;
    private: transport::PublisherPtr pub;
    private: transport::SubscriberPtr sub;
  };
  // Register this plugin with the simulator
  GZ_REGISTER_WORLD_PLUGIN(ScoreEngine)
}
