/*------------------------------------------------------------------------------
Filename:     vision.cpp
Project:      IEEE SoutheastCon Hardware Competition 2019
School:       Auburn University
Organization: Student Projects and Research Committee (SPARC)
Description:  Takes pictures on the Raspberry Pi Camera V2 and processes them
with OpenCV2 via color recognition.

Color Indices = Red(0), Blue(1), Yellow(2), Green(3)
Object Indices = Debris(0), Corner(1), CenterFace(2), Unknown(3)
------------------------------------------------------------------------------*/
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
// #include "vision.cpp"
#include <opencv_node/vision_msg.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "vision_talker");  // initialize ROS
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<opencv_node::vision_msg>("vision_info", 1000);  // start publishing chatter
  ros::Rate loop_rate(10);
  // IEEE_VISION::VisionHandle vis; // initialize vision 

  while (ros::ok())
  {
//    std::stringstream ss;
    // vis.takePicture();
    // vis.findObjects();
    // angle = vis.angle2LargestDebris();
    // ss << "The angle is " << angle;
    uint32_t x_position = 1000;
    uint32_t y_position = 2000;
    uint32_t width = 300;
    uint32_t height = 400;
    float_t distance = 0.5;
    uint8_t color_index = 1;
    uint8_t object_type = 0;

    opencv_node::vision_msg msg;
    msg.x_position = x_position;
    msg.y_position = y_position;
    msg.width = width;
    msg.height = height;
    msg.distance = distance;
    msg.color_index = color_index;
    msg.object_type = object_type;

    ROS_INFO("%s", "Sending message");

    pub.publish(msg);  // Sends messages

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
