#pragma once
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <cctype>
#include <nlohmann/detail/meta/std_fs.hpp>
#include <nlohmann/json.hpp>

#include "WebSocketServerService.hpp"
#include "../entity/Car.hpp"

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
        websocket->registerHandler("/connect", [this](std::string_view message) {
            try {
                auto json = nlohmann::json::parse(message);

                const int battery = json["battery"];
                Car car;
                car.battery = battery;
                cars.push_back(car);


                std::cout << "New car added with battery: " << battery << std::endl;
                for (const auto& car : cars) {
    std::cout << "Car ID: " << car.id
              << ", Battery: " << car.battery
              << ", Owner: " << (car.owner ? car.owner->name : "None")
              << std::endl;
}
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse message: " << e.what() << std::endl;
            }
        });

        websocket->registerHandler("/dissconnect", [this](std::string_view message) {

        })
        //
        // cars.emplace_back();
        // cars.emplace_back();
        // cars.emplace_back();
        //
        // auto person = Person("Name", Person::USER);
        // own_car(&person);
        //
        for (const auto& car : cars) {
            std::cout << "Car ID: " << car.id
                      << ", Battery: " << car.battery
                      << ", Owner: " << (car.owner ? car.owner->name : "None")
                      << std::endl;
        }
    }

    void stop() override {}
};