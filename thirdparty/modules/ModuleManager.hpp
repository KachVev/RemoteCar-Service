#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

#include "Module.hpp"

class ModuleManager {
    std::vector<Module*> modules;

public:
    void start() const {
        for (auto module : modules) {
            module->run();
        }
    }

    void stop() const {
        for (auto module : modules) {
            module->stop();
        }
    }

    void addModule(Module* module) {
        module->setManager(this);
        modules.push_back(module);
    }

    void removeModule(Module* module) {
        modules.erase(std::ranges::remove(modules, module).begin(), modules.end());
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
    std::vector<T*> getModules() {
        std::vector<T*> result;
        for (auto module : modules) {
            if (auto casted = dynamic_cast<T*>(module)) {
                result.push_back(casted);
            }
        }
        return result;
    }
};