roslaunch odometry_publisher odometry_publisher.launch &
python ieee-2019-electrical-software/Main-Program-2/odom.py &
roslaunch ~/launches/razor-pub.launch &
roslaunch ydlidar lidar.launch &
roslaunch ~/launches/ekf_template.launch &
rosrun map_server map_server ~/mymap/garage.yaml &
rosrun main_node main &
sleep 5
roslaunch launches/test.launch &
#roslaunch ieee_2dnav  move_base.launch &
sleep 10
roslaunch launches/amcl_diff.launch &
#sleep 10
#roslaunch ieee_2dnav move_base.launch
#roslaunch launches/ekf_template2.launch &


