cmake_minimum_required(VERSION 3.6)
project(TIN_P2P)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

set(SOURCE_FILES main.cpp Dependencies/JsonCpp/jsoncpp.cpp JsonCreator.cpp JsonCreator.h Constants.h ServerThread.cpp ServerThread.h Socket.cpp Socket.h UDPAdapter.cpp UDPAdapter.h Message.cpp Message.h MessageContainer.cpp MessageContainer.h MessageHello.cpp MessageHello.h SocketCreator.cpp SocketCreator.h JsonParser.cpp JsonParser.h WcisloSocket.cpp WcisloSocket.h File.cpp File.h FileManager.cpp FileManager.h ServerInterface.cpp ServerInterface.h Constants.cpp Configuration.cpp Configuration.h Exceptions.cpp Exceptions.h ActionContainer.cpp ActionContainer.h)

add_executable(TIN_P2P ${SOURCE_FILES})
target_link_libraries(TIN_P2P Threads::Threads)