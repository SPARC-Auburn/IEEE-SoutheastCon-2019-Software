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
#include <wiringPi.h>
#include "deadreckon.h"
#include <thread>
#define ticksPerRev 1024.0 //ticks per rev is a double to the possibility of non whole number gear ratios due to how the encdoers are coupled
#define pi 3.141592
#define tau 2*pi
struct Encoder{
  static int outcome[] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};
  int pin_a,pin_b;
  volatile long value;
  volatile char last,cur;
  Encoder(int a, int b){
    pin_a = a;
    pin_b = b;
    pinMode (a, INPUT);
    pinMode (b, INPUT);

    lastEncoded = 0;
    value = 0;
  }
  update(){
    cur = (digitalRead(pin_a) << 1) | digitalRead(pin_b);
    value += outcome[(last << 2) | cur];
    last = cur;
  }
}
void update(Encoder &coders[2]){
  while(1){
    coders[0].update();
    coders[1].update();
  }
}
int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_publisher");
  wiringPiSetup();
  Encoder coders[2] = {Encoder(21,20),Encoder(19,26)}
  std::thread IO (bar,coders);//put in a seperate thread to ensure its not delayed by the odometry integration

  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
  tf::TransformBroadcaster odom_broadcaster;
  odomIntegral odom(0.1778,0.038735);//base and radius in meters. TODO get accurate values here


  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
  long lastCountR = coders[0].value,lastCountL = coders[1].value,curValueR,curValueL;
  ros::Rate r(1.0);
  while(n.ok()){
    current_time = ros::Time::now();

    //compute odometry in a typical way given the velocities of the robot
    double dt = (current_time - last_time).toSec();
    curValueR = coders[0].value;
    curValueL = coders[1].value;
    double diffR = curValueR-lastValueR;
    double diffL = curValueL-lastValueL;
    double wR = (tau*diffR)/(ticksPerRev*dt) //revolution speed of the right wheel in radians per second. This is computed as an instantneous measurement since the last time we updated
    double wL = (tau*diffL)/(ticksPerRev*dt)
    odom.proc(wL,wR,dt);  //this performs all the integration

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(odom.theta);

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = odom.x;
    odom_trans.transform.translation.y = odom.y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    //send the transform
    odom_broadcaster.sendTransform(odom_trans);

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_link";

    //set the position
    odom.pose.pose.position.x = odom.x;
    odom.pose.pose.position.y = odom.y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.twist.twist.linear.x = odom.xdot;
    odom.twist.twist.linear.y = odom.ydot;
    odom.twist.twist.angular.z = odom.thetadot;

    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;
    r.sleep();
  }
}
