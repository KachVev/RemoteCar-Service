#pragma once
#include "person.h"
#include "../utils/color.hpp"

class Car {
    Color color = Color(255, 0, 0); // Red by default
    // Current owner
    Person currentOwner;
};

