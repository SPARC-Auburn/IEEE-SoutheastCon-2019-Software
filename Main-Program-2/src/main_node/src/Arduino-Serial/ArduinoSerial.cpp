/*------------------------------------------------------------------------------
Filename:     ArduinoSerial.cpp
Project:      IEEE SoutheastCon Hardware Competition 2019
School:       Auburn University
Organization: Student Projects and Research Committee (SPARC)
Description:  Communicates with an Arduino from the Raspberry Pi 3 B+ over USB.
Controls 2 drive motors and 3 steppers.  Speed ranges are from -127 to 127.
------------------------------------------------------------------------------*/
#include "ArduinoSerial.h"
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <cerrno>
#include <cstring>		//for strerror()
#include <sstream>
#include <iostream>
#include <string>

// Constants
#define DEBUG_TEXT 1
const char serialPort::typicalPortName[] = "/dev/ttyUSB0";

// Namespaces
using namespace std;

// Variables
int leftDriveSpeed = 0;
int rightDriveSpeed = 0;
int gatePos = 0;
int flagPos = 0;
string LCDtext = "Connected!";

serialPort::serialPort(const char* portName) {
  fileHandle = open(portName, O_RDWR | O_NOCTTY | O_NDELAY);
  if(fileHandle == -1) {
    throw std::runtime_error(string("Error opening port: ") + strerror(errno));
  }
  if(!isatty(fileHandle)) {
    close(fileHandle);
    throw std::runtime_error("Port is not a serial device.");
  }

  cfmakeraw(&config);     //Sets various parameters for non-canonical mode; disables parity

  cfsetospeed (&config, B9600);    //Baud rate
  cfsetispeed (&config, B9600);

  config.c_cflag     &=  ~CSTOPB;    //One stop bit

  config.c_cflag     |=  CREAD | CLOCAL;
  config.c_cflag     &=  ~CRTSCTS;           // no flow control

  config.c_cc[VMIN]   =  0;
  config.c_cc[VTIME]  =  0;

  if(tcsetattr(fileHandle, TCSANOW, &config) != 0) {
    close(fileHandle);
    throw std::runtime_error("Setting attributes failed.");
  }
  usleep(1000*1000*1); // wait 1 sec for arduino to reset
  tcflush(fileHandle, TCIFLUSH);    //clear input buffer
  usleep(1000*1000*1); // wait 1 sec for arduino to reset
}

void serialPort::write(string text) {
  ::write(fileHandle, text.c_str(), text.length());
}

void serialPort::write(char data[], int length) {
  ::write(fileHandle, data, length);
}

string serialPort::read() {
  string input;
  int bytes = available();
  input.resize(bytes);
  ::read(fileHandle, const_cast<char*>(input.data()) , bytes);    //The const cast is less than ideal
  return(input);
}

int serialPort::available() {
  int bytes;
  ioctl(fileHandle, FIONREAD, &bytes);
  return(bytes);
}

// Updates the motor speeds according to the state variables
void serialPort::updateArduino() {
  signed char char1 = (signed char)(leftDriveSpeed);
  signed char char2 = (signed char)(rightDriveSpeed);
  unsigned char char3 = (unsigned char)(gatePos);
  unsigned char char4 = (unsigned char)(flagPos);
  string newText = LCDtext;
  newText.resize(32 , ' ');
  unsigned char char5 = char1 + char2 + char3 + char4 + 1;
  signed char motorData[2] = {char1,char2};
  unsigned char servoData[3] = {char3, char4, char5};
  if (DEBUG_TEXT){
    cout << "Sending to Arduino: " << (int)char1 << "," << (int)char2 << "," << (int)char3  << "," << (int)char4 << "," << (int)char5 << "," << newText << endl;
    cout << "Total bytes: " << (5+newText.length()) << endl;
  }
  ::write(fileHandle, motorData, 2); //Send messages
  ::write(fileHandle, servoData, 3); //Appended checksum
  ::write(fileHandle, newText.c_str(), newText.length());
  char qqqq[32];
  memcpy(qqqq,newText.c_str(),32);
  for(int i = 0; i<32; i++)cout << (int)qqqq[i] << " ";
  cout << endl;
  string received = read();
  if (DEBUG_TEXT){
    cout << "Received from Arduino: " << received << endl;
  }
  //TODO: Parse received string to get goButton state
}

void serialPort::turnLeft(int speed){
  if(speed < 0 || speed > 127)
		throw out_of_range("Motor speed must be between 0 and 127.");
  leftDriveSpeed = speed;
  rightDriveSpeed = -speed;
  updateArduino();
}

void serialPort::turnRight(int speed){
  if(speed < 0 || speed > 127)
		throw out_of_range("Motor speed must be between 0 and 127.");
  leftDriveSpeed = -speed;
  rightDriveSpeed = speed;
  updateArduino();
}

void serialPort::goForward(int speed){
  if(speed < 0 || speed > 127)
		throw out_of_range("Motor speed must be between 0 and 127.");
  leftDriveSpeed = -speed;
  rightDriveSpeed = -speed;
  updateArduino();
}

void serialPort::goBackward(int speed){
  if(speed < 0 || speed > 127)
		throw out_of_range("Motor speed must be between 0 and 127.");
  leftDriveSpeed = speed;
  rightDriveSpeed = speed;
  updateArduino();
}

void serialPort::stopMotors(){
  leftDriveSpeed = 0;
  rightDriveSpeed = 0;
  updateArduino();
}

void serialPort::moveGate(int pos){
  if(pos < 0 || pos > 180)
		throw out_of_range("Servo position must be between 0 and 180.");
  gatePos = pos;
  updateArduino();
}

void serialPort::moveFlag(int pos){
  if(pos < 0 || pos > 180)
		throw out_of_range("Servo position must be between 0 and 180.");
  flagPos = pos;
  updateArduino();
}

void serialPort::updateLCD(string text){
LCDtext = text;
  cout << "New LCD text: " << text << endl;
  updateArduino();
}

serialPort::~serialPort() {
  cout << "Disconnecting from Arduino..." << endl;
  close(fileHandle);
}
