cmake_minimum_required(VERSION 3.6)
project(TIN_P2P)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)


set(SOURCE_FILES main.cpp Dependencies/JsonCpp/jsoncpp.cpp JsonCreator.cpp JsonCreator.h Constants.h)
add_executable(TIN_P2P ${SOURCE_FILES})
target_link_libraries(TIN_P2P Threads::Threads)