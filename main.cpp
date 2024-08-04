#include <iostream>
#include "Generator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Generator generator(Generator::MEDIUM);
    std::cout << "Array generado con " <<generator.SMALL << " elementos." << std::endl;

    std::cout << "Imprimiendo array generado: " << std::endl;
    generator.printArray();

    return 0;
}
