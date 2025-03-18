cmake_minimum_required(VERSION 3.31)
project(Modules)

set(CMAKE_CXX_STANDARD 20)

add_library(Modules STATIC
        Module.cpp
        ModuleManager.cpp
)

target_include_directories(Modules PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
