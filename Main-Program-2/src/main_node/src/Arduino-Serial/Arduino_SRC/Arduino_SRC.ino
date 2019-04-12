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

const byte numChars = 38;
char receivedChars[numChars];
char receivedLCDText[32];

boolean newData = false;

//Serial RECV
void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    auto s = Serial.readStringUntil('>');
    int first = s.indexOf(",");
    int second = s.indexOf(",",first+1);
    int third = s.indexOf(",",second+1);
    int fourth = s.indexOf(",",third+1);
    int fifth = s.indexOf(",",fourth+1);
    speed1 = s.substring(1,first).toInt();
    speed2 = s.substring(first+1,second).toInt();
    gatePos = s.substring(second+1,third).toInt();
    flagPos = s.substring(third+1,fourth).toInt();
    clearButtonState = s.substring(fourth+1,fifth).toInt();
    LCDtext = s.substring(fifth+1);
}

//Output Data
void takeNewData() {
  Serial.print(speed1);
  Serial.print(',');
  Serial.print(speed2);
  Serial.print(',');
  Serial.print(gatePos);
  Serial.print(',');
  Serial.print(flagPos);
  Serial.print(',');
  Serial.print(clearButtonState);
  Serial.print(',');
  Serial.print(LCDtext);
  Serial.print(',');
  Serial.print(buttonState);
  Serial.print(',');
  Serial.print(mode);
  Serial.println(", Correct");
  smartDriveDuo30.control(speed1,speed2);
  gateServo.write(gatePos);
  flagServo.write(flagPos);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(LCDtext.substring(0,15)); //First line of LCD
  lcd.setCursor(0,1);
  lcd.print(LCDtext.substring(16,32)); //Second Line of LCD
}


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
  lcd.setCursor(0,0);
  lcd.print(LCDtext.substring(0,16)); //First line of LCD
  lcd.setCursor(0,1);
  lcd.print(LCDtext.substring(17,32)); //Second Line of LCD
  gateServo.attach(10);
  flagServo.attach(11);
  
  gateServo.write(20);//initial flag and gate position
  flagServo.write(130);
  pinMode(BUTTON, INPUT);
  while(Serial.available())
  Serial.read();
}

void loop()
{
  digitalWrite(13,LOW);                   //Reading button
  int buttonRead = digitalRead(BUTTON);
  if (buttonRead == HIGH){
    buttonState = "1";
  }
  if (clearButtonState == 1){
    buttonState = "0";
  }
  sensorValue = analogRead(POTPIN);       //Reading pot
  if (sensorValue < 255){       //Red
      mode = "0";
    }
    else if (sensorValue < 510){    //Yellow
      mode = "1";
    }
    else if (sensorValue < 765){    //Blue
      mode = "2";
    }                           
    else if (sensorValue < 1024){   //Green
      mode = "3";
    }
    else {    //Error
      mode = "-1";
    }
  recvWithStartEndMarkers();
  takeNewData();  

  delay(1);
}
