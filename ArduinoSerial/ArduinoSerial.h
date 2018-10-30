#pragma once

#include <string>
#include <termios.h>

class serialPort {
public:
	serialPort(const char* portName);
	int fileHandle;
	termios config;
	void write(std::string text);
	int available();
	std::string read();
	~serialPort();
};