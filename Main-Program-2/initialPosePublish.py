import rospy
from geometry_msgs.msg import Pose, PoseWithCovarianceStamped
import struct
def talker():
    while not rospy.is_shutdown(): 
        pub = rospy.Publisher('/initialpose', geometry_msgs.msg.PoseWithCovarianceStamped, queue_size=10,latched = True)
        rospy.init_node('talker', anonymous=True)
        rate = rospy.Rate(1) # 10hz

        pose = geometry_msgs.msg.PoseWithCovarianceStamped()
        pose.header.frame_id = "map"
        pose.pose.pose.position.x=0.1143
        pose.pose.pose.position.y=0.1143
        pose.pose.pose.position.z=0
        pose.pose.covariance=[1e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1e-3, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1e-3]
        rospy.loginfo(pose)
        pub.publish(pose)
        rospy.spin()
        rate.sleep()
    