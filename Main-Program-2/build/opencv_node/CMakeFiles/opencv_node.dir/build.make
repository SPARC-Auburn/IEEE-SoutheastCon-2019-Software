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
include opencv_node/CMakeFiles/opencv_node.dir/depend.make

# Include the progress variables for this target.
include opencv_node/CMakeFiles/opencv_node.dir/progress.make

# Include the compile flags for this target's objects.
include opencv_node/CMakeFiles/opencv_node.dir/flags.make

opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o: opencv_node/CMakeFiles/opencv_node.dir/flags.make
opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o: /home/pi/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/src/vision_talker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/ieee-2019-electrical-software/Main-Program-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o -c /home/pi/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/src/vision_talker.cpp

opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_node.dir/src/vision_talker.cpp.i"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/src/vision_talker.cpp > CMakeFiles/opencv_node.dir/src/vision_talker.cpp.i

opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_node.dir/src/vision_talker.cpp.s"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/ieee-2019-electrical-software/Main-Program-2/src/opencv_node/src/vision_talker.cpp -o CMakeFiles/opencv_node.dir/src/vision_talker.cpp.s

opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.requires:

.PHONY : opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.requires

opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.provides: opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.requires
	$(MAKE) -f opencv_node/CMakeFiles/opencv_node.dir/build.make opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.provides.build
.PHONY : opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.provides

opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.provides.build: opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o


# Object files for target opencv_node
opencv_node_OBJECTS = \
"CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o"

# External object files for target opencv_node
opencv_node_EXTERNAL_OBJECTS =

/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: opencv_node/CMakeFiles/opencv_node.dir/build.make
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/libroscpp.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_filesystem.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_signals.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/librosconsole.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/liblog4cxx.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_regex.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/librostime.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/ros/kinetic/lib/libcpp_common.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_system.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_thread.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_chrono.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_date_time.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libboost_atomic.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libpthread.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/lib/arm-linux-gnueabihf/libconsole_bridge.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/vc/lib/libmmal_core.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/vc/lib/libmmal_util.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /opt/vc/lib/libmmal.so
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_dnn.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_ml.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_objdetect.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_shape.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_stitching.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_superres.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_videostab.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_calib3d.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_features2d.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_flann.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_highgui.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_photo.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_video.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_videoio.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_imgcodecs.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_imgproc.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: /usr/local/lib/libopencv_core.so.3.3.1
/home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so: opencv_node/CMakeFiles/opencv_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/ieee-2019-electrical-software/Main-Program-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so"
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
opencv_node/CMakeFiles/opencv_node.dir/build: /home/pi/ieee-2019-electrical-software/Main-Program-2/devel/lib/libopencv_node.so

.PHONY : opencv_node/CMakeFiles/opencv_node.dir/build

opencv_node/CMakeFiles/opencv_node.dir/requires: opencv_node/CMakeFiles/opencv_node.dir/src/vision_talker.cpp.o.requires

.PHONY : opencv_node/CMakeFiles/opencv_node.dir/requires

opencv_node/CMakeFiles/opencv_node.dir/clean:
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node && $(CMAKE_COMMAND) -P CMakeFiles/opencv_node.dir/cmake_clean.cmake
.PHONY : opencv_node/CMakeFiles/opencv_node.dir/clean

opencv_node/CMakeFiles/opencv_node.dir/depend:
	cd /home/pi/ieee-2019-electrical-software/Main-Program-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/ieee-2019-electrical-software/Main-Program-2/src /home/pi/ieee-2019-electrical-software/Main-Program-2/src/opencv_node /home/pi/ieee-2019-electrical-software/Main-Program-2/build /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node /home/pi/ieee-2019-electrical-software/Main-Program-2/build/opencv_node/CMakeFiles/opencv_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : opencv_node/CMakeFiles/opencv_node.dir/depend

