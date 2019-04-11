cmake_minimum_required(VERSION 2.8.3)
project(opencv_node)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

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
message(${OpenCV_LIBRARIES})
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_library(opencv_node src/vision_talker.cpp)
target_link_libraries(opencv_node ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(opencv_node opencv_node_generate_messages_cpp)

add_executable(vision_talker src/vision_talker.cpp src/Vision3D.cpp)
target_link_libraries(vision_talker ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(vision_talker opencv_node_generate_messages_cpp)
