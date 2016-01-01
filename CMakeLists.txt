cmake_minimum_required(VERSION 3.3)
project(Fat16)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BootSector.cpp BootSector.h)
add_executable(Fat16 ${SOURCE_FILES})