cmake_minimum_required(VERSION 2.8)
project( BlockDetection )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


find_package( OpenCV REQUIRED )
add_executable( BlockDetection src/main.cpp )
target_link_libraries( BlockDetection ${OpenCV_LIBS} )
