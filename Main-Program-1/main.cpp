/*------------------------------------------------------------------------------
Filename:     main.cpp
Project:      IEEE SoutheastCon Hardware Competition 2019
School:       Auburn University
Organization: Student Projects and Research Committee (SPARC)
Description:  Main development program for competition.
------------------------------------------------------------------------------*/
#include "Arduino-Serial/ArduinoSerial.h"
#include "Vision-Processing/vision.cpp"
#include <thread>
#include <unistd.h>
#include <iostream>
#include <chrono>

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

// Constants
#define getms() std::chrono::duration_cast<std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count()
template <typename T> int sign(T val){return (T(0)<val)-(val<T(0));}
const long turnTimePerDegree = 1;

void startupRoutine();
void testMovement();
void testPointToObject();

serialPort arduino("/dev/ttyUSB0");  

struct threadableVision{
        double angle=0;
	int imgs=0;
        bool updated = false;
        IEEE_VISION::VisionHandle vis;
        void operator()(){
		while(1) {
                        vis.takePicture();
                        //vis.findObjects();
                        vis.findObjectsOfColor(1);
                	this->angle = vis.angle2LargestDebris(1);
			imgs++;
                	updated = true;
		}
        }
};


int main()
{
        startupRoutine();    
	//testMovement();  
        testPointToObject();    
         
        return 0;
}

void my_handler(int s){
        arduino.stopMotors(); 
        cout << "Forcing Stop..." << endl;
        exit(1); 

}

void startupRoutine()
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
        cout << "Connected to Arduino..." << endl;
        arduino.stopMotors(); 
        cout << "Starting robot..." << endl;
        
        // Setup handler for a forced stop of program
        struct sigaction sigIntHandler;
        sigIntHandler.sa_handler = my_handler;
        sigemptyset(&sigIntHandler.sa_mask);
        sigIntHandler.sa_flags = 0;
        sigaction(SIGINT, &sigIntHandler, NULL);
}

void testMovement()
{
        
        arduino.turnRight(25);
        usleep(1000*500);
        arduino.stopMotors();
}

void testPointToObjectSmart()
{
        cout << "Connecting to Arduino..." << endl;
        serialPort arduino("/dev/ttyUSB0");
        threadableVision vis;
        thread visThread = thread(ref(vis));
        double angle = 0;
        long startTime,temp;
        while (0 == 0)
        {       
                if(vis.updated)
                {
                        angle = vis.angle;
                        vis.updated = false;
//                        cout << "Updated State" << endl;
                        startTime = getms();
                        if(5 < angle && angle < 120)
                        {
				cout <<"issued turn" << endl;
                                arduino.turnLeft(25);
                        }
                        else if(angle < -5 && angle > -120)
                        {
				cout <<"issued turn" << endl;
                                arduino.turnRight(25);
                        }
                }
		temp = getms();
                angle = (sign(angle)*(abs(angle)-((temp-startTime)/turnTimePerDegree)));//update angle based on time since we started turning
                startTime = temp;
		cout << "Angle to Debris: " << angle << ":hoo:" << vis.imgs << endl;
                if(abs(angle) < 5) 
                {
                        arduino.stopMotors();
                }
		usleep(100);

        }
}

void testPointToObject()
{
        //threadableVision vis;
        //thread visThread = thread(ref(vis));
        IEEE_VISION::VisionHandle vis;
        double angle = 0;
        double distance = 0;
        //long startTime,temp;
        bool isInactive = false;
        long beginInactive = 0;
        while (0 == 0)
        {       
                vis.takePicture();
                vis.findObjects();
                //vis.findObjectsOfColor(1);
                angle = vis.angle2LargestDebris();
                //cout << "Angle to Debris: " << angle << endl;
                //cout << "Largest object: " << vis.findLargestObject()  << endl;
                if (vis.findLargestObject() >= 0){
                        distance = vis.objectProperties[vis.findLargestObject()].distance;
                }
                else {
                        distance = 0;
                }
                //cout << "Distance to Debris: " << distance << endl;
                if (angle > (distance < .6 ? 55 : 10) && angle < 120)
                {
                        //cout << "Turning Right\n";
                        arduino.turnRight(25);
                        usleep(120*1000);
                        arduino.stopMotors();
                        isInactive = false;
                }
                else if (angle < (distance < .6 ? -55 : -10) && angle > -120)
                {
                        //cout << "Turning Left\n";
                        arduino.turnLeft(25);
                        usleep(120*1000);
                        arduino.stopMotors();
                        isInactive = false;
                }
                else
                {
                        //cout << "Stopping Motors\n";
                        arduino.stopMotors();
                        if(!isInactive) {
                                isInactive = true;
                                beginInactive = getms();
                                cout << "Time reset\n";
                        }
                        if (distance > 0.25 && distance < 2){
                                cout << "Going Forward\n";
                                arduino.goForward(25);
                                //usleep(120*1000);
                                //arduino.stopMotors();
                        }
                        else {
                                if(getms() - beginInactive > 4000) {
                                        cout << getms() - beginInactive << '\n';
                                        arduino.turnRight(25);
                                        usleep(1000*200);
                                        arduino.stopMotors();
                                }
                        }          
                }
                    
        }
}
