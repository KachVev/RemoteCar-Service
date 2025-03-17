#pragma once
#include <string>

class ModuleManager;


class Module {
protected:
    ModuleManager* manager = nullptr;

public:
    virtual ~Module() = default;

    [[nodiscard]] virtual std::string name() const = 0;
    virtual void run() = 0;
    virtual void stop() = 0;

    void setManager(ModuleManager* mgr) {
        manager = mgr;
    }
};