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
	testMovement();  
        //testPointToObject();    
         
        return 0;
}

void my_handler(int s){
        arduino.stopMotors(); 
        arduino.stopMotors();
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
        usleep(1000*1000*1);
        arduino.stopMotors();
        arduino.stopMotors();
        arduino.stopMotors();
        usleep(1000*1000*1);
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
        //long startTime,temp;
        while (0 == 0)
        {       
                vis.takePicture();
                //vis.findObjects();
                vis.findObjectsOfColor(1);
                angle = vis.angle2LargestDebris(1);
                cout << "Angle to Debris: " << angle << endl;
                if(angle < -5 && angle > -120)
                {
                        cout <<"Turning Left" << endl;
                        arduino.turnLeft(25);
                        usleep(1000*100);
                        arduino.stopMotors();
                        arduino.stopMotors();
                }
                else if(5 < angle && angle < 120)
                {
                        cout <<"Turning Right" << endl;
                        arduino.turnRight(25);
                        usleep(1000*100);
                        arduino.stopMotors();
                        arduino.stopMotors();
                }
                else {
                        cout <<"Stopped Turning" << endl;
                        arduino.stopMotors();
                        arduino.stopMotors();
                }                        
		usleep(1000*1000);
        }
}
