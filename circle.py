import roslib
import rospy
import math
import tf
import geometry_msgs.msg
lp = 0
def callback(data):
    lp = data
if __name__ == '__main__':
    rospy.init_node('fast')
    tl = tf.TransformListener()
    twist = rospy.Publisher('cmd_vel', geometry_msgs.msg.Twist,queue_size=1)
    sub = rospy.Subscriber('amcl_pose', geometry_msgs.msg.PoseWithCovarianceStamped,callback)
    rate = rospy.Rate(60.0)
    state = 0
    while not rospy.is_shutdown():
	rate.sleep()

	if lp == 0:
		continue
	else:
		print(lp)
'''        try:
            z = math.atan2(lp.pose.orientation[2], lp.pose.orientation[3])
            distance = math.sqrt(lp.pose.pose[0]*lp.pose.pose[0]+lp.pose.pose[1]*lp.pose.pose[1])

            if state == 0:
                if distance > 0.6:
                    cmd = geometry_msgs.msg.Twist()
                    cmd.linear.x = 1
                    cmd.angular.z = 0.5
                    twist.publish(cmd)
                else:
                    state+=1
            if state == 1:
                cmd = geometry_msgs.msg.Twist()
                cmd.linear.x = 1
                theta = math.atan2(lp.pose.pose[1],lp.pose.pose[0])+math.pi/2
                print(theta)
                cmd.angular.z = -theta*3*distance 
                twist.publish(cmd)
        except Exception as e:
            print(e)
            #pass
   '''     
