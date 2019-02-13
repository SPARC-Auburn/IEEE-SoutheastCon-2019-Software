#include "Arduino-Serial/ArduinoSerial.h"
#include "Arduino-Serial/ArduinoSerial.cpp"
#include "Vision-Processing/vision.cpp"
#include <boost/thread.hpp>
#include <unistd.h>
#include <iostream>
#include <chrono>
#define getms() std::chrono::duration_cast< milliseconds >(system_clock::now().time_since_epoch().count())

const long turnTimePerDegree = 2;
void startupRoutine();
struct threadableVision{
        double angle;
        bool updated = false;
        IEEE_VISION::VisionHandle vis;
        void operator()(){
                this->angle = vis.angle2LargestDebris(1); 
                updated = true;
        }
}
int main()
{
        startupRoutine();
        cout << "Connecting to Arduino..." << endl;
        serialPort arduino("/dev/ttyUSB0");
        threadableVision vis;
        boost::thread visThread = boost::thread(boost::ref(vis));
        double angle = 0;
        long startTime;
        while (0 == 0)
        {       
                if(vis.updated)
                {
                        angle = vis.angle;
                        vis.updated = false;
                        cout << "Updated State" << endl;
                        startTime = getms();
                        if(5 < angle && angle < 120)
                        {
                                arduino.turnRight(25);
                        }
                        else if(angle < -5 && angle > -120)
                        {
                                arduino.turnLeft(25);
                        }
                }
                angle = (sign(angle)*(abs(angle)-((getms()-starTime)/turnTimePerDegree)));//update angle based on time since we started turning
                cout << "Angle to Debris: " << angle << endl;
                if(abs(angle) < 5) 
                {
                        arduino.stopMotors();
                }

        }
        return 0;
}

void startupRoutine()
{
        cout << "\033[1;34m-------------------------------------------------------------------\033[0m     \n";
        cout << "\033[1;34m   .:: ::    .:::::::          .:         .:::::::          .::    \033[0m     \n";
        cout << "\033[1;34m .::    .::  .::    .::       .: ::       .::    .::     .::   .:: \033[0m     \n";
        cout << "\033[1;34m  .::        .::    .::      .:  .::      .::    .::    .::        \033[0m    \n";
        cout << "\033[1;34m    .::      .:::::::       .::   .::     .: .::        .::        \033[0m     \n";
        cout << "\033[1;34m       .::   .::           .:::::: .::    .::  .::      .::        \033[0m     \n";
        cout << "\033[1;34m .::    .::  .::          .::       .::   .::    .::     .::   .:: \033[0m     \n";
        cout << "\033[1;34m   .:: ::    .::         .::         .::  .::      .::     .::::   \033[0m     \n";
        cout << "\033[1;34m-------------------------------------------------------------------\033[0m     \n";
        cout << "\033[1;34m|        Student Projects and Research Committee IEEE 2019        |\033[0m     \n";
        cout << "\033[1;34m ------------------------------------------------------------------\033[0m    \n";
        cout << "Starting robot...\n";
}

void testMovement()
{
        serialPort arduino("/dev/ttyACM0");
        arduino.goForward(22);
        sleep(3);
        arduino.stopMotors();
        sleep(1);
        arduino.turnRight(19);        
        sleep(1);
        arduino.stopMotors();
        sleep(1);
        arduino.goForward(25);        
        sleep(3);
        arduino.stopMotors();
        arduino.turnLeft(14);        
        sleep(1);
        arduino.stopMotors();
        sleep(1);
        arduino.goForward(27);        
        sleep(1);
        arduino.stopMotors();
}
