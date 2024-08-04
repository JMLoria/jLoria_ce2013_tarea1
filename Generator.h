#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <filesystem>

class Generator {
public:
    Generator(const std::string& sizeStr, const std::string& fileName);
    void printArray() const;
    const std::vector<int>& getArray() const;

private:
    enum Size : std::size_t {
        SMALL = 512ull * (1024 * 512),
        MEDIUM = 1024ull * (1024 * 512),
        LARGE = 2ull * 1024 * (1024 * 512)
    };

    std::vector<int> array;
    void generateArray(Size size);
    static Size parseSize(const std::string& sizeStr) ;
    void saveFile(const std::string& fileName, Size size) const;

    static std::filesystem::path getProjectPath() ;

};

#endif //GENERATOR_H
