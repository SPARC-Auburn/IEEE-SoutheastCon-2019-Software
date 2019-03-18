# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build

# Include any dependencies generated for this target.
include utils/CMakeFiles/raspicam_cv_test.dir/depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/raspicam_cv_test.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/raspicam_cv_test.dir/flags.make

utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o: utils/CMakeFiles/raspicam_cv_test.dir/flags.make
utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o: ../utils/raspicam_cv_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o"
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o -c /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/utils/raspicam_cv_test.cpp

utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.i"
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/utils/raspicam_cv_test.cpp > CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.i

utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.s"
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/utils/raspicam_cv_test.cpp -o CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.s

utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.requires:

.PHONY : utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.requires

utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.provides: utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.requires
	$(MAKE) -f utils/CMakeFiles/raspicam_cv_test.dir/build.make utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.provides.build
.PHONY : utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.provides

utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.provides.build: utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o


# Object files for target raspicam_cv_test
raspicam_cv_test_OBJECTS = \
"CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o"

# External object files for target raspicam_cv_test
raspicam_cv_test_EXTERNAL_OBJECTS =

utils/raspicam_cv_test: utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o
utils/raspicam_cv_test: utils/CMakeFiles/raspicam_cv_test.dir/build.make
utils/raspicam_cv_test: src/libraspicam.so.0.1.2
utils/raspicam_cv_test: src/libraspicam_cv.so
utils/raspicam_cv_test: /opt/vc/lib/libmmal_core.so
utils/raspicam_cv_test: /opt/vc/lib/libmmal_util.so
utils/raspicam_cv_test: /opt/vc/lib/libmmal.so
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_stitching3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_superres3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_videostab3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_aruco3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_bgsegm3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_bioinspired3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_ccalib3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_cvv3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_dpm3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_face3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_photo3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_fuzzy3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_hdf3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_img_hash3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_line_descriptor3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_optflow3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_reg3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_rgbd3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_saliency3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_stereo3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_structured_light3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_viz3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_phase_unwrapping3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_surface_matching3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_tracking3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_datasets3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_plot3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_text3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_dnn3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_xfeatures2d3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_ml3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_shape3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_video3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_ximgproc3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_calib3d3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_features2d3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_flann3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_highgui3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_videoio3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_xobjdetect3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_imgcodecs3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_objdetect3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_xphoto3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_imgproc3.so.3.3.1
utils/raspicam_cv_test: /opt/ros/kinetic/lib/arm-linux-gnueabihf/libopencv_core3.so.3.3.1
utils/raspicam_cv_test: utils/CMakeFiles/raspicam_cv_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable raspicam_cv_test"
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raspicam_cv_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/raspicam_cv_test.dir/build: utils/raspicam_cv_test

.PHONY : utils/CMakeFiles/raspicam_cv_test.dir/build

utils/CMakeFiles/raspicam_cv_test.dir/requires: utils/CMakeFiles/raspicam_cv_test.dir/raspicam_cv_test.cpp.o.requires

.PHONY : utils/CMakeFiles/raspicam_cv_test.dir/requires

utils/CMakeFiles/raspicam_cv_test.dir/clean:
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/raspicam_cv_test.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/raspicam_cv_test.dir/clean

utils/CMakeFiles/raspicam_cv_test.dir/depend:
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/utils /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/raspicam/build/utils/CMakeFiles/raspicam_cv_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/raspicam_cv_test.dir/depend

