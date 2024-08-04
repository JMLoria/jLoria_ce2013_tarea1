#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <iostream>
#include <ctime>


class Generator {
public:
    enum Size : std::size_t {
        SMALL = 512ull * 1024 * 1024,
        MEDIUM = 1024ull * 1024 * 1024,
        LARGE = 2ull * 1024 * 1024 * 1024
    };

    Generator(Size size);
    void printArray() const;

private:
    std::vector<int> array;
    void generateArray(Size size);

};


#endif //GENERATOR_H
