cmake_minimum_required(VERSION 3.31)
project(Car_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(Car_server src/main.cpp
        src/utils/color.hpp
        src/models/car.hpp
        src/models/person.h
)
