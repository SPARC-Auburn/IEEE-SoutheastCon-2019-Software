rosrun tf2_ros static_transform_publisher 0.06 0 0 1.570796327 0 0 base_footprint base_imu_link &
roslaunch ~/launches/test.launch &
python ~/ieee-2019-electrical-software/Main-Program-2/odom.py &
rosrun odometry_publisher odometry_publisher &
roslaunch ~/launches/razor-pub.launch &
roslaunch ~/launches/ekf_template.launch &
roslaunch ~/launches/ekf_template2.launch 
