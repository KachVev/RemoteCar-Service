#pragma once

struct IdGenerator {
    using Id_type = unsigned int;
    static Id_type generate_id() noexcept {
        static Id_type counter = 0;
        return ++counter;
    }
};