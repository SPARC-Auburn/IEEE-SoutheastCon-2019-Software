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
        serialPort arduino("/dev/ttyACM0");
        int angle = 0;
        IEEE_VISION::VisionHandle vis;
        cout << "Finding Closest Debris...\n";
        cout << "Turning Left\n";
        while (0 == 0)
        {
                angle = vis.angle2LargestDebris();
                cout << "Angle to Debris: " << angle << "\n";
                if (angle > 5 && angle < 120)
                {
                        cout << "Turning Right\n";
                        arduino.turnRight(60);
                }
                else if (angle < -5 && angle > -120)
                {
                        cout << "Turning Left\n";
                        arduino.turnLeft(60);
                }
                else
                {
                        arduino.stopMotors();
                }
                usleep(10);
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
