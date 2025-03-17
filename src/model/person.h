#pragma once

#include <string>
#include <utility>

struct Person {
    enum Permission { USER, ADMIN };

    std::string name;
    Permission type;

    explicit Person(std::string name, const Permission permission = USER) : name(std::move(name)), type(permission) {}
};






