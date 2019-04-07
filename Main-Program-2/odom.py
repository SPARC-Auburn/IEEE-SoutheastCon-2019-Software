import serial
import rospy
from std_msgs.msg import Int32
import struct
ser = serial.Serial('/dev/serial0',115200)
rospy.init_node('odomTalker')
rate = rospy.Rate(100)
a = rospy.Publisher("lwheel",Int32,queue_size=10)
b = rospy.Publisher("rwheel",Int32,queue_size=10)
while not rospy.is_shutdown():
	#input()
	if ser.in_waiting >= 50:
		ser.read(ser.in_waiting-50)
		x = str(ser.read(50))
#		print(x)
		x = x.split("<")[-2]
		x = x.replace(">","")
		x = x.split(",")
#		print(-int(x[0]),int(x[1]))
		a.publish(-int(x[0]))
		b.publish(int(x[1]))
		rate.sleep()
