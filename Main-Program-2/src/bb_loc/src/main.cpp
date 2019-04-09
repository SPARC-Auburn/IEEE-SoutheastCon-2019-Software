#include "ros/ros.h"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <sensor_msgs/LaserScan.h>

using namespace std;
void laserCallback(const sensor_msgs::LaserScan &msg){
	cout << "Angle min:" << msg->angle_min << endl;
  cout << "Angle max:" << msg->angle_max << endl;
  cout << "Angle inc:" << msg->angle_increment << endl;
  cout << "Time inc: " << msg->time_increment << endl;
  cout << "Scan Time:" << msg->scan_time << endl;
  cout << "Range min:" << msg->range_min << endl;
  cout << "Range max:" << msg->range_max << endl;
}
int main(int argc, char **argv)
{

  ros::init(argc, argv, "main");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("scan", 50, laserCallback);

  ros::Publisher pose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("amcl_pose", 1);

 // initPose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("initialpose",1,true);
  sleep(1);
  //ros::Subscriber sub2 = n.subscribe("sensor_msgs/Imu", 1000, imuCallback);

	// ros::Publisher arduinoSend = n.advertise<std_msgs::String>("arduinoTopic", 500);
	// ros::Subscriber arduinoReceive = n.subscribe("arduinoPub", 500, arduinoCallback);
	ros::Rate loop_rate(60);	//1 Hz


	//geometry_msgs::PoseWithCovarianceStamped ip;
	//ip.header.frame_id = "map";
	ros::Time current_time = ros::Time::now();
	/*ip.header.stamp = current_time;
	ip.pose.pose.position.x = 0.1143;
	ip.pose.pose.position.y = 0.1143;
	ip.pose.pose.orientation.z = 0;
	ip.pose.covariance[0] = 1e-3;
	ip.pose.covariance[7] = 1e-3;
	ip.pose.covariance[35] = 1e-3;
	initPose.publish(ip);
	*/
	int count = 0;
	while(ros::ok()) {
		ros::spinOnce();
		loop_rate.sleep();
	}

  return 0;
}

