#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    json j;
    j["username"] = "Steve";
    j["level"] = 42;
    j["inventory"] = { "pickaxe", "sword", "shield" };

    std::cout << j.dump(4) << std::endl;

    return 0;
}
