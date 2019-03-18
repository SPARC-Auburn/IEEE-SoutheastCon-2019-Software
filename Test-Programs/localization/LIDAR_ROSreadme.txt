How to start the LIDAR in ROS:

*This is assuming ROS has been installed and configued. The ROS tutorial's for configuring workspace and setting up catkin has been followed and the LIDAR 
ROS Manual has been followed.

1. $cd ~/catkin_ws
2.$source devel/setup.bash
3.$roscd ydlidar/startup
4.$sudo chmod 0777 *
5. UNPLUG & REPLUG LIDAR into pi
6.$roscd ydlidar/launch
7.$roslaunch ydlidar lidar_view.launch
8.RVIZ should start.
9. Crtl c to close