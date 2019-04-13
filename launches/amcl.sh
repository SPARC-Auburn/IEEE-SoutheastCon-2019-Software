#rosrun arduino_talker arduino_talker&
#roslaunch odometry_publisher odometry_publisher.launch &
#python ../Main-Program-2/odom.py &
#roslaunch razor-pub.launch &
#roslaunch ydlidar lidar.launch &
#roslaunch ekf_template.launch &
#rosrun map_server map_server ~/mymap/practice.yaml &
#roslaunch test.launch &
roslaunch ieee_2dnav  move_base.launch &
#roslaunch amcl_diff.launch &
rosrun main_node main &


