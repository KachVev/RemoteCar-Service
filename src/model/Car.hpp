#pragma once
#include "Person.h"
#include "../util/Color.hpp"

class Car {
    using Battery = unsigned int;
    Color color; // Red by default
    Battery battery;
    // Current owner
    Person* current_owner {nullptr};

public:
    Car() : color(Color(255, 0, 0)), battery(0) {}
    explicit Car(Person* owner) : Car() { current_owner = owner; }

};