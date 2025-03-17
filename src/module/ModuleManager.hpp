#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Module.hpp"

class ModuleManager {
    std::vector<Module*> modules{};

public:
    void start() const {
        for (const auto module : modules) {
            module->run();
            std::cout << "Module " << module->name() << " started" << std::endl;
        }
    }

    void stop() const {
        for (const auto module : modules) {
            module->stop();
            std::cout << "Module " << module->name() << " stopped" << std::endl;
        }
    }

    void addModule(Module* module) {
        modules.push_back(module);
    }

    void removeModule(Module* module) {
        std::erase(modules, module); // FIXME
    }

    template <typename T>
    T* getModule() {
        for (auto module : modules) {
            if (auto casted = dynamic_cast<T*>(module)) {
                return casted;
            }
        }
        return nullptr;
    }

    template <typename T>
    void startModule() {
        for (auto module : modules) {
            if (auto casted = dynamic_cast<T*>(module)) {
                casted->run();
                std::cout << "Module " << casted->name() << " started" << std::endl;
                return;
            }
        }
    }

    template <typename T>
    void stopModule() {
        for (auto module : modules) {
            if (auto casted = dynamic_cast<T*>(module)) {
                casted->stop();
                std::cout << "Module " << casted->name() << " stopped" << std::endl;
                return;
            }
        }
    }
};