#pragma once
#include "Person.h"
#include "../util/Color.hpp"
#include "../util/IdGenerator.hpp"

class Car {
    using Battery = unsigned int;
    friend class CarProvideService;

    IdGenerator::Id_type id;
    Color color;
    volatile Battery battery;
    Person* owner {nullptr};
public:
    Car() : id(IdGenerator::generate_id()), color(Color(255, 0, 0)), battery(0) {}
    explicit Car(const Battery newBattery) : Car() { battery = newBattery; }
    explicit Car(Person* newOwner) : Car() { owner = newOwner;}


    bool has_owner() const { return owner != nullptr; }
};




