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


CMakeFiles/TIN_P2P.dir/Message.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/Message.cpp.o: ../Message.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TIN_P2P.dir/Message.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/Message.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/Message.cpp

CMakeFiles/TIN_P2P.dir/Message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/Message.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/Message.cpp > CMakeFiles/TIN_P2P.dir/Message.cpp.i

CMakeFiles/TIN_P2P.dir/Message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/Message.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/Message.cpp -o CMakeFiles/TIN_P2P.dir/Message.cpp.s

CMakeFiles/TIN_P2P.dir/Message.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/Message.cpp.o.requires

CMakeFiles/TIN_P2P.dir/Message.cpp.o.provides: CMakeFiles/TIN_P2P.dir/Message.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/Message.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/Message.cpp.o.provides

CMakeFiles/TIN_P2P.dir/Message.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/Message.cpp.o


CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o: ../MessageContainer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/MessageContainer.cpp

CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/MessageContainer.cpp > CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.i

CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/MessageContainer.cpp -o CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.s

CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.requires

CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.provides: CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.provides

CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o


CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o: ../MessageHello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/MessageHello.cpp

CMakeFiles/TIN_P2P.dir/MessageHello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/MessageHello.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/MessageHello.cpp > CMakeFiles/TIN_P2P.dir/MessageHello.cpp.i

CMakeFiles/TIN_P2P.dir/MessageHello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/MessageHello.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/MessageHello.cpp -o CMakeFiles/TIN_P2P.dir/MessageHello.cpp.s

CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.requires

CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.provides: CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.provides

CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o


CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o: ../SocketCreator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/SocketCreator.cpp

CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/SocketCreator.cpp > CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.i

CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/SocketCreator.cpp -o CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.s

CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.requires

CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.provides: CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.provides

CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o


CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o: ../JsonParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/JsonParser.cpp

CMakeFiles/TIN_P2P.dir/JsonParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/JsonParser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/JsonParser.cpp > CMakeFiles/TIN_P2P.dir/JsonParser.cpp.i

CMakeFiles/TIN_P2P.dir/JsonParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/JsonParser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/JsonParser.cpp -o CMakeFiles/TIN_P2P.dir/JsonParser.cpp.s

CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.requires

CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.provides: CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.provides

CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o


CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o: ../WcisloSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/WcisloSocket.cpp

CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/WcisloSocket.cpp > CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.i

CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/WcisloSocket.cpp -o CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.s

CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.requires

CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.provides: CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.provides

CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o


CMakeFiles/TIN_P2P.dir/File.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/File.cpp.o: ../File.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/TIN_P2P.dir/File.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/File.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/File.cpp

CMakeFiles/TIN_P2P.dir/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/File.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/File.cpp > CMakeFiles/TIN_P2P.dir/File.cpp.i

CMakeFiles/TIN_P2P.dir/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/File.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/File.cpp -o CMakeFiles/TIN_P2P.dir/File.cpp.s

CMakeFiles/TIN_P2P.dir/File.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/File.cpp.o.requires

CMakeFiles/TIN_P2P.dir/File.cpp.o.provides: CMakeFiles/TIN_P2P.dir/File.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/File.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/File.cpp.o.provides

CMakeFiles/TIN_P2P.dir/File.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/File.cpp.o


CMakeFiles/TIN_P2P.dir/FileManager.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/FileManager.cpp.o: ../FileManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/TIN_P2P.dir/FileManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/FileManager.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/FileManager.cpp

CMakeFiles/TIN_P2P.dir/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/FileManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/FileManager.cpp > CMakeFiles/TIN_P2P.dir/FileManager.cpp.i

CMakeFiles/TIN_P2P.dir/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/FileManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/FileManager.cpp -o CMakeFiles/TIN_P2P.dir/FileManager.cpp.s

CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.requires

CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.provides: CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.provides

CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/FileManager.cpp.o


CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o: ../ServerInterface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/ServerInterface.cpp

CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/ServerInterface.cpp > CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.i

CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/ServerInterface.cpp -o CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.s

CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.requires

CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.provides: CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.provides

CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o


CMakeFiles/TIN_P2P.dir/Constants.cpp.o: CMakeFiles/TIN_P2P.dir/flags.make
CMakeFiles/TIN_P2P.dir/Constants.cpp.o: ../Constants.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/TIN_P2P.dir/Constants.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TIN_P2P.dir/Constants.cpp.o -c /home/lukasz/CLionProjects/TIN_P2P/Constants.cpp

CMakeFiles/TIN_P2P.dir/Constants.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TIN_P2P.dir/Constants.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz/CLionProjects/TIN_P2P/Constants.cpp > CMakeFiles/TIN_P2P.dir/Constants.cpp.i

CMakeFiles/TIN_P2P.dir/Constants.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TIN_P2P.dir/Constants.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz/CLionProjects/TIN_P2P/Constants.cpp -o CMakeFiles/TIN_P2P.dir/Constants.cpp.s

CMakeFiles/TIN_P2P.dir/Constants.cpp.o.requires:

.PHONY : CMakeFiles/TIN_P2P.dir/Constants.cpp.o.requires

CMakeFiles/TIN_P2P.dir/Constants.cpp.o.provides: CMakeFiles/TIN_P2P.dir/Constants.cpp.o.requires
	$(MAKE) -f CMakeFiles/TIN_P2P.dir/build.make CMakeFiles/TIN_P2P.dir/Constants.cpp.o.provides.build
.PHONY : CMakeFiles/TIN_P2P.dir/Constants.cpp.o.provides

CMakeFiles/TIN_P2P.dir/Constants.cpp.o.provides.build: CMakeFiles/TIN_P2P.dir/Constants.cpp.o


# Object files for target TIN_P2P
TIN_P2P_OBJECTS = \
"CMakeFiles/TIN_P2P.dir/main.cpp.o" \
"CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o" \
"CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o" \
"CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o" \
"CMakeFiles/TIN_P2P.dir/Socket.cpp.o" \
"CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o" \
"CMakeFiles/TIN_P2P.dir/Message.cpp.o" \
"CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o" \
"CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o" \
"CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o" \
"CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o" \
"CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o" \
"CMakeFiles/TIN_P2P.dir/File.cpp.o" \
"CMakeFiles/TIN_P2P.dir/FileManager.cpp.o" \
"CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o" \
"CMakeFiles/TIN_P2P.dir/Constants.cpp.o"

# External object files for target TIN_P2P
TIN_P2P_EXTERNAL_OBJECTS =

TIN_P2P: CMakeFiles/TIN_P2P.dir/main.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/Dependencies/JsonCpp/jsoncpp.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/JsonCreator.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/ServerThread.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/Socket.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/UDPAdapter.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/Message.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/File.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/FileManager.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/Constants.cpp.o
TIN_P2P: CMakeFiles/TIN_P2P.dir/build.make
TIN_P2P: CMakeFiles/TIN_P2P.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable TIN_P2P"
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
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/Message.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/MessageContainer.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/MessageHello.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/SocketCreator.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/JsonParser.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/WcisloSocket.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/File.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/FileManager.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/ServerInterface.cpp.o.requires
CMakeFiles/TIN_P2P.dir/requires: CMakeFiles/TIN_P2P.dir/Constants.cpp.o.requires

.PHONY : CMakeFiles/TIN_P2P.dir/requires

CMakeFiles/TIN_P2P.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TIN_P2P.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TIN_P2P.dir/clean

CMakeFiles/TIN_P2P.dir/depend:
	cd /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukasz/CLionProjects/TIN_P2P /home/lukasz/CLionProjects/TIN_P2P /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug /home/lukasz/CLionProjects/TIN_P2P/cmake-build-debug/CMakeFiles/TIN_P2P.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TIN_P2P.dir/depend

