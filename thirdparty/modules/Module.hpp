#pragma once
#include <string_view>

class ModuleManager;

class Module {
protected:
    ModuleManager* manager = nullptr;

public:
    virtual ~Module() = default;

    [[nodiscard]] virtual std::string_view name() const = 0;
    virtual void run() = 0;
    virtual void stop() = 0;

    void setManager(ModuleManager* mgr) {
        manager = mgr;
    }
};
