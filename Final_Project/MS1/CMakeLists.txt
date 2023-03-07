cmake_minimum_required(VERSION 3.24)
project(MS1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS1
        ms1.cpp
        Station.cpp
        Station.h
        Utilities.cpp
        Utilities.h)
