cmake_minimum_required(VERSION 2.8)
project(MainProgram)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF )

find_package( OpenCV REQUIRED )

set(raspicam_DIR "raspicam/build")
find_package(raspicam REQUIRED)

add_executable( MainProgram main.cpp )

target_link_libraries( MainProgram ${OpenCV_LIBS} ${raspicam_CV_LIBS})
