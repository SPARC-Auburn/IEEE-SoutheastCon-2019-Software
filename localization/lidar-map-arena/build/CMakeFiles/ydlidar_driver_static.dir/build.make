# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build

# Include any dependencies generated for this target.
include CMakeFiles/ydlidar_driver_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ydlidar_driver_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ydlidar_driver_static.dir/flags.make

CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/CYdLidar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/CYdLidar.cpp

CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/CYdLidar.cpp > CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.i

CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/CYdLidar.cpp -o CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.s

CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o


CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/line_feature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/line_feature.cpp

CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/line_feature.cpp > CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.i

CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/line_feature.cpp -o CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.s

CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o


CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/serial.cpp

CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/serial.cpp > CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.i

CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/serial.cpp -o CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.s

CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o


CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/ydlidar_driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/ydlidar_driver.cpp

CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/ydlidar_driver.cpp > CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.i

CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/ydlidar_driver.cpp -o CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.s

CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o


CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/lock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o   -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/lock.c

CMakeFiles/ydlidar_driver_static.dir/src/lock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ydlidar_driver_static.dir/src/lock.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/lock.c > CMakeFiles/ydlidar_driver_static.dir/src/lock.c.i

CMakeFiles/ydlidar_driver_static.dir/src/lock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ydlidar_driver_static.dir/src/lock.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/lock.c -o CMakeFiles/ydlidar_driver_static.dir/src/lock.c.s

CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o


CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_serial.cpp

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_serial.cpp > CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.i

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_serial.cpp -o CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.s

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o


CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o: CMakeFiles/ydlidar_driver_static.dir/flags.make
CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o -c /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_timer.cpp

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_timer.cpp > CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.i

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/src/impl/unix/unix_timer.cpp -o CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.s

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.requires:

.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.requires

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.provides: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ydlidar_driver_static.dir/build.make CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.provides.build
.PHONY : CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.provides

CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.provides.build: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o


# Object files for target ydlidar_driver_static
ydlidar_driver_static_OBJECTS = \
"CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o" \
"CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o" \
"CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o" \
"CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o" \
"CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o" \
"CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o" \
"CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o"

# External object files for target ydlidar_driver_static
ydlidar_driver_static_EXTERNAL_OBJECTS =

/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/build.make
/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a: CMakeFiles/ydlidar_driver_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ydlidar_driver_static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ydlidar_driver_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ydlidar_driver_static.dir/build: /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk/lib/libydlidar_driver.a

.PHONY : CMakeFiles/ydlidar_driver_static.dir/build

CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/CYdLidar.cpp.o.requires
CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/line_feature.cpp.o.requires
CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/serial.cpp.o.requires
CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/ydlidar_driver.cpp.o.requires
CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/lock.c.o.requires
CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_serial.cpp.o.requires
CMakeFiles/ydlidar_driver_static.dir/requires: CMakeFiles/ydlidar_driver_static.dir/src/impl/unix/unix_timer.cpp.o.requires

.PHONY : CMakeFiles/ydlidar_driver_static.dir/requires

CMakeFiles/ydlidar_driver_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ydlidar_driver_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ydlidar_driver_static.dir/clean

CMakeFiles/ydlidar_driver_static.dir/depend:
	cd /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/sdk /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build /home/matthew/IEEE-SoutheastCon-2019/Electrical-Software/localization/lidar-map-arena/build/CMakeFiles/ydlidar_driver_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ydlidar_driver_static.dir/depend

