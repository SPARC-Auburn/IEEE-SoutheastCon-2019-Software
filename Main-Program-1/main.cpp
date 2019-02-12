#include "Arduino-Serial/ArduinoSerial.h"
#include "Arduino-Serial/ArduinoSerial.cpp"
#include "Vision-Processing/vision.cpp"
#include <unistd.h>
#include <iostream>

void startupRoutine();

int main()
{
        startupRoutine();
        cout << "Connecting to Arduino...\n";
        serialPort arduino("/dev/ttyUSB0");
        int angle = 0;        
        IEEE_VISION::VisionHandle vis;
        while (0 == 0)
        {
                angle = vis.angle2LargestDebris(1);
                cout << "Angle to Debris: " << angle << "\n";
                if (angle > 5 && angle < 120)
                {
                        cout << "Turning Right\n";
                        arduino.turnRight(25);
                        usleep(20*1000);
                        arduino.stopMotors();
                }
                else if (angle < -5 && angle > -120)
                {
                        cout << "Turning Left\n";
                        arduino.turnLeft(25);
                        usleep(20*1000);
                        arduino.stopMotors();
                }
                else
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
