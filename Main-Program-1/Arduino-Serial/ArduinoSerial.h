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
	~serialPort();

	static const char typicalPortName[];

private:
	int fileHandle;
	termios config;
};
