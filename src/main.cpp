#include "ModuleManager.hpp"
#include "service/CarProvideService.hpp"

int main() {
    auto manager = ModuleManager();

    manager.addModule(new WebSocketServerService());
    manager.addModule(new CarProvideService());

    manager.start();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
