#include <Cytron_SmartDriveDuo.h>
#define IN1 4 // Arduino pin 4 is connected to MDDS60 pin IN1.
#define BAUDRATE  9600
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_SIMPLFIED, IN1, BAUDRATE);

char streamIn[2] = "00";
int speed1;
int speed2;
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  smartDriveDuo30.control(0, 0);
}

void loop()
{
  digitalWrite(13,LOW);
  while (Serial.available()<2);
  speed1  = ((int)Serial.read())-127;
  speed2  = ((int)Serial.read())-127;    
  smartDriveDuo30.control(speed1,speed2);
  digitalWrite(13,HIGH);
  Serial.flush();
  delay(1000);
}
