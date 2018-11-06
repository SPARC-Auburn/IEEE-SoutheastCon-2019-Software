#include "Arduino-Serial/ArduinoSerial.h"
#include <unistd.h>

int main (){    
    serialPort arduino (serialPort::typicalPortName);
    while (1){
        arduino.controlMotors(1, 100, 1, 100);
        sleep(3);
        arduino.controlMotors(0, 0, 0, 0);
        sleep(3);
    }    
    return 0;
}
