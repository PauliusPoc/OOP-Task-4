cmake_minimum_required(VERSION 3.9)
project(OOP_Task_4)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_BUILD_TYPE Release)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS_DEBUG "-o1")
set(CMAKE_CXX_FLAGS_RELEASE "-o1")

message(STATUS "Flags: ${CMAKE_CXX_FLAGS_DEBUG}")

add_executable(OOP_Task_4 main.cpp myvector.h Timer.h)
