#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
nclude <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>

include "../main_node/src/Arduino-Serial/ArduinoSerial.h"
//Color Indices = red(0), yellow(1), blue(2), green(3)
using namespace std;
int colorSelected = 0;
int colorChoose = 0;
int matchStatus  = 0;
int gatePos = 0;
int flagPos = 0;
serialPort arduino("/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0");

void rin(const std_msgs::Float32ConstPtr &msg){
	rightSpeed = (int)msg->data;
}

void lin(const std_msgs::Float32ConstPtr &msg){
	leftSpeed = (int)msg->data;

void colorSelectFunc(const std_msgs::Float32ConstPtr &msg){
	colorSelect = (int)msg->data;
}
void startMatchFunc(const std_msgs::Float32ConstPtr &msg){
	matchStatus = (int)msg->data;
}
void flagFunc(const std_msgs::Float32ConstPtr &msg){
	flagPos = (int)msg->data;
    arduino.moveFlag(flagPos);
}
void gateFunc(const std_msgs::Float32ConstPtr &msg){
	gatePos = (int)msg->data;
    arduino.moveFlag(gatePos);

}


int main(int argc, char **argv){

    ros::NodeHandle n;
    ros::Rate loop_rate(40);	//1 Hz
    ros::Subscriber lsub = n.subscribe<std_msgs::Float32>("rmotor_cmd", 1,lin);
    ros::Subscriber rsub = n.subscribe<std_msgs::Float32>("lmotor_cmd", 1,rin);
    ros::Subscriber flag = n.subscribe<std_msgs::Float32>("flag_cmd", 1,flagFunc);
    ros::Subscriber gate = n.subscribe<std_msgs::Float32>("gate_cmd", 1,gateFunc);

    ros::Publisher colorSelectPub = n.advertise<std_msgs::Int32>("colorSelectFunc",1);
    ros::Publisher startMatchPub = n.advertise<std_msgs::Int32>("startMatchFunc",1);

    ros::Rate loop_rate(40);	//1 Hz
    ros::Time current_time = ros::Time::now();

    while(ros::ok()) {

        if(arduino.getButtonState && colorChoose){
            startMatchPub.publish(matchStatus);
        }

        std_msgs::String msg;
		msg.data = std::string("Hello ");
		msg.data += std::to_string(count);
        if(colorChoose == 0){
            switch(arduino.getMode()){
                case 0: arduino.updateLCD("Red");
                if(arduino.getButtonState() && colorChoose < 1){
                    colorSelect = arduino.getMode();colorChoose++;}
                break;
                case 1: arduino.updateLCD("Yellow");
                if(arduino.getButtonState() && colorChoose < 1){
                    colorSelect = arduino.getMode();colorChoose++;}
                break;
                case 2: arduino.updateLCD("Blue");
                if(arduino.getButtonState() && colorChoose < 1){
                    colorSelect = arduino.getMode();colorChoose++;}
                break;
                case 3: arduino.updateLCD("Green");
                if(arduino.getButtonState() && colorChoose < 1){
                    colorSelect = arduino.getMode();colorChoose++;}
                break;
                default: break;
            }
        }
        if(colorChoose == 1){
            colorSelectPub.publish(colorSelect);   
        }
        ros::spinOnce();
		arduino.drive(rightSpeed,leftSpeed);
		arduino.updateArduino();
		loop_rate.sleep();	
    }
    return 0;
}