#pragma once

#include <string>
#include "../util/IdGenerator.hpp"

struct Person {
    enum Permission { USER, ADMIN };

    IdGenerator::Id_type id;
    std::string name;
    Permission type;

    explicit Person(std::string name, const Permission permission = USER)
        : id(IdGenerator::generate_id()), name(std::move(name)), type(permission) {}
};