#pragma once

struct IdGenerator {
    using Id = unsigned int;
    static Id generate_id() noexcept {
        static Id counter = 0;
        return ++counter;
    }
};