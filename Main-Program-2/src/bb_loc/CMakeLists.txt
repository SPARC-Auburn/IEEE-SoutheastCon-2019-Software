cmake_minimum_required(VERSION 2.8.3)
project(bb_al)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

find_package(catkin REQUIRED COMPONENTS geometry_msgs sensor_msgs roscpp tf)

catkin_package()
find_package(Boost REQUIRED)

IF(Boost_FOUND)
  INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
  LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)
find_package(OpenCV REQUIRED)

include_directories(${catkin_INCLUDE_DIRS})
# Build the executable
add_executable(bb_al src/main.cpp)
# Add a build order dependency on nav_msgs
# This ensures that nav_msgs' msg headers are built before your executable
if(sensor_msgs_EXPORTED_TARGETS)
  add_dependencies(bb_al ${sensor_msgs_EXPORTED_TARGETS})
endif()
if(geometry_msgs_EXPORTED_TARGETS)
  add_dependencies(bb_al ${geometry_msgs_EXPORTED_TARGETS})
endif()

# Link against the catkin libraries
target_link_libraries(bb_al ${catkin_LIBRARIES} ${Boost_LIBRARIES} ${OpenCV_LIBS})

# Install the executable
install(TARGETS bb_al
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})




