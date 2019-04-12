roslaunch odometry_publisher odometry_publisher.launch &
python ../Main-Program-2/odom.py &
#roslaunch razor-pub.launch &
roslaunch ydlidar lidar.launch &
roslaunch ekf_template.launch &
rosrun map_server map_server ~/mymap/garage.yaml &
sleep 5
roslaunch test.launch &
roslaunch ieee_2dnav  move_base.launch &
sleep 10
roslaunch amcl_diff.launch &
rosrun arduino_talker arduino_talker&
sleep 20
rosrun main_node main &


