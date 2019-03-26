#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher sender("arduinoPub", &str_msg);

void receiveCallback(const std_msgs::String& message) {
  str_msg.data = message.data;
  sender.publish(&str_msg);
}

ros::Subscriber<std_msgs::String> receiver("arduinoTopic", &receiveCallback);

void setup() {
  nh.initNode();
  nh.advertise(sender);
  nh.subscribe(receiver);
}

void loop() {
  nh.spinOnce();
  delay(20);
}
