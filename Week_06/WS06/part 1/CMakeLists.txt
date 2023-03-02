cmake_minimum_required(VERSION 3.24)
project(part_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_1
        College.cpp
        College.h
        Employee.cpp
        Employee.h
        Person.h
        Utilities.cpp
        Utilities.h
        w6_p1.cpp)
