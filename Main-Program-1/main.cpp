#include "Arduino-Serial/ArduinoSerial.h"
#include "Arduino-Serial/ArduinoSerial.cpp"
#include "Vision-Processing/vision.cpp"
#include <unistd.h>
#include <iostream>

void startupRoutine();

int main (){    
        startupRoutine(); 
        cout << "Connecting to Arduino...\n"; 
        serialPort arduino("/dev/ttyACM0");       
        int angle = 180;
        cout << "Finding Closest Debris...\n"; 
        while (abs(angle) > 5){
                angle = getAngle2ClosestDebris();
                cout << "Angle to Debris: "<< angle << "\n"; 
                if (angle > 0)
                        arduino.turnLeft(100);
                else
                        arduino.turnRight(100);
                usleep(1000);
        }
        arduino.stopMotors();    
        return 0;
}

void startupRoutine(){
        cout << "\033[1;34m-------------------------------------------------------------------\033[0m     \n";
        cout << "\033[1;34m   .:: ::    .:::::::          .:         .:::::::          .::    \033[0m     \n";
        cout << "\033[1;34m .::    .::  .::    .::       .: ::       .::    .::     .::   .:: \033[0m     \n";
        cout << "\033[1;34m  .::        .::    .::      .:  .::      .::    .::    .::        \033[0m    \n";
        cout << "\033[1;34m    .::      .:::::::       .::   .::     .: .::        .::        \033[0m     \n";
        cout << "\033[1;34m       .::   .::           .:::::: .::    .::  .::      .::        \033[0m     \n";
        cout << "\033[1;34m .::    .::  .::          .::       .::   .::    .::     .::   .:: \033[0m     \n";
        cout << "\033[1;34m   .:: ::    .::         .::         .::  .::      .::     .::::   \033[0m     \n";  
        cout << "\033[1;34m-------------------------------------------------------------------\033[0m     \n";        
        cout << "\033[1;34m|        Student Projects and Reasearch Committee IEEE 2019       |\033[0m     \n"; 
        cout << "\033[1;34m ------------------------------------------------------------------\033[0m    \n";                    
        cout << "Starting robot...\n";                        
}