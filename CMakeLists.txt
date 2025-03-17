cmake_minimum_required(VERSION 3.31)
project(Car_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(Car_server src/main.cpp
        src/util/color.hpp
        src/model/car.hpp
        src/model/person.h
        src/module/Module.hpp
        src/service/CarProvideService.hpp
        src/module/ModuleManager.hpp
        src/util/IdGenerator.hpp
)



