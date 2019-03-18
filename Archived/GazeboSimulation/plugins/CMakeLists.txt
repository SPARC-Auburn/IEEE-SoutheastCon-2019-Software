cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

add_subdirectory(msgs)

add_library(debris SHARED debris.cc)
add_library(scoreEngine SHARED scoreEngine.cc)
add_library(skidSteer SHARED skidSteer.cc)
target_link_libraries(debris scoreinfomsgs ${GAZEBO_LIBRARIES})
target_link_libraries(scoreEngine scoreinfomsgs ${GAZEBO_LIBRARIES})
target_link_libraries(skidSteer scoreinfomsgs ${GAZEBO_LIBRARIES})