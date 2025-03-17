#pragma once

class Module {
public:
    virtual ~Module() = default;
    [[nodiscard]] virtual std::string name() const = 0;

    virtual void run() = 0;
    virtual void stop() = 0;

};