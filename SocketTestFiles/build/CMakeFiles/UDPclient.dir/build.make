# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /space/mjb20/socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /space/mjb20/socket/build

# Include any dependencies generated for this target.
include CMakeFiles/UDPclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UDPclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UDPclient.dir/flags.make

CMakeFiles/UDPclient.dir/UDPclient.cpp.o: CMakeFiles/UDPclient.dir/flags.make
CMakeFiles/UDPclient.dir/UDPclient.cpp.o: ../UDPclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/space/mjb20/socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UDPclient.dir/UDPclient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDPclient.dir/UDPclient.cpp.o -c /space/mjb20/socket/UDPclient.cpp

CMakeFiles/UDPclient.dir/UDPclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDPclient.dir/UDPclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /space/mjb20/socket/UDPclient.cpp > CMakeFiles/UDPclient.dir/UDPclient.cpp.i

CMakeFiles/UDPclient.dir/UDPclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDPclient.dir/UDPclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /space/mjb20/socket/UDPclient.cpp -o CMakeFiles/UDPclient.dir/UDPclient.cpp.s

# Object files for target UDPclient
UDPclient_OBJECTS = \
"CMakeFiles/UDPclient.dir/UDPclient.cpp.o"

# External object files for target UDPclient
UDPclient_EXTERNAL_OBJECTS =

UDPclient: CMakeFiles/UDPclient.dir/UDPclient.cpp.o
UDPclient: CMakeFiles/UDPclient.dir/build.make
UDPclient: CMakeFiles/UDPclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/space/mjb20/socket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UDPclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UDPclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UDPclient.dir/build: UDPclient

.PHONY : CMakeFiles/UDPclient.dir/build

CMakeFiles/UDPclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UDPclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UDPclient.dir/clean

CMakeFiles/UDPclient.dir/depend:
	cd /space/mjb20/socket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /space/mjb20/socket /space/mjb20/socket /space/mjb20/socket/build /space/mjb20/socket/build /space/mjb20/socket/build/CMakeFiles/UDPclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UDPclient.dir/depend

