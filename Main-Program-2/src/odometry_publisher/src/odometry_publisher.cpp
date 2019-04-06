/*********************************************************************
*
* Software License Agreement (BSD License)
*
*  Copyright (c) 2009, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of Willow Garage, Inc. nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
* Author: Eitan Marder-Eppstein
*********************************************************************/
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "deadreckon.h"
#include <string>
#include <termios.h>

#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#define ticksPerRev 2244.923077 //ticks per rev is a double to the possibility of non whole number gear ratios due to how the encdoers are coupled
#define pi 3.141592
#define tau 2*pi

int getSer(std::string name){
  int fileHandle = open(name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
  if(fileHandle == -1) {
    throw std::runtime_error(std::string("Error opening port: ") + strerror(errno));
  }
  if(!isatty(fileHandle)) {
    close(fileHandle);
    throw std::runtime_error("Port is not a serial device.");
  }
  termios config;
  cfmakeraw(&config);     //Sets various parameters for non-canonical mode; disables parity

  cfsetospeed (&config, B9600);    //Baud rate
  cfsetispeed (&config, B9600);

  config.c_cflag     &=  ~CSTOPB;    //One stop bit

  config.c_cflag     |=  CREAD | CLOCAL;
  config.c_cflag     &=  ~CRTSCTS;           // no flow control

  config.c_cc[VMIN]   =  0;
  config.c_cc[VTIME]  =  0;

  if(tcsetattr(fileHandle, TCSANOW, &config) != 0) {
    close(fileHandle);
    throw std::runtime_error("Setting attributes failed.");
  }
  usleep(1000*1000*1); // wait 1 sec for arduino to reset
  tcflush(fileHandle, TCIFLUSH);    //clear input buffer
  usleep(1000*1000*1); // wait 1 sec for arduino to reset  
  return fileHandle;
}
int available(int fd) {
  int bytes;
  ioctl(fd, FIONREAD, &bytes);
  return(bytes);
}
int get(int fd) {
  while(available(fd)<4);
  int ret;
  lseek(fd,-4,SEEK_END);
  read(fd,(char*)&ret,4 );    //The const cast is less than ideal
  return ret;
}
int main(int argc, char** argv){
  int s1 = getSer("/dev/ttyACM0");
  int s2 = getSer("/dev/ttyS0");
  while(1){
	std::cout << get(s1) << " " << get(s2) << std::endl;
  }}
/*
  ros::init(argc, argv, "odometry_publisher");

  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("fuck/odom", 50);
  tf::TransformBroadcaster odom_broadcaster;
  odomIntegral odomI(0.1730756,0.0379095);//base and radius in meters. TODO get accurate values here


  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
  long lastValueR = coders[0].value,lastValueL = coders[1].value,curValueR,curValueL;
  ros::Rate r(100);
  while(n.ok()){
    current_time = ros::Time::now();

    //compute odometry in a typical way given the velocities of the robot
    double dt = (current_time - last_time).toSec();
    curValueR = coders[0].value;
    curValueL = coders[1].value;
//    std::cout << curValueR << " " << curValueL << std::endl;
    double diffR = curValueR-lastValueR;
    double diffL = curValueL-lastValueL;
    double wR = (tau*diffR)/(ticksPerRev*dt); //revolution speed of the right wheel in radians per second. This is computed as an instantneous measurement since the last time we updated
    double wL = (tau*diffL)/(ticksPerRev*dt);
    odomI.proc(wL,wR,dt);  //this performs all the integration
    lastValueR = curValueR;
    lastValueL = curValueL;
    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(odomI.theta);

    //first, we'll publish the transform over tf
    /*geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "fuck/odom";
    odom_trans.child_frame_id = "base_footprint";

    odom_trans.transform.translation.x = odomI.x;
    odom_trans.transform.translation.y = odomI.y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);
	*/
    //next, we'll publish the odometry message over ROS*/
    /*nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_footprint";

    //set the position
    odom.pose.pose.position.x = odomI.x;
    odom.pose.pose.position.y = odomI.y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;
    odom.pose.covariance[0] = 1e-3;
    odom.pose.covariance[7] = 1e-3;
    odom.pose.covariance[35] = 1e-3; 

    //set the velocity
    odom.twist.twist.linear.x = odomI.xdot;
    odom.twist.twist.linear.y = odomI.ydot;
    odom.twist.twist.angular.z = odomI.thetadot;
    odom.twist.covariance[0] = 1e-3;
    odom.twist.covariance[7] = 1e-3;
    odom.twist.covariance[35] = 1e-3;

    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;
//    std::cout << "x:" << odomI.x << " y:" << odomI.y << " t:" << odomI.theta << std::endl;
    r.sleep();
  }
}*/
