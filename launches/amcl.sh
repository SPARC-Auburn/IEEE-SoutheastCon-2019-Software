rosparam set use_sim_time true
python ../Main-Program-2/cock.py&
rosrun arduino_talker arduino_talker&
roslaunch odometry_publisher odometry_publisher.launch &
python ../Main-Program-2/odom.py &
#roslaunch razor-pub.launch &
roslaunch ydlidar lidar.launch &
sleep 5
roslaunch ekf_template.launch &
rosrun map_server map_server ~/mymap/practice3.yaml &
sleep 5
roslaunch test.launch &
roslaunch ieee_2dnav  move_base.launch &
sleep 10
roslaunch amcl_diff.launch &
sleep 10
#rosrun opencv_node vision_talker
rosrun main_node main &


