rosrun tf2_ros static_transform_publisher 0.06 0 0 1.570796327 0 0 base_footprint base_imu_link &
rosrun tf2_ros static_transform_publisher -0.06 0 0 0 0 0 base_footprint odom_footprint  &
roslaunch odometry_publisher odometry_publisher.launch &
python ieee-2019-electrical-software/Main-Program-2/odom.py &
#roslaunch ~/launches/razor-pub.launch &
roslaunch ~/launches/ekf_template.launch &
