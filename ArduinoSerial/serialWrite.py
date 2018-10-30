import time
import serial

ser = serial.Serial(
    port='/dev/ttyACM0',
    baudrate = 9600,
    parity = serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1)

counter1 = 256
counter2 = 256
d1 = 1
d2 = 1
string = ""
while 1:
    string = str(d1)+","+str(d2)+","+str(counter1)+","+str(counter2)
    ser.write(str.encode(string))
    print(string)
    time.sleep(2)
    counter1-=16
    counter2 = counter1
    if (counter1==0):
        counter1 = 256
        counter2 = 256
        if (d1==1):
            d1 = 0
            d2 = 0
        else:
            d1 = 1
            d2 = 1

#    if (d1 == 1):
#        d1 = 0
#        d2 = 0
        
#    else:
#        d1 = 1
#        d2 = 1
    string = ""
    
