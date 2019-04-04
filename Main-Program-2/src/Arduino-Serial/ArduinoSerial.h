#pragma once

#include <string>
#include <termios.h>

class serialPort {
public:
	serialPort(const char* portName);
	
	void write(std::string text);
	template<int size>
	void write(char data[size]) { write(data, size); }
	
	int available();
	std::string read();
	void updateMotors();
	void turnLeft(int speed);
	void turnRight(int speed);
	void goForward(int speed);
	void goBackward(int speed);
	void raiseGate(int speed);
	void lowerGate(int speed);
	void holdGate();
	void spinForward(int speed);
	void spinBackward(int speed);
	void stopSpinner();
	void stopMotors();
	~serialPort();

	static const char typicalPortName[];

private:
	int fileHandle;
	termios config;
	
	void write(char data[], int length);		//Only exists so that template's ::write call does not have to go in the header
};
