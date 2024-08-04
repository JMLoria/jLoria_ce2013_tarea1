#include <iostream>
#include "Generator.h"

int main() {
    std::string fileName = "test1";
    std::string size = "SMALL";

    Generator generator(size, fileName);
    std::cout << "Array generado y guardado en " << fileName << ".bin con " << generator.getArray().size() << " elementos." << std::endl;

    return 0;
}
