#include "ros/ros.h"
#include "std_msgs/String.h"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "opencv_node/vision_msg.h"
#include "opencv_node/object.h"
//#include "sensor_msgs/Imu.h"

using namespace std;

void visionCallback(const opencv_node::vision_msg::ConstPtr &msg)
{
  ROS_INFO("Main>>>Number of Objects: %d", msg->objects.size);
  for (int i = 0; i < msg->objects.size; ++i)
  {
    const opencv_node::vision_msg &prop = msg->objects[i];
    ROS_INFO_STREAM("Position: " << prop.x_position << "," << prop.y_position);
  }  
}

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

  ros::init(argc, argv, "main");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("vision_info", 1000, visionCallback);
  //ros::Subscriber sub2 = n.subscribe("sensor_msgs/Imu", 1000, imuCallback);

  ros::spin();

  return 0;
}
