#include "ArduinoSerial.h"
#include <stdexcept>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <cerrno>
#include <cstring>		//for strerror()
#include <sstream>

using namespace std;


const char serialPort::typicalPortName[] = "/dev/ttyACM0";

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

  tcflush(fileHandle, TCIFLUSH);    //clear input buffer
  if(tcsetattr(fileHandle, TCSANOW, &config) != 0) {
    close(fileHandle);
    throw std::runtime_error("Setting attributes failed.");
  }
}

void serialPort::write(string text) {
  ::write(fileHandle, text.c_str(), text.length());
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

void serialPort::controlMotors(bool dir1, int speed1, bool dir2, int speed2) {
	if(speed1 < 0 || speed1 > 255 || speed2 < 0 || speed1 > 255)
		throw out_of_range("Motor speed must be between 0 and 255.");

	stringstream output;
	output << dir1 << ',' << speed1 << ',' << dir2 << ',' << speed2;
	write(output.str());		//There is an unnecessary copy here
}

serialPort::~serialPort() {
  close(fileHandle);
}
