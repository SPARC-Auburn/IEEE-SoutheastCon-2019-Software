/* 
 * This example shows how to control MDDS30 in Serial Simplified mode with Arduino.
 * Set MDDS30 input mode to 0b11001100
 * Open Serial Monitor, set baudrate to 9600bps and "No line ending".
 * Send 0: Left motor stops
 *      1: Left motor rotates CW with half speed
 *      2: Left motor rotates CW with full speed
 *      3: Left motor rotates CCW with half speed
 *      4: Left motor rotates CCW with full speed
 *      5: Right motor stops
 *      6: Right motor rotates CW with half speed
 *      7: Right motor rotates CW with full speed
 *      8: Right motor rotates CCW with half speed
 *      9: Right motor rotates CCW with full speed
 * 
 * Note: This example also compatible with MDDS10 and MDDS60
 *
 * Hardware Connection:
 *   Arduino Uno    MDDS30
 *   GND ---------- GND
 *   4 ------------ IN1
 *
 * Related Products:
 * - SmartDriveDuo-30: http://www.cytron.com.my/P-MDDS60
 * - CT UNO: http://www.cytron.com.my/p-ct-uno
 * - DC Brush Motors: http://www.cytron.com.my/c-84-dc-motor
 * - LiPo Battery: http://www.cytron.com.my/c-87-power/c-97-lipo-rechargeable-battery-and-charger
 * - Male to Male Jumper: https://www.cytron.com.my/p-wr-jw-mm65
 *
 * URL: http://www.cytron.com.my
 */

//#include <SoftwareSerial.h>
#include <Cytron_SmartDriveDuo.h>
#define IN1 4 // Arduino pin 4 is connected to MDDS60 pin IN1.
#define BAUDRATE  9600
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_SIMPLFIED, IN1, BAUDRATE);

char inChar;
signed int speedLeft, speedRight;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  smartDriveDuo30.control(0, 0);
}

void loop()
{
  if (Serial.available()) {
    int dir1  = (int)Serial.parseInt();
    while(!Serial.available()){}
    int speed1  = (int) Serial.parseInt();
    while(!Serial.available()){}
    int dir2  = (int) Serial.parseInt();
    while(!Serial.available()){}
    int speed2  = (int) Serial.parseInt();
    while(!Serial.available()){}
    int checkSum = (int) Serial.parseInt();
    if (dir1+speed1+dir2+speed2 == checkSum){
      if (dir1 == 0)
        dir1 = -1;
      if (dir2 == 0)
        dir2 = -1;
      smartDriveDuo30.control(speed1*dir1, speed2*dir1);
    }
    else
      smartDriveDuo30.control(0,0);
  }
  Serial.flush();
}
