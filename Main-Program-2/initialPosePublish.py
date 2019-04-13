import rospy
from geometry_msgs.msg import Pose, PoseWithCovarianceStamped
import struct
def talker():
    while not rospy.is_shutdown(): 
        pub = rospy.Publisher('/initialpose', PoseWithCovarianceStamped, queue_size=10)
        rospy.init_node('talker', anonymous=True)
        rate = rospy.Rate(1) # 10hz

        pose = PoseWithCovarianceStamped()
        pose.header.frame_id = "map"
        pose.pose.pose.position.x=4.5
        pose.pose.pose.position.y=4.5
        pose.pose.pose.position.z=0
        pose.pose.covariance=[1e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1e-3]
        rospy.loginfo(pose)
        pub.publish(pose)
        rospy.spin()
        rate.sleep()
    
talker()
