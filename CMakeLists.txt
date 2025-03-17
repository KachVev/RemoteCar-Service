cmake_minimum_required(VERSION 3.31)
project(Car_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(Car_server src/main.cpp
        src/util/color.hpp
        src/model/car.hpp
        src/model/person.h
)
