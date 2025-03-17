#pragma once
#include "../util/color.hpp"

class Car {
    using Battery = unsigned int;
    Color color = Color(255, 0, 0); // Red by default
    // Current owner
    Battery battery = 0;



};