#pragma once
#include "Person.h"
#include "../util/Color.hpp"
#include "../util/IdGenerator.hpp"


class Car {

    friend class CarProvideService;
    using Battery = unsigned int;
    IdGenerator::Id_type id;
    Color color;
    volatile Battery battery;
    Person* owner {nullptr};

    bool has_owner() const { return owner != nullptr; }

public:
    Car() : id(IdGenerator::generate_id()), color(Color(255, 0, 0)), battery(0) {}
    explicit Car(Person* o) : Car() { owner = o;}
};




