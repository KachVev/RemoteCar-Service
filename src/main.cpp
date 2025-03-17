#include <iostream>

#include "model/person.h"
#include "util/color.hpp"
using namespace std;

int main() {
    const Person person("John", Person::USER);

    std::cout << "Person name: " << person.name << std::endl;
    return 0;

    // Return car who have biggest battery and don`t have current owner(not rented)
}