#include <ros.h>
#include <std_msgs/String.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher sender("arduinoPub", &str_msg);

void receiveCallback(const std_msgs::String& message) {
  str_msg.data = message.data;
  sender.publish(&str_msg);
  lcd.clear();
  lcd.print(str_msg.data);
  
}
  
ros::Subscriber<std_msgs::String> receiver("arduinoTopic", &receiveCallback);

void setup() {
  lcd.begin();
  nh.initNode();
  nh.advertise(sender);
  nh.subscribe(receiver);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  nh.spinOnce();
  delay(20);
}
