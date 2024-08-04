#include "Generator.h"

Generator::Generator(Size size){
    std::srand(std::time(nullptr));

    generateArray(size);
}

void Generator::generateArray(Generator::Size size){
    std::size_t numElements = size / sizeof(int);

    array.reserve(numElements);

    for (std::size_t i = 0; i < numElements; i++){
        array.push_back(std::rand());
    }
}

void Generator::printArray() const {
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << ", ";
        if ((i+1) % 10 == 0){
            std::cout << std::endl;
        }
    }

}
