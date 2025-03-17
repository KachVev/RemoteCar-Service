#pragma once
#include <map>

#include "../module/Module.hpp"
#include "../util/IdGenerator.hpp"

class CarProvideService final : public Module {
public:

    std::string name() const override {;
        return "CarProvideService";
    }

    void run() override {

    }

    void stop() override {
    }
};
