#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "opencv_node/vision_msg.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "opencv_node/object.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

//#include "sensor_msgs/Imu.h"
#include "Arduino-Serial/ArduinoSerial.h"

using namespace std;

serialPort arduino("/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0");

ros::Publisher initPose;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
//arduino.setupConnection();
int rightSpeed=0,leftSpeed=0;
void testMovement()
{
  arduino.updateLCD("Starting movement test..");
  usleep(1000*500);
  arduino.updateLCD("Forward..");
  arduino.goForward(25);
  usleep(1000*500);
  arduino.updateLCD("Stop");
  arduino.stopMotors(); 
  usleep(1000*500);
  arduino.updateLCD("Backward..");
  arduino.goBackward(25);
  usleep(1000*500);
  arduino.updateLCD("Stop");
  arduino.stopMotors(); 
  usleep(1000*500);
  arduino.updateLCD("Right..");     
  arduino.turnRight(25);
  usleep(1000*500);
  arduino.updateLCD("Stop");
  arduino.stopMotors();
  usleep(1000*500);
  arduino.updateLCD("Left..");
  arduino.turnLeft(25);
  usleep(1000*500);
  arduino.updateLCD("Stop");
  arduino.stopMotors();
  usleep(1000*500);
  arduino.updateLCD("Moving Gate Up..");
  arduino.moveGate(180);
  usleep(1000*500);
  arduino.updateLCD("Moving Gate Down..");
  arduino.moveGate(0);
  usleep(1000*500);
  arduino.updateLCD("Moving Flag Up..");
  arduino.moveFlag(0);
  usleep(1000*500);
  arduino.updateLCD("Moving Flag Down..");
  arduino.moveFlag(180);
  usleep(1000*500);
  arduino.updateLCD("Movement Test   Compeleted!");
}
void rin(const std_msgs::Float32ConstPtr &msg){
	rightSpeed = (int)msg->data;
}

void lin(const std_msgs::Float32ConstPtr &msg){
	leftSpeed = (int)msg->data;
}

void visionCallback(const opencv_node::vision_msg::ConstPtr &msg)
{
  ROS_INFO("Main>>>Number of Objects: %d", msg->objects.size());
  for (int i = 0; i < msg->objects.size(); ++i)
  {
    const opencv_node::object &prop = msg->objects[i];
    ROS_INFO_STREAM("Position: " << prop.x_position << "," << prop.y_position);
  }  
}

void moveFwdOneMeter(){
	//MOVE BASE CODE//

        MoveBaseClient ac("move_base", true); //Tell the client we want to spin a thread by default
         while(!ac.waitForServer(ros::Duration(5.0))){
                ROS_INFO("Waiting for the move_base action server to come up");
        }

        move_base_msgs::MoveBaseGoal moveFwd;
	
	moveFwd.target_pose.header.frame_id = "base_footprint";
        moveFwd.target_pose.header.stamp = ros::Time::now();

        moveFwd.target_pose.pose.orientation.x = 1.0; //move 1 meter forward
        moveFwd.target_pose.pose.orientation.w = 1.0;

        ROS_INFO("Sending goal");
	ac.sendGoal(moveFwd);

	ac.waitForResult();

	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		ROS_INFO("WOOP WOOP YOU DID IT");
	else
		ROS_INFO("You screwed up boi");
        /////////////////

}

//Note: frame is typicall "map" or "base_footprint"
bool moveToGoal(double xGoal, double yGoal, string frame){

   //define a client for to send goal requests to the move_base server through a SimpleActionClient
   actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base", true);

   //wait for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
   }

   move_base_msgs::MoveBaseGoal goal;

   //set up the frame parameters
   goal.target_pose.header.frame_id = "map";
   goal.target_pose.header.stamp = ros::Time::now();

   /* moving towards the goal*/

   goal.target_pose.pose.position.x =  xGoal;
   goal.target_pose.pose.position.y =  yGoal;
   goal.target_pose.pose.position.z =  0.0;
   goal.target_pose.pose.orientation.x = 0.0;
   goal.target_pose.pose.orientation.y = 0.0;
   goal.target_pose.pose.orientation.z = 0.0;
   goal.target_pose.pose.orientation.w = 1.0;

   ROS_INFO("Sending goal location ...");
   ac.sendGoal(goal);

   ac.waitForResult();

   if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
      ROS_INFO("You have reached the destination");
      return true;
   }
   else{
      ROS_INFO("The robot failed to reach the destination");
      return false;
   }

}

// void arduinoCallback(const std_msgs::String& msg) {
// 	ROS_INFO_STREAM(msg << '\n');
// }

/*void imuCallback(const sensor_msgs::Imu::ConstPtr &msg)
{
  float gyro_x = msg->angular_velocity.x;
  float gyro_y = msg->angular_velocity.y;
  float gyro_z = msg->angular_velocity.z;
  float orientation_x = msg->orientation.x;
  float orientation_y = msg->orientation.y;
  float orientation_z = msg->orientation.z;
  float orientation_w = msg->orientation.w;
  //ROS_INFO("Main>>>Angular Velocity: x(%f),y(%f),z(%f)", gyro_x,gyro_y,gyro_z);
  ROS_INFO("Main>>>Orientation: x(%f),y(%f),z(%f)", orientation_x, orientation_y, orientation_z);
}*/


int main(int argc, char **argv)
{

  ros::init(argc, argv, "main");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("vision_info", 1000, visionCallback);

  ros::Subscriber lsub = n.subscribe<std_msgs::Float32>("rmotor_cmd", 1,lin);
  ros::Subscriber rsub = n.subscribe<std_msgs::Float32>("lmotor_cmd", 1,rin);

  initPose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose",1,true);

  cout << "\033[1;34m-------------------------------------------------------------------\033[0m" << endl;
  cout << "\033[1;34m   .:: ::    .:::::::          .:         .:::::::          .::    \033[0m" << endl;
  cout << "\033[1;34m .::    .::  .::    .::       .: ::       .::    .::     .::   .:: \033[0m" << endl;
  cout << "\033[1;34m  .::        .::    .::      .:  .::      .::    .::    .::        \033[0m" << endl;
  cout << "\033[1;34m    .::      .:::::::       .::   .::     .: .::        .::        \033[0m" << endl;
  cout << "\033[1;34m       .::   .::           .:::::: .::    .::  .::      .::        \033[0m" << endl;
  cout << "\033[1;34m .::    .::  .::          .::       .::   .::    .::     .::   .:: \033[0m" << endl;
  cout << "\033[1;34m   .:: ::    .::         .::         .::  .::      .::     .::::   \033[0m" << endl;
  cout << "\033[1;34m-------------------------------------------------------------------\033[0m" << endl;
  cout << "\033[1;34m|        Student Projects and Research Committee IEEE 2019        |\033[0m" << endl;
  cout << "\033[1;34m ------------------------------------------------------------------\033[0m" << endl;
  sleep(1);
  //ros::Subscriber sub2 = n.subscribe("sensor_msgs/Imu", 1000, imuCallback);

	// ros::Publisher arduinoSend = n.advertise<std_msgs::String>("arduinoTopic", 500);
	// ros::Subscriber arduinoReceive = n.subscribe("arduinoPub", 500, arduinoCallback);
	ros::Rate loop_rate(40);	//1 Hz


	geometry_msgs::PoseWithCovarianceStamped ip;
	ip.header.frame_id = "map";
	ros::Time current_time = ros::Time::now();
	ip.header.stamp = current_time;
	ip.pose.pose.position.x = 0.1143;
	ip.pose.pose.position.y = 0.1143;
	ip.pose.pose.orientation.z = 0;
	ip.pose.covariance[0] = 1e-3;
	ip.pose.covariance[7] = 1e-3;
	ip.pose.covariance[35] = 1e-3;
	initPose.publish(ip);
	int count = 0;
	while(ros::ok()) {
		//TEST #0 - Move. Period.
	        //testMovement();

       		//TEST #1 - Move forward a meter
       		//moveFwdOneMeter;

		//TEST #2 - Go in a circle
		//bool goalReached = false;
		//double x1 = 2.25;
		//double y1 = 2.25;
		//double x2 = 2.25;
		//double y2 = 2.25;
		//double x3 = 2.25;
		//double y3 = 2.25;
		//double x4 = 2.25;
		//double x5 = 2.25;
		//if(goalReached == moveToGoal(x1,y1)){
		//	goalReached = false;
		//	if(goalReached == moveToGoal(x2,y2)){
		//		goalReached = false;
		//		if(goalReached == moveToGoal(x3,y3)){
		//			goalReached = false;
		//			if(goalReached == moveToGoal(x4,y4)){
		//				goalReached = false;
		//			}
		//		}
		//	}
	//	}
					
		
		std_msgs::String msg;
		msg.data = std::string("Hello ");
		msg.data += std::to_string(count);
		ROS_INFO_STREAM(msg.data);
		switch(arduino.getMode()){
			case 0: arduino.updateLCD("Red");\
				break;
			case 1: arduino.updateLCD("Green");
				break;
			case 2: arduino.updateLCD("Blue");
				break;
			case 3: arduino.updateLCD("Yellow");
				break;
			default: break;
		}
		ros::spinOnce();
		arduino.drive(rightSpeed,leftSpeed);
		loop_rate.sleep();
		++count;
	}

  return 0;
}

