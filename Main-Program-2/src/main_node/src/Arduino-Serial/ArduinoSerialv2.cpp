#include <errno.h>
#include <fcntl.h> 
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "ArduinoSerialv2.h"

// Constants
#define DEBUG_TEXT 1
const char serialPort::typicalPortName[] = "/dev/ttyUSB0";

// Variables
int leftDriveSpeed = 0;
int rightDriveSpeed = 0;
int gatePos = 0;
int flagPos = 0;
string LCDtext = "Connected!";
string buttonState = "0";
int clearButtonState = 0;
string mode = "-1";

//SerialVariables
int fd;

serialPort::serialPort(const char* portName, int speed){
  fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);
  if (fd < 0)
  {
          error_message ("error %d opening %s: %s", errno, portname, strerror (errno));
          return;
  }

  set_interface_attribs (fd, speed, 0);  // set speed to 115,200 bps, 8n1 (no parity)
  set_blocking (fd, 0);                // set no blocking

}

int serialPort::set_interface_attribs (int fd, int speed, int parity){
  
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                error_message ("error %d from tcgetattr", errno);
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                error_message ("error %d from tcsetattr", errno);
                return -1;
        }
        return 0;
}

void serialPort::set_blocking (int fd, int should_block)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                error_message ("error %d from tggetattr", errno);
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
                error_message ("error %d setting term attributes", errno);
}

void serialPort::updateArduino(){
        //Write our message first
        char startChar[1] = {'<'};
        char endChar[1] = {'>'};
        signed char leftMotor = (signed char)(leftMotorSpeed);
        signed char rightMotor = (signed char)(rightMotorSpeed);
        unsigned char gate = (unsigned char)(gatePos);
        unsigned char flag = (unsigned char)(flagPos);
        unsigned char clearState = (unsigned char)(clearButtonState);
        string newText = LCDtext;
        newText.resize(32 , ' ');
        unsigned char checkSum = leftMotor + rightMotor + gate + flag + clearState + 1; 
        char data[7] = {startChar, leftMotor, rightMotor, gate, flag, clearState, checkSum}
        write (fd, data, 7);           // send 7 data characters
        write (fd, newText.c_str(), newText.length());
        write (fd, endChar, 1);
        usleep ((38 + 25) * 100);             // sleep enough to transmit the 7 plus
        //Listen for a response
        char buf [50];
        string n = read (fd, buf, sizeof buf);  // read up to 100 characters if ready to read
        string delim = ","; //Pick out 6th value to find buttonState
        auto start = 0U;
        auto end = received.find(delim);
        int value = 0;
        if (DEBUG_TEXT){
                cout << "Recieved from Arduino: ";
        }
        while (end != string::npos){
                value++;
                if(value==8){
                        buttonState = received.substr(start, end - start);
                        if (DEBUG_TEXT){
                                cout << "ButtonState: " << buttonState << ",";
                        }
                }
                else if(value==9){
                        mode = received.substr(start, end - start);
                        if (DEBUG_TEXT){
                                cout << "Mode: " << mode;
                        }
                        break;
                }
                if (DEBUG_TEXT){
                        cout << received.substr(start, end - start) << ",";
                }
                start = end + delim.length();
                end = received.find(delim, start);
        }
        if (DEBUG_TEXT){
                cout << endl;
        }
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
void serialPort::drive(int left, int right){
  leftDriveSpeed = left;
  rightDriveSpeed = right;
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

int serialPort::getMode(){
	updateArduino();
	return stoi(mode);
}

int serialPort::getButtonState(){
	int currentState = 0;
	updateArduino();
	currentState = stoi(buttonState);
	if (buttonState == "1"){
		clearButtonState = 1;
		buttonState = "0";
	}
	else{
		clearButtonState = 0;
	}
	return currentState;
}


serialPort::~serialPort() {
  cout << "Disconnecting from Arduino..." << endl;
  updateLCD("Disconnected..");
  close(fd);
}

