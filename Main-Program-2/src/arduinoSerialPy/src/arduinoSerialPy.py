import serial
import rospy
from std_msgs.msg import Float32,Int16,String
import struct
ser = serial.Serial('/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0"',38400)
rate = rospy.Rate(40)

rmotor = 0
lmotor = 0
readRmotor = 0
readLmotor = 0

flagPos = 0
gatePos = 0

readFlag = 0
readGate = 0




def callback1(rmotorVal):
    rmotor = int(rmotorVal)
    readRmotor = 1

def callback2(lmotorVal):
    lmotor = int(lmotorVal)
    readLmotor = 1
def callback3(fP):
    flagPos = fP
    readFlag = 1
def callback4(gP):
    gatePos = gP
    readGate = 1
clrbut = 0


while not rospy.is_shutdown():
    if(ser.in_waiting >= 40):
        print(ser.read(40))
    rospy.init_node('arduinoSerialPy')
    rospy.Subscriber("rmotor_cmd",Float32,callback1) 
    rospy.Subscriber("lmotor_cmd",Float32,callback2)

    rospy.Subscriber("flag_cmd",Int16,callback3)
    rospy.Subscriber("gate_cmd",Int16,callback4)
    x= "hello"
    x.ljust(32)
    checkSum = struct.pack('38b','<',lmotor,rmotor,gatePos,flagPos,lmotor + rmotor + gatePos + flagPos + clrbut + 1,clrbut,x, ">")
    print(checkSum) 
    #values = "<" + str(lmotor) + str(rmotor) + str(gatePos) + str(flagPos) + "00" + str(checkSum) + "Read Python" + "<" #00 = checksum and clearState
    ser.write(checkSum)
    rospy.spinOnce()    
