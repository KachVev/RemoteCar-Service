#pragma once
#include "Person.h"
#include "../util/Color.hpp"
#include "../util/IdGenerator.hpp"



class Car {
    using Battery = unsigned int;
    friend class CarProvideService;

    // TODO: Add here websocket client
    // Car -> Connect -> Server -> Get client -> Link client to car

    IdGenerator::Id_type id;
    Color color;
    volatile Battery battery;
    Person* owner {nullptr};
public:
    explicit Car(IdGenerator::Id_type id) : id(id), color(Color(255, 0, 0)), battery(0) {}

    bool has_owner() const { return owner != nullptr; }
};