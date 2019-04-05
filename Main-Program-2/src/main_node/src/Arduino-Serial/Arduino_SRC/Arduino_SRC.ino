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
unsigned char gatePos;
unsigned char flagPos;
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_SIMPLFIED, IN1, MOTOR_CONTROLLER_BAUDRATE);
Servo gateServo;
Servo flagServo;
const int goButton = 2;
char goState = 0;

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
  lcd.print("Starting up..");
  gateServo.attach(10);
  flagServo.attach(11);
  pinMode(goButton, INPUT)
}

void loop()
{

  while (Serial.available()<37){ //5 bytes for speeds and positions; 32 bytes for LCD message
    digitalWrite(13,LOW);
    buttonState = digitalRead(goButton);
    if (buttonState == HIGH){
      goState = 1;
    }
  } 
  speed1  = Serial.read(); // left drive speed
  speed2  = Serial.read(); // Right drive speed
  gatePos = Serial.read(); //Gate servo position
  flagPos = Serial.read(); //Flag servo position
  signed char checksumIn = Serial.read();
  LCDtext = Serial.read(); //New LCDtext
  signed char calculatedChecksum = speed1 + speed2  + gatePos + flagPos + 1;
  digitalWrite(13,HIGH);
  Serial.print(speed1);
  Serial.print(',');
  Serial.print(speed2);
  Serial.print(',');
  Serial.print(gatePos);
  Serial.print(',');
  Serial.print(flagPos);
  Serial.print(',');
  Serial.print(checksumIn);
  Serial.print(',');
  Serial.print(LCDtext);
  Serial.print(',');
  Serial.print(goState);
  if(calculatedChecksum == checksumIn){
    Serial.println(", Correct");
    smartDriveDuo30.control(speed1,speed2);
    gateServo.write(gatePos);
    flagServo.write(flagPos);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(LCDtext.substr(0,16)); //First line of LCD
    lcd.setCursor(0,1);
    lcd.print(LCDtext.substr(17,32)); //Second Line of LCD
  }
  else
    Serial.println(", Error");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Input Error");
  Serial.flush();
  delay(1);
}
