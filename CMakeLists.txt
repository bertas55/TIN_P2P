cmake_minimum_required(VERSION 3.6)
project(TIN_P2P)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

set(SOURCE_FILES main.cpp Dependencies/JsonCpp/jsoncpp.cpp JsonCreator.cpp JsonCreator.h Constants.h ServerThread.cpp ServerThread.h Socket.cpp Socket.h UDPAdapter.cpp UDPAdapter.h Message.cpp Message.h MessageContainer.cpp MessageContainer.h SocketCreator.cpp SocketCreator.h JsonParser.cpp JsonParser.h UDPSocket.cpp UDPSocket.h File.cpp File.h FileManager.cpp FileManager.h ServerInterface.cpp ServerInterface.h Constants.cpp Exceptions.cpp Exceptions.h ActionContainer.cpp ActionContainer.h TCPManager.cpp TCPManager.h Connection.cpp Connection.h FileInfoContainer.cpp FileInfoContainer.h FileDownload.cpp FileDownload.h LogContainer.cpp LogContainer.h DownloadHandler.cpp DownloadHandler.h)

add_executable(TIN_P2P ${SOURCE_FILES})
target_link_libraries(TIN_P2P Threads::Threads)