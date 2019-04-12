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
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>

#include "Arduino-Serial/ArduinoSerial.h"
//Color Indices = red(0), yellow(1), blue(2), green(3)
using namespace std;
int colorSelect = 0;
int colorChoose = 0;
int matchStatus  = 0;
int gatepos = 0;
int flagpos = 0;
int rightSpeed = 0;
int leftSpeed = 0;
serialPort arduino("/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0");

void rin(const std_msgs::Float32ConstPtr &msg){
	rightSpeed = (int)msg->data;
}

void lin(const std_msgs::Float32ConstPtr &msg){
	leftSpeed = (int)msg->data;
}
void colorSelectFunc(const std_msgs::Float32ConstPtr &msg){
	colorSelect = (int)msg->data;
}

void flagFunc(const std_msgs::Float32ConstPtr &msg){
	flagpos = (int)msg->data;
    arduino.moveFlag(flagpos);
}
void gateFunc(const std_msgs::Float32ConstPtr &msg){
	gatepos = (int)msg->data;
    arduino.moveFlag(gatepos);

}


int main(int argc, char **argv){
    ros::init(argc, argv, "arduino_talker");
    ros::NodeHandle n;
    ros::Rate loop_rate(40);	//1 Hz
    ros::Subscriber lsub = n.subscribe<std_msgs::Float32>("rmotor_cmd", 1,lin);
    ros::Subscriber rsub = n.subscribe<std_msgs::Float32>("lmotor_cmd", 1,rin);
    ros::Subscriber flag = n.subscribe<std_msgs::Float32>("flag_cmd", 1,flagFunc);
    ros::Subscriber gate = n.subscribe<std_msgs::Float32>("gate_cmd", 1,gateFunc);

    ros::Publisher colorSelectPub = n.advertise<std_msgs::Int32>("colorSelectFunc",1);
    ros::Publisher startMatchPub = n.advertise<std_msgs::Int32>("startMatchFunc",1);
    ros::Time current_time = ros::Time::now();

    while(ros::ok()) {

        if(matchStatus){
            startMatchPub.publish(matchStatus);
            colorChoose++;
        }

        std_msgs::String msg;
	msg.data = std::string("Hello ");
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
	if(colorChoose == 1 && arduino.getButtonState()){
		matchStatus = 1;
	}
        ros::spinOnce();
		//cout << "ButtonState " << arduino.getButtonState() << endl;
		arduino.drive(rightSpeed,leftSpeed);
		arduino.updateArduino();
		loop_rate.sleep();	
    }
    return 0;
}