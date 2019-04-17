/*------------------------------------------------------------------------------
Filename:     ArduinoSerial.cpp
Project:      IEEE SoutheastCon Hardware Competition 2019
School:       Auburn University
Organization: Student Projects and Research Committee (SPARC)
Description:  Communicates with a Raspberry Pi 3 B+ over USB.
Controls 2 drive motors and 3 steppers.  Speed ranges are from -127 to 127.
Speed Order = leftDriveSpeed,rightDriveSpeed,leftGateSpeed,rightGateSpeed,
              spinnerSpeed
------------------------------------------------------------------------------*/
#include <Cytron_SmartDriveDuo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Constants
#define IN1 4 // Arduino pin 4 is connected to MDDS60 pin IN1.
#define BUTTON 2
#define POTPIN A7
#define MOTOR_CONTROLLER_BAUDRATE  9600
#define RASPBERRY_PI_BAUDRATE  38400

// Variables
signed char speed1;
signed char speed2;
unsigned char gatePos;
unsigned char flagPos;
String LCDtext = "Waiting for      connection";
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_SIMPLFIED, IN1, MOTOR_CONTROLLER_BAUDRATE);
Servo gateServo;
Servo flagServo;

String buttonState = "0";
unsigned char clearButtonState = 0;
String mode = "-1"; // Should we go?
int sensorValue = 0; //Pot value
int time =0;
const byte numChars = 38;
char receivedChars[numChars];
char receivedLCDText[32];

boolean newData = false;



// Setup serial and pin states
void setup()
{
  pinMode(13, OUTPUT); 
  smartDriveDuo30.control(0, 0);
  gateServo.attach(10);
  flagServo.attach(11);
  pinMode(BUTTON, INPUT);
  delay(1000);
  smartDriveDuo30.control(0, 0);
  digitalWrite(13,LOW);                   //Reading button
  int pos = 50;
  smartDriveDuo30.control(25, 25);
  delay(1400);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(25,-25);
  delay(420);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(25, 25);
  delay(1400);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(-25,25);
  delay(600);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(25, 25);
  delay(1500);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(-25,25);
  delay(600);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(25, 25);
  delay(1400);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(-25,25);
  delay(600);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(25, 25);
  delay(1500);
  smartDriveDuo30.control(0,0);
  delay(500);
  smartDriveDuo30.control(25, 25);
  delay(1500);
  smartDriveDuo30.control(0,0);
  delay(500);
        

   //for( int time = 0; time<9; time++)
   //{
        // smartDriveDuo30.control(25,10);
         //delay(2500);
         //delay(500);
         //smartDriveDuo30.control(-25,25);
         //delay(500);
        // smartDriveDuo30.control(25,25);
         //delay(2000);
         //smartDriveDuo30.control(-25,-25);
         //delay(5700);
         //smartDriveDuo30.control(25,20);
         //delay(5700);
     // }
      
    //smartDriveDuo30.control(-25, -25);   
    //delay(1500); 
    //smartDriveDuo30.control(0, 0);
    //flagServo.write(140);
    //flagServo.write(140);
    //flagServo.write(140);
    //flagServo.write(140);
    //flagServo.write(140);
}

void loop()
{
  
    

  
}
