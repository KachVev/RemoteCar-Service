cmake_minimum_required(VERSION 3.31)
project(Car_server)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(thirdparty/modules)

# vcpkg manager
find_package(nlohmann_json CONFIG REQUIRED)
find_package(unofficial-uwebsockets CONFIG REQUIRED)

add_executable(Car_server
        src/main.cpp
        src/util/color.hpp
        src/entity/car.hpp
        src/entity/person.h
        src/service/CarProvideService.hpp
        src/util/IdGenerator.hpp
        src/service/WebSocketServerService.hpp
)

target_link_libraries(Car_server PRIVATE
        nlohmann_json::nlohmann_json
        unofficial::uwebsockets::uwebsockets
        Modules
)
