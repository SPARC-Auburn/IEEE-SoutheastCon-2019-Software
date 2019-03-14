## Setting up for the first time
### Setup ROS Workspace
```
cd ieee-2019-electrical-software/Main-Program-2
catkin_make
. ~/ieee-2019-electrical-software/Main-Program-2
```
> You may have to delete the build and devel directories if they exist
### Create New Package: [Package Tutorial](http://wiki.ros.org/ROS/Tutorials/CreatingPackage)
* Initialize New Package with name "package_name" and corresponding dependencies
```
cd ~/ieee-2019-electrical-software/Main-Program-2/src
catkin_create_pkg package_name std_msgs rospy roscpp
```
* Add desired C++ files to package under package_name/src.  File names cannot be the same across packages.  Add the following lines to CMakeLists.txt in the package for each C++ file like file-name.cpp.
```
add_executable(file-name src/file-name.cpp)
target_link_libraries(file-name ${catkin_LIBRARIES})
add_dependencies(file-name pacakge_name_generate_messages_cpp)
```
* Run the following commands to build the package
```
cd ~/ieee-2019-electrical-software/Main-Program-2/
catkin_make
source ~/ieee-2019-electrical-software/Main-Program-2/devel/setup.bash
```
### Adding source to .bashrc
* Open .bashrc
```
cd ~
nano .bashrc
```
* Add the following line
```
source ~/ieee-2019-electrical-software/Main-Program-2/devel/setup.bash
```
### Running Package: [Subscribing Tutorial](http://wiki.ros.org/ROS/Tutorials/ExaminingPublisherSubscriber)
* In separate terminal session run:
```
roscore
```
* In the other terminal run:
```
cd ~/ieee-2019-electrical-software/Main-Program-2/
source ~/ieee-2019-electrical-software/Main-Program-2/devel/setup.bash
rosrun package_name file_name
rosrun package_name file_name2
```

### Run Individual nodes
```
rosrun main_node main
rosrun opencv_node vision_talker
```

### Run Launch File
```
roslaunch main_node main.launch
```

## Debug Tools
### rqt_graph
```
rosrun rqt_graph rqt_graph
```
### rostopic examples
```
rostopic echo [topic]
rostopic echo /turtle1/cmd_vel
rostopic list -v
rostopic type [topic]
rostopic type /turtle1/cmd_vel
```
### rostopic refresh rate
```
rostopic hz [topic]
rostopic hz /turtle1/cmd_vel
```
### rosmsg examples
```
rosmsg show [msg]
rosmsg show geometry_msgs/Twist
```
### rqt_plot
```
rosrun rqt_graph rqt_graph
```
### console logger
Run the following 2 lines in seperate terminals before running launch file
```
rosrun rqt_console rqt_console
rosrun rqt_logger_level rqt_logger_level
```

## Vision Messages
### Stucture
* x_position (uint32): position in pixels on screen
* y_position (uint32): position in pixels on screen
* width (uint32): width of object
* height (uint32): height of object
* distance (float): approximate distance in meters to object
* color_index (uint8): color index of object [Red(0), Blue(1), Yellow(2), Green(3)]
* object_type (uint8): type of object detected [Debris(0), Corner(1), CenterFace(2), Unknown(3)]
