#include "ModuleManager.hpp"
#include "service/CarProvideService.hpp"

int main() {
    auto manager = ModuleManager();

    manager.addModule(new WebSocketServerService());
    manager.addModule(new CarProvideService());

    manager.start();

    return 0;
}
