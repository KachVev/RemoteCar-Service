#pragma once
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

#include "WebSocketServerService.hpp"
#include "../model/Car.hpp"

class CarProvideService final : public Module {
    std::vector<Car> cars;


    auto find_unowned_cars() {
        return cars | std::views::filter([](const Car& c) { return !c.has_owner(); });
    }

    void own_car(Person* new_owner) {
        auto unowned_cars = find_unowned_cars();
        if (unowned_cars.empty()) {
            std::cout << "No cars available" << std::endl;
            return;
        }
        const auto car = &*std::ranges::max_element(unowned_cars, {}, &Car::battery);
        car->owner = new_owner;
    }

public:
    [[nodiscard]] std::string_view name() const override {
        return "CarProvideService";
    }

    void run() override {
        const auto websocket = manager ? manager->getModule<WebSocketServerService>() : nullptr;
        if (!websocket) {
            return;
        }
        websocket->registerHandler("/connect", [this](auto *ws, std::string_view message) {
            // Parse message as json and create car
        });

        cars.emplace_back();
        cars.emplace_back();
        cars.emplace_back();

        auto person = Person("Name", Person::USER);
        own_car(&person);

        for (const auto& car : cars) {
            std::cout << "Car ID: " << car.id
                      << ", Battery: " << car.battery
                      << ", Owner: " << (car.owner ? car.owner->name : "None")
                      << std::endl;
        }
    }

    void stop() override {}
};