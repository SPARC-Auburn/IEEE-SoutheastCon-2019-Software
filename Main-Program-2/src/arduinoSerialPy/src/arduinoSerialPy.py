import serial
import rospy
from std_msgs.msg import Float32,Int16,String
import struct
#ser = serial.Serial('/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0"',38400)
ser = serial.Serial('/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0',38400)

rmotor = 0
lmotor = 0
flagPos = 0
gatePos = 0



def callback1(rmotorVal):
    rmotor = int(rmotorVal)
def callback2(lmotorVal):
    lmotor = int(lmotorVal)
def callback3(fP):
    flagPos = fP
def callback4(gP):
    gatePos = gP

clrbut = 0
rospy.init_node('arduinoSerialPy')

rate = rospy.Rate(40)
rospy.Subscriber("rmotor_cmd",Float32,callback1) 
rospy.Subscriber("lmotor_cmd",Float32,callback2)

rospy.Subscriber("flag_cmd",Int16,callback3)
rospy.Subscriber("gate_cmd",Int16,callback4)
qq = 0
error = 0
while not rospy.is_shutdown():
    msg = ser.read(ser.in_waiting)
    print(msg)
    x = "hello"+str(qq)
    x = x.ljust(32)

    checkSum = struct.pack('7b',ord('<'),lmotor,rmotor,gatePos,flagPos,clrbut,lmotor + rmotor + gatePos + flagPos + clrbut + 1)
    checkSum += bytes(x) + bytes('>')
    abc = "<" + str(lmotor) + "," + str(rmotor) + "," + str(gatePos) + "," + str(flagPos) + "," + str(clrbut) +"," + x +">"
    print(abc)
    #values = "<" + str(lmotor) + str(rmotor) + str(gatePos) + str(flagPos) + "00" + str(checkSum) + "Read Python" + "<" #00 = checksum and clearState
    ser.write(bytes(abc))
    rate.sleep()
    qq+=1
