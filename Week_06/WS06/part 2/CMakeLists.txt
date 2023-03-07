cmake_minimum_required(VERSION 3.24)
project(part_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_2
        College.cpp
        College.h
        Employee.cpp
        Employee.h
        Person.h
        Utilities.cpp
        Utilities.h
        w6_p2.cpp Professor.h Professor.cpp Student.h Student.cpp)
