## Setting up for the first time
### Setup ROS Workspace
```
cd ieee-2019-electrical-software/Main-Program-2
catkin_make
. ~/ieee-2019-electrical-software/Main-Program-2
```
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
. ~/ieee-2019-electrical-software/Main-Program-2/devel/setup.bash
```
### Running Package: [Subscribing Tutorial](http://wiki.ros.org/ROS/Tutorials/ExaminingPublisherSubscriber)
* In separate terminal session run:
```
roscore
```
* In the other terminal run:
```
cd ~/ieee-2019-electrical-software/Main-Program-2/
. ~/ieee-2019-electrical-software/Main-Program-2/devel/setup.bash
rosrun package_name file_name
rosrun package_name file_name2
```

### Current Setup: Run these commands in separate terminals
```
rosrun main_node main
rosrun opencv_node vision_talker
rosrun beginner_tutorials talker
```