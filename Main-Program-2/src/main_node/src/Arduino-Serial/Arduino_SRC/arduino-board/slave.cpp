#include <Arduino.h>

#include <Cytron_SmartDriveDuo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#include "order.h"
#include "slave.h"
#include "parameters.h"

#define IN1 4
#define BUTTON 2
#define POTPIN A7
#define MOTOR_CONTROLLER_BAUDRATE 9600
#define FLAGPIN 11
#define GATEPIN 10


bool is_connected = false; ///< True if the connection with the master is available

int8_t lmotor_speed = 0;
int8_t lmotor_speed = 0;
int16_t flag_servo_angle = INITIAL_THETA;
int16_t gate_servo_angle = INITIAL_THETA;
String currentLCDtext = "Waiting for      connection";
String newLCDtext;
Servo flagServo;
Servo gateServo;

int buttonState = 0;
int clearButtonState - 0;
int mode = -1;
int sensorValue = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Cytron_SmartDriveDuo smartDriveDuo30(SERIAL_SIMPLIFIED, IN1, MOTOR_CONTROLLER_BAUDRATE);

void setup()
{
  // Init Serial
  Serial.begin(SERIAL_BAUD);

  // Init Motor
  pinMode(13, OUTPUT);
  smartDriveDuo30.control(0,0);
  lcd.begin();
  lcd.begin()
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(currentLCDtext.substring(0,16)); //First line of LCD
  lcd.setCursor(0,1);
  lcd.print(currentLCDtext.substring(17,32)); //Second Line of LCD
  stop();

  // Init Servo
  gateServo.attach(GATEPIN);
  flagServo.attach(FLAGPIN);
  // Order between 0 and 180
  gateServo.write(INITIAL_THETA);
  flagServo.attach(INITIAL_THETA);

  // Wait until the arduino is connected to master
  while(!is_connected)
  {
    write_order(HELLO);
    wait_for_bytes(1, 1000);
    get_messages_from_serial();
  }

}

void loop()
{
  get_messages_from_serial();
  update_Bot();
}

void update_Bot()
{
  digitalWrite(13,LOW);                   //Reading button
  int buttonRead = digitalRead(BUTTON);
  if (buttonRead == HIGH){
    buttonState = 1;
  }
  if (clearButtonState == 1){
    buttonState = 0;
  }
  sensorValue = analogRead(POTPIN);       //Reading pot
  if (sensorValue < 255){       //Red
      mode = "0";
    }
    else if (sensorValue < 510){    //Green
      mode = 1;
    }
    else if (sensorValue < 765){    //Blue
      mode = 2;
    }                           
    else if (sensorValue < 1024){   //Yellow
      mode = 3;
    }
    else {    //Error
      mode = -1;
    }
	smartDriveDuo30.control(lmotor_speed, rmotor_speed);
	gateServo.write(gate_servo_angle);
	flagServo.write(flag_servo_angle);
	if(newLCDtext != currentLCDtext){
		currentLCDtext = newLCDtext;
		lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(currentLCDtext.substring(0,15)); //First line of LCD
        lcd.setCursor(0,1);
        lcd.print(currentLCDtext.substring(16,32)); //Second Line of LCD
	}
}

void stop()
{
  smartDriveDuo30.control(lmotor_speed, rmotor_speed);
}

int convert_to_pwm(float motor_speed)
{
  // TODO: compensate the non-linear dependency speed = f(PWM_Value)
  return (int) round(abs(motor_speed)*(255./100.));
}

void get_messages_from_serial()
{
  if(Serial.available() > 0)
  {
    // The first byte received is the instruction
    Order order_received = read_order();

    if(order_received == HELLO)
    {
      // If the cards haven't say hello, check the connection
      if(!is_connected)
      {
        is_connected = true;
        write_order(HELLO);
      }
      else
      {
        // If we are already connected do not send "hello" to avoid infinite loop
        write_order(ALREADY_CONNECTED);
      }
    }
    else if(order_received == ALREADY_CONNECTED)
    {
      is_connected = true;
    }
    else
    {
      switch(order_received)
      {
        case STOP:
        {
          lmotor_speed = 0;
		  rmotor_speed = 0;
          stop();
          if(DEBUG)
          {
            write_order(STOP);
          }
          break;
        }
        case GATESERVO:
        {
          gate_servo_angle = read_i16();
          if(DEBUG)
          {
            write_order(GATESERVO);
            write_i16(gate_servo_angle);
          }
          break;
        }
		case FLAGSERVO:
        {
          flag_servo_angleservo_angle = read_i16();
          if(DEBUG)
          {
            write_order(FLAGSERVO);
            write_i16(flag_servo_angle);
          }
          break;
        }
        case LMOTOR:
        {
          // between -100 and 100
          lmotor_speed = read_i8();
          if(DEBUG)
          {
            write_order(LMOTOR);
            write_i8(lmotor_speed);
          }
          break;
        }
		case RMOTOR:
        {
          // between -100 and 100
          rmotor_speed = read_i8();
          if(DEBUG)
          {
            write_order(RMOTOR);
            write_i8(rmotor_speed);
          }
          break;
        }
  			// Unknown order
  			default:
          write_order(ERROR);
          write_i16(404);
  				return;
      }
    }
    write_order(RECEIVED); // Confirm the reception
  }
}


Order read_order()
{
	return (Order) Serial.read();
}

void wait_for_bytes(int num_bytes, unsigned long timeout)
{
	unsigned long startTime = millis();
	//Wait for incoming bytes or exit if timeout
	while ((Serial.available() < num_bytes) && (millis() - startTime < timeout)){}
}

// NOTE : Serial.readBytes is SLOW
// this one is much faster, but has no timeout
void read_signed_bytes(int8_t* buffer, size_t n)
{
	size_t i = 0;
	int c;
	while (i < n)
	{
		c = Serial.read();
		if (c < 0) break;
		*buffer++ = (int8_t) c; // buffer[i] = (int8_t)c;
		i++;
	}
}

int8_t read_i8()
{
	wait_for_bytes(1, 100); // Wait for 1 byte with a timeout of 100 ms
  return (int8_t) Serial.read();
}

int16_t read_i16()
{
  int8_t buffer[2];
	wait_for_bytes(2, 100); // Wait for 2 bytes with a timeout of 100 ms
	read_signed_bytes(buffer, 2);
  return (((int16_t) buffer[0]) & 0xff) | (((int16_t) buffer[1]) << 8 & 0xff00);
}

int32_t read_i32()
{
  int8_t buffer[4];
	wait_for_bytes(4, 200); // Wait for 4 bytes with a timeout of 200 ms
	read_signed_bytes(buffer, 4);
  return (((int32_t) buffer[0]) & 0xff) | (((int32_t) buffer[1]) << 8 & 0xff00) | (((int32_t) buffer[2]) << 16 & 0xff0000) | (((int32_t) buffer[3]) << 24 & 0xff000000);
}

void write_order(enum Order myOrder)
{
	uint8_t* Order = (uint8_t*) &myOrder;
  Serial.write(Order, sizeof(uint8_t));
}

void write_i8(int8_t num)
{
  Serial.write(num);
}

void write_i16(int16_t num)
{
	int8_t buffer[2] = {(int8_t) (num & 0xff), (int8_t) (num >> 8)};
  Serial.write((uint8_t*)&buffer, 2*sizeof(int8_t));
}

void write_i32(int32_t num)
{
	int8_t buffer[4] = {(int8_t) (num & 0xff), (int8_t) (num >> 8 & 0xff), (int8_t) (num >> 16 & 0xff), (int8_t) (num >> 24 & 0xff)};
  Serial.write((uint8_t*)&buffer, 4*sizeof(int8_t));
}
