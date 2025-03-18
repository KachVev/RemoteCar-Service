cmake_minimum_required(VERSION 3.31)
project(Car_server)

set(CMAKE_CXX_STANDARD 20)

# Thirdparty
add_subdirectory(thirdparty/modules)

add_executable(Car_server src/main.cpp
        src/util/color.hpp
        src/model/car.hpp
        src/model/person.h
        src/service/CarProvideService.hpp
        src/util/IdGenerator.hpp
        src/service/WebSocketServerService.hpp
)

target_link_libraries(Car_server PRIVATE Modules)

target_include_directories(Car_server PRIVATE thirdparty/modules)

# Todo add websocket and json for parse connection