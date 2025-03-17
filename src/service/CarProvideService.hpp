#pragma once
#include <algorithm>
#include <iostream>
#include <optional>
#include <ranges>
#include <vector>
#include "../module/Module.hpp"
#include "../model/Car.hpp"

class CarProvideService final : public Module {
    std::vector<Car> cars;

    auto find_unowned_cars() {
        return cars | std::views::filter([](const Car& c) { return !c.has_owner(); });
    }

    std::optional<std::reference_wrapper<Car>> find_relevant_car() {
        auto filtered_cars = find_unowned_cars();
        auto it = std::ranges::max_element(filtered_cars, {}, &Car::battery);
        if (it == filtered_cars.end()) {
            return std::nullopt;
        }
        return std::ref(*it);
    }

    void own_car(Person* new_owner) {
        auto car_opt = find_relevant_car();
        if (car_opt) {
            car_opt->get().owner = new_owner;
        }
    }

public:
    [[nodiscard]] std::string name() const override {
        return "CarProvideService";
    }

    void run() override {
        cars.push_back(Car());
        cars.push_back(Car());
        cars.push_back(Car());

        auto person = Person("Name", Person::USER);
        own_car(&person);
    }

    void stop() override {}
};