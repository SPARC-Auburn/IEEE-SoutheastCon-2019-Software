#include <SoftwareSerial.h>
#include <Cytron_SmartDriveDuo.h>
#define IN1 4 // Arduino pin 4 is connected to MDDS60 pin DIG1.
#define BAUDRATE  9600
#define BOARD_ID  0
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_PACKETIZED, IN1, BOARD_ID, BAUDRATE);

char inChar;
signed int speedLeft, speedRight;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  smartDriveDuo30.control(0, 0);
  while (Serial.available() > 0) {
    int dir1  = Serial.parseInt();
    int speed1  =  Serial.parseInt();
    int dir2  =  Serial.parseInt();
    int speed2  =  Serial.parseInt();
    if (dir1 == 0)
      dir1 = -1;
    if (dir2 == 0)
      dir2 = -1;
    smartDriveDuo30.control(speed1*dir1+127, speed2*dir1+127);
    Serial.flush();
}
