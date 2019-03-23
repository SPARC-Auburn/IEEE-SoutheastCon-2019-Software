cmake_minimum_required(VERSION 2.8.3)
project(opencv_node)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################
## Generate messages in the 'msg' folder
add_message_files(
  FILES
  vision_msg.msg
  object.msg
)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
   opencv_node
)

catkin_package(
  #INCLUDE_DIRS include
  LIBRARIES opencv_node
  CATKIN_DEPENDS roscpp std_msgs message_runtime
  #DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
find_package(OpenCV REQUIRED)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)


add_executable(vision_talker src/vision_talker.cpp)
target_link_libraries(vision_talker ${catkin_LIBRARIES} ${OpenCV_LIBS})
add_dependencies(vision_talker opencv_node_generate_messages_cpp)

add_library(opencv_node src/vision_talker.cpp )
