cmake_minimum_required(VERSION 2.8.3)
project(arduino_talker)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

find_package(catkin REQUIRED COMPONENTS move_base_msgs std_msgs roscpp tf)

catkin_package()

include_directories(${catkin_INCLUDE_DIRS})
# Build the executable
add_executable(arduino_talker src/arduino_talker.cpp src/Arduino-Serial/ArduinoSerial.cpp)
# Add a build order dependency on nav_msgs
# This ensures that nav_msgs' msg headers are built before your executable
if(move_base_msgs_EXPORTED_TARGETS)
  add_dependencies(arduino_talker ${move_base_msgs_EXPORTED_TARGETS})
endif()
if(std_msgs_EXPORTED_TARGETS)
  add_dependencies(arduino_talker ${std_msgs_EXPORTED_TARGETS})
endif()

# Link against the catkin libraries
target_link_libraries(arduino_talker ${catkin_LIBRARIES})

# Install the executable
install(TARGETS arduino_talker
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
