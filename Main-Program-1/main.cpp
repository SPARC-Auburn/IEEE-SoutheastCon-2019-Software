#include "Arduino-Serial/ArduinoSerial.h"
#include <unistd.h>

int main (){    
    serialPort arduino ("/dev/ttyACM0");
   while (1){
        arduino.controlMotors(1, 255, 1, 255);
        sleep(2);
	arduino.controlMotors(0, 0, 0, 0);
        sleep(2);
	arduino.controlMotors(0, 150, 0, 150);
        sleep(2);
	arduino.controlMotors(0, 0, 0, 0);
        sleep(2);
	arduino.controlMotors(1, 255, 0, 255);
        sleep(2);
	arduino.controlMotors(0, 0, 0, 0);
        sleep(2);
	arduino.controlMotors(0, 150, 1, 150);
        sleep(2);
	arduino.controlMotors(0, 0, 0, 0);
        sleep(2);
   }    
    return 0;
}
