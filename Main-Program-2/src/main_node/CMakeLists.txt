cmake_minimum_required(VERSION 2.8.3)
project(main_node)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  opencv_node
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

################################################
## Declare ROS messages, services and actions ##
################################################

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES main_node
  CATKIN_DEPENDS roscpp std_msgs opencv_node 
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############

#############
## Testing ##
#############

add_executable(main src/main.cpp src/Arduino-Serial/ArduinoSerial.cpp)

target_link_libraries(main ${catkin_LIBRARIES})
add_dependencies(main main_node_generate_messages_cpp)

add_dependencies(opencv_node ${catkin_EXPORTED_TARGETS})
