#pragma once

#include <string>
#include <termios.h>

class serialPort {
public:
	serialPort(const char* portName, int speed);
	template<int size>
	int set_interface_attribs (int fd, int speed, int parity)
	void set_blocking (int fd, int should_block)
	void updateArduino();
	void turnLeft(int speed);
	void turnRight(int speed);
	void goForward(int speed);
	void goBackward(int speed);
	void drive(int left, int right);
	void stopMotors();
	void moveFlag(int pos);
	void updateLCD(string text);
	int getMode();
	int getButtonState();
	~serialPort();

	static const char typicalPortName[];

private:
	int fd;
	termios config;
};
