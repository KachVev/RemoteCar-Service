#include <iostream>

#include "models/person.h"
#include "utils/color.hpp"
using namespace std;

int main() {
    const Person person("John", Person::USER);

    std::cout << "Person name: " << person.name << std::endl;
    return 0;
}