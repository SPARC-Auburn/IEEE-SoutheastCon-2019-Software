# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/ieee-2019-electrical-software/Main-Program-2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/ieee-2019-electrical-software/Main-Program-2/build

# Include any dependencies generated for this target.
include main_node/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include main_node/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include main_node/CMakeFiles/main.dir/flags.make

main_node/CMakeFiles/main.dir/src/main.cpp.o: main_node/CMakeFiles/main.dir/flags.make
main_node/CMakeFiles/main.dir/src/main.cpp.o: /home/pi/ieee-2019-electrical-software/Main-Program-2/src/main_node/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/ieee-2019-electrical-software/Main-Program-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main_node/CMakeFiles/main.dir/src/main.cpp.o"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.cpp.o -c /home/pi/ieee-2019-electrical-software/Main-Program-2/src/main_node/src/main.cpp

main_node/CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/ieee-2019-electrical-software/Main-Program-2/src/main_node/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

main_node/CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/ieee-2019-electrical-software/Main-Program-2/src/main_node/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

main_node/CMakeFiles/main.dir/src/main.cpp.o.requires:

.PHONY : main_node/CMakeFiles/main.dir/src/main.cpp.o.requires

main_node/CMakeFiles/main.dir/src/main.cpp.o.provides: main_node/CMakeFiles/main.dir/src/main.cpp.o.requires
	$(MAKE) -f main_node/CMakeFiles/main.dir/build.make main_node/CMakeFiles/main.dir/src/main.cpp.o.provides.build
.PHONY : main_node/CMakeFiles/main.dir/src/main.cpp.o.provides

main_node/CMakeFiles/main.dir/src/main.cpp.o.provides.build: main_node/CMakeFiles/main.dir/src/main.cpp.o


# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: main_node/CMakeFiles/main.dir/src/main.cpp.o
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: main_node/CMakeFiles/main.dir/build.make
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/libroscpp.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/librosconsole.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/librostime.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/ros/kinetic/lib/libcpp_common.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_dnn.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_ml.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_objdetect.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_shape.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_stitching.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_superres.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_videostab.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_calib3d.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_features2d.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_flann.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_highgui.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_photo.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_video.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_videoio.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_imgcodecs.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_imgproc.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /usr/local/lib/libopencv_core.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/vc/lib/libmmal_core.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/vc/lib/libmmal_util.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: /opt/vc/lib/libmmal.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main: main_node/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/ieee-2019-electrical-software/Main-Program-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main_node/CMakeFiles/main.dir/build: /home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/main_node/main

.PHONY : main_node/CMakeFiles/main.dir/build

main_node/CMakeFiles/main.dir/requires: main_node/CMakeFiles/main.dir/src/main.cpp.o.requires

.PHONY : main_node/CMakeFiles/main.dir/requires

main_node/CMakeFiles/main.dir/clean:
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : main_node/CMakeFiles/main.dir/clean

main_node/CMakeFiles/main.dir/depend:
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/ieee-2019-electrical-software/Main-Program-2/src /home/pi/ieee-2019-electrical-software/Main-Program-2/src/main_node /home/pi/ieee-2019-electrical-software/Main-Program-2/build /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node /home/pi/ieee-2019-electrical-software/Main-Program-2/build/main_node/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : main_node/CMakeFiles/main.dir/depend

