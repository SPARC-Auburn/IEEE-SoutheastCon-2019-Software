import rospy
import rosgraph_msgs.msg
import time
rospy.init_node("NTP20")
pub = rospy.Publisher('clock', rosgraph_msgs.msg.Clock, queue_size=10)
msg = rosgraph_msgs.msg.Clock()
while(1):
    msg.clock = rospy.Time.from_sec(time.time())
        
    pub.publish(msg)
    time.sleep(0.001)
