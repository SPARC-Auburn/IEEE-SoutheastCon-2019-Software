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
#include <boost/geometry.hpp>
#include <vector>
#include <math.h> 
using namespace cv;
using namespace std;
#define DEBUG false

namespace bg = boost::geometry;
    typedef bg::model::point<double, 2, bg::cs::cartesian> point_t;

namespace trans = bg::strategy::transform;
    typedef trans::rotate_transformer<bg::radian, double, 2, 2> rotator;
    typedef trans::translate_transformer<double,2,2> translater;


bg::model::multi_point<point_t> last_cloud;
bg::model::ring<point_t> hull;
ros::Time current_time;
ros::Subscriber sub;
ros::Publisher pose;
void laserCallback(const sensor_msgs::LaserScanConstPtr &msg){
  current_time = ros::Time::now();
  if(DEBUG){
    cout << "Angle min:" << msg->angle_min << endl;
    cout << "Angle max:" << msg->angle_max << endl;
    cout << "Angle inc:" << msg->angle_increment << endl;
    cout << "Time inc: " << msg->time_increment << endl;
    cout << "Scan Time:" << msg->scan_time << endl;
    cout << "Range min:" << msg->range_min << endl;
    cout << "Range max:" << msg->range_max << endl;
  }
  clear(last_cloud);
  float angle = msg->angle_min;
  for(int i = 0; i < scan_time/time_increment; i+=1, angle += msg->angle_increment){
    bg::append(cloud, point_t(cos(angle)*msg->ranges[i], sin(angle)*msg->ranges[i]));
  }
  clear(hull);
  bg::convex_hull(cloud, hull);

  point_t centroid;
  bg::centroid(hull,centroid);
  bg::model::ring<point_t> transhull;
  translater translate(-centroid.get<0>(),-centroid.get<1>()); //center so rotation does no movement of the center of the field.
  boost::geometry::transform(hull, transhull, translate);
  double x = centroid.get<0>();
  double y = centroid.get<1>();
  bg::model::ring<point_t> rothull;
  double area = INFINITY,temp,angle;
  for(int i = 0; i < transhull.size()-1; i++){
      for(int j = i++; j < transhull.size(); j++){
          rotator rotate(atan((transhull[i].get<1>()-transhull[j].get<1>())/(transhull[i].get<0>()-transhull[j].get<0>())));
          boost::geometry::transform(transhull, rothull, rotate);
          bg::model::box<point_t> box;
          bg::envelope(rothull,box);
          temp = bg::area(box);
          if(temp < area){
              angle = atan((transhull[i].get<1>()-transhull[j].get<1>())/(transhull[i].get<0>()-transhull[j].get<0>()));
              area = temp;
          }
          rothull.clear();
      }
  }
  geometry_msgs::PoseWithCovarianceStamped ip;
	ip.header.frame_id = "map";
	ip.header.stamp = current_time;
	ip.pose.pose.position.x = x;
	ip.pose.pose.position.y = y;
	ip.pose.pose.orientation.z = angle;
	ip.pose.covariance[0] = 1e-3;
	ip.pose.covariance[7] = 1e-3;
	ip.pose.covariance[35] = 1e-3;
	pose.publish(ip);
  //just drawing the output from here on down
  /*rotator rotate(angle);
  boost::geometry::transform(transhull, rothull, rotate);

  Mat testimage = Mat::zeros(Size(1000,1000),CV_8UC3);
  for(int i = 0; i < rothull.size()-1; i++){
      int x1 = (int)(200*rothull[i].get<0>()+500), y1 = (int)(200*rothull[i].get<1>()+500);
      int x2 = (int)(200*rothull[i+1].get<0>()+500), y2 = (int)(200*rothull[i+1].get<1>()+500);
      //testimage.at<uchar>(y1,x1) = (uchar)255;
      line(testimage,Point(x1,y1),Point(x2,y2),Scalar(0,0,255));
  }
  {
      int x1 = (int)(200*rothull[0].get<0>()+500), y1 = (int)(200*rothull[0].get<1>()+500);
      int x2 = (int)(200*rothull[rothull.size()-1].get<0>()+500), y2 = (int)(200*rothull[rothull.size()-1].get<1>()+500);
      line(testimage,Point(x1,y1),Point(x2,y2),Scalar(0,0,255));
  }
  cout << angle*180*3.14 << " degrees" << endl; 
  cout << centroid.get<0>() << "," << centroid.get<1>() << endl;
  rectangle(testimage,Rect(-1.22*200+500,-1.22*200+500,2.44*200,2.44*200),Scalar(255,255,255),1);
  {
      RotatedRect rRect = RotatedRect(Point2f(500,500), Size2f(.23*200,.23*200), 45);
      Point2f vertices[4];
      rRect.points(vertices);
      for (int i = 0; i < 4; i++)
          line(testimage, vertices[i], vertices[(i+1)%4], Scalar(255,255,255));
  }
  {
      RotatedRect rRect = RotatedRect(Point2f(500-centroid.get<0>()*200,500+centroid.get<1>()*200), Size2f(.2286*200,.2286*200), angle*180*3.14);
      Point2f vertices[4];
      rRect.points(vertices);
      for (int i = 0; i < 4; i++)
          line(testimage, vertices[i], vertices[(i+1)%4], Scalar(0,255,255),2);
  }
  imwrite("final.png",testimage);*/
  
  
}
int main(int argc, char **argv)
{

  ros::init(argc, argv, "main");
  ros::NodeHandle n;
  sub = n.subscribe<sensor_msgs::LaserScan>("scan", 50, laserCallback);
  pose = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("amcl_pose_test", 1);

	//geometry_msgs::PoseWithCovarianceStamped ip;
	//ip.header.frame_id = "map";
	/*ip.header.stamp = current_time;
	ip.pose.pose.position.x = 0.1143;
	ip.pose.pose.position.y = 0.1143;
	ip.pose.pose.orientation.z = 0;
	ip.pose.covariance[0] = 1e-3;
	ip.pose.covariance[7] = 1e-3;
	ip.pose.covariance[35] = 1e-3;
	initPose.publish(ip);
	*/

  ros::spin();

  return 0;
}

