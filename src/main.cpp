#include <iostream>
#include "model/Person.h"
#include "module/Module.hpp"
#include "module/ModuleManager.hpp"
#include "service/CarProvideService.hpp"

int main() {
    auto manager = ModuleManager();

    manager.addModule(new CarProvideService());
    const Person person("John", Person::USER);

    std::cout << "Person name: " << person.name << std::endl;
    manager.start();


    return 0;
}
