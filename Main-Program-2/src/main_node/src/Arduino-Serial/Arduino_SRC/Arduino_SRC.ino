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
//#include <std_msgs/String.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Constants
#define IN1 4 // Arduino pin 4 is connected to MDDS60 pin IN1.
#define MOTOR_CONTROLLER_BAUDRATE  9600
#define RASPBERRY_PI_BAUDRATE  9600

// Variables
char streamIn[2] = {'0', '0'};
signed char speed1;
signed char speed2;
signed char gatePos;
signed char flagPos;
signed char LCDtext;
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_SIMPLFIED, IN1, MOTOR_CONTROLLER_BAUDRATE);
Servo gateServo;
Servo flagServo;

// Setup serial and pin states
void setup()
{
  pinMode(13, OUTPUT); 
  Serial.begin(RASPBERRY_PI_BAUDRATE);
  smartDriveDuo30.control(0, 0);
  lcd.begin();
  lcd.begin();
  lcd.backlight();  
  lcd.clear();
  lcd.print("Starting Up Pi.. Please wait..");
  gateServo.attach(10);
  flagServo.attach(11);
}

void loop()
{
  digitalWrite(13,LOW);
  while (Serial.available()<3);
  speed1  = Serial.read(); // left drive speed
  speed2  = Serial.read(); // Right drive speed
  gatePos = Serial.read(); //Gate servo position
  flagPos = Serial.read(); //Flag servo position
  LCDtext = Serial.read(); //New LCDtext
  signed char calculatedChecksum = speed1 + speed2 + gatePos + flagPos + LCDtext + 1;
  signed char checksumIn = Serial.read();
  digitalWrite(13,HIGH);
  Serial.print(speed1);
  Serial.print(',');
  Serial.print(speed2);
  Serial.print(',');
  Serial.print(gatePos);
  Serial.print(',');
  Serial.print(flagPos);
  Serial.print(',');
  Serial.print(LCDtext);
  Serial.print(',');
  Serial.print(checksumIn);
  if(calculatedChecksum == checksumIn){
    Serial.println(", Correct");
    smartDriveDuo30.control(speed1,speed2);
    gateServo.write(gatePos);
    flagServo.write(flagPos);
    lcd.print(LCDtext);
  }
  else
    Serial.println(", Error");
  Serial.flush();
  delay(1);
}
