# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/lukasz/Pulpit/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/lukasz/Pulpit/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lukasz/CLionProjects/TIN_P2P

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TIN_P2P.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TIN_P2P.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TIN_P2P.dir/flags.make

CMakeFiles/TIN_P2P.dir/main.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TIN_P2P.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/main.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/main.cpp

CMakeFiles/TIN_P2P.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/main.cpp > CMakeFiles/TIN_P2P.dir/main.cpp.i

CMakeFiles/TIN_P2P.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/main.cpp -o CMakeFiles/TIN_P2P.dir/main.cpp.s

CMakeFiles/TIN_P2P.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/main.cpp.o.requires

CMakeFiles/TIN_P2P.dir/main.cpp.o.provides: CMakeFiles/TIN_P2P.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/main.cpp.o.provides

CMakeFiles/TIN_P2P.dir/main.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/main.cpp.o


CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o: ../Dependencies/JsonCpp/jsoncpp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/Dependencies/JsonCpp/jsoncpp.cpp

CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/Dependencies/JsonCpp/jsoncpp.cpp > CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.i

CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/Dependencies/JsonCpp/jsoncpp.cpp -o CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.s

CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.requires

CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.provides: CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.provides

CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o


CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o: ../JsonCreator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/JsonCreator.cpp

CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/JsonCreator.cpp > CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.i

CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/JsonCreator.cpp -o CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.s

CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.requires

CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.provides: CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.provides

CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o


CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o: ../ServerThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/ServerThread.cpp

CMakeFiles/TIN_P2P.dir/ServerThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/ServerThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/ServerThread.cpp > CMakeFiles/TIN_P2P.dir/ServerThread.cpp.i

CMakeFiles/TIN_P2P.dir/ServerThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/ServerThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/ServerThread.cpp -o CMakeFiles/TIN_P2P.dir/ServerThread.cpp.s

CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.requires

CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.provides: CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.provides

CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o


CMakeFiles/TIN_P2P.dir/Socket.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/Socket.cpp.o: ../Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TIN_P2P.dir/Socket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/Socket.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/Socket.cpp

CMakeFiles/TIN_P2P.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/Socket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/Socket.cpp > CMakeFiles/TIN_P2P.dir/Socket.cpp.i

CMakeFiles/TIN_P2P.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/Socket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/Socket.cpp -o CMakeFiles/TIN_P2P.dir/Socket.cpp.s

CMakeFiles/TIN_P2P.dir/Socket.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/Socket.cpp.o.requires

CMakeFiles/TIN_P2P.dir/Socket.cpp.o.provides: CMakeFiles/TIN_P2P.dir/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/Socket.cpp.o.provides

CMakeFiles/TIN_P2P.dir/Socket.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/Socket.cpp.o


CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o: ../UDPAdapter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/UDPAdapter.cpp

CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/UDPAdapter.cpp > CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.i

CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/UDPAdapter.cpp -o CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.s

CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.requires

CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.provides: CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.provides

CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o


# Object files for target TIN_P2P
TIN_P2P_OBJECTS = \
"CMakeFiles/TIN_P2P.dir/main.cpp.o" \
"CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o" \
"CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o" \
"CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o" \
"CMakeFiles/TIN_P2P.dir/Socket.cpp.o" \
"CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o"

# External object files for target TIN_P2P
TIN_P2P_EXTERNAL_OBJECTS =

TIN_P2P: CMakeFiles/TIN_P2P.dir/main.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/Socket.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/build.make
TIN_P2P: CMakeFiles/TIN_P2P.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable TIN_P2P"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TIN_P2P.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TIN_P2P.dir/build: TIN_P2P

.PHONY : CMakeFiles/TIN_P2P.dir/build

CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/main.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/Socket.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o.requires

.PHONY : CMakeFiles/TIN_P2P.dir/requires

CMakeFiles/TIN_P2P.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TIN_P2P.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TIN_P2P.dir/clean

CMakeFiles/TIN_P2P.dir/depend:
	cd /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukasz/CLionProjects/TIN_P2P /home/lukasz/CLionProjects/TIN_P2P /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles/TIN_P2P.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TIN_P2P.dir/depend

