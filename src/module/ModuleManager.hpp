#pragma once
#include <vector>
#include <iostream>

#include "Module.hpp"

class ModuleManager {
    std::vector<Module*> modules{};

public:
    void start() const {
        for (const auto module : modules) {
            module->run();
        }
    }

    void stop() const {
        for (const auto module : modules) {
            module->stop();
        }
    }

    void addModule(Module* module) {
        module->setManager(this);
        modules.push_back(module);
    }

    void removeModule(Module* module) {
        module->setManager(nullptr);
        std::erase(modules, module);
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
};