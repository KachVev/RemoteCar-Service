#pragma once
#include <algorithm>
#include <iostream>
#include <optional>
#include <ranges>
#include <unordered_map>
#include "../module/Module.hpp"
#include "../model/Car.hpp"


class CarProvideService final : public Module {
public:

    [[nodiscard]] std::string name() const override {
        return "CarProvideService";
    }

    void run() override {
        // Create some cars
        cars.push_back(Car());
        cars.push_back(Car());
        cars.push_back(Car());

        auto person = Person("Name", Person::USER);
        own_car(&person);
    }

    void stop() override {}


};