#pragma once

#include <string>
#include <termios.h>

class serialPort {
public:
	serialPort(const char* portName);
	void write(std::string text);
	int available();
	std::string read();
	void controlMotors(bool dir1, int speed1, bool dir2, int speed2);
	void turnLeft(int speed);
	void turnRight(int speed);
	void goForward(int speed);
	void goBackward(int speed);
	void stopMotors();
	~serialPort();

	static const char typicalPortName[];

private:
	int fileHandle;
	termios config;
};
