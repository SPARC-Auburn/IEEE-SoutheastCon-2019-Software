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
CMAKE_SOURCE_DIR = /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/build

# Utility rule file for opencv_node_gencpp.

# Include the progress variables for this target.
include opencv_node/CMakeFiles/opencv_node_gencpp.dir/progress.make

opencv_node_gencpp: opencv_node/CMakeFiles/opencv_node_gencpp.dir/build.make

.PHONY : opencv_node_gencpp

# Rule to build all files generated by this target.
opencv_node/CMakeFiles/opencv_node_gencpp.dir/build: opencv_node_gencpp

.PHONY : opencv_node/CMakeFiles/opencv_node_gencpp.dir/build

opencv_node/CMakeFiles/opencv_node_gencpp.dir/clean:
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/build/opencv_node && $(CMAKE_COMMAND) -P CMakeFiles/opencv_node_gencpp.dir/cmake_clean.cmake
.PHONY : opencv_node/CMakeFiles/opencv_node_gencpp.dir/clean

opencv_node/CMakeFiles/opencv_node_gencpp.dir/depend:
	cd /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/src /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/src/opencv_node /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/build /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/build/opencv_node /home/ubuntu/ieee-2019-electrical-software/Main-Program-2/build/opencv_node/CMakeFiles/opencv_node_gencpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : opencv_node/CMakeFiles/opencv_node_gencpp.dir/depend

