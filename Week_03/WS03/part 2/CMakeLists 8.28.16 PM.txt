cmake_minimum_required(VERSION 3.24)
project(part_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_1
        Collection.h
        Pair.cpp
        Pair.h
        w3_p1.cpp)
