#ifndef CE2103_TAREA1_JOSEMANUELLORIA_GENERATOR_H
#define CE2103_TAREA1_JOSEMANUELLORIA_GENERATOR_H

#include <vector>
#include <iostream>
#include <ctime>
#include <stdexcept>

#include <fstream>
#include <filesystem>

/*
 *
░█████╗░██╗░░░░░░█████╗░░██████╗░██████╗░░░░░░██████╗░███████╗███╗░░██╗███████╗██████╗░░█████╗░████████╗░█████╗░██████╗░
██╔══██╗██║░░░░░██╔══██╗██╔════╝██╔════╝░░░░░██╔════╝░██╔════╝████╗░██║██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗
██║░░╚═╝██║░░░░░███████║╚█████╗░╚█████╗░░░░░░██║░░██╗░█████╗░░██╔██╗██║█████╗░░██████╔╝███████║░░░██║░░░██║░░██║██████╔╝
██║░░██╗██║░░░░░██╔══██║░╚═══██╗░╚═══██╗░░░░░██║░░╚██╗██╔══╝░░██║╚████║██╔══╝░░██╔══██╗██╔══██║░░░██║░░░██║░░██║██╔══██╗
╚█████╔╝███████╗██║░░██║██████╔╝██████╔╝░░░░░╚██████╔╝███████╗██║░╚███║███████╗██║░░██║██║░░██║░░░██║░░░╚█████╔╝██║░░██║
░╚════╝░╚══════╝╚═╝░░╚═╝╚═════╝░╚═════╝░░░░░░░╚═════╝░╚══════╝╚═╝░░╚══╝╚══════╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝
 */


class Generator {
public:
    Generator(const std::string& sizeStr, const std::string& fileName);
    void printArray() const;
    const std::vector<int>& getArray() const;

private:
    enum SIZE : std::size_t {
        SMALL = 512ull * (1024 * 1024),
        MEDIUM = 1024ull * (1024 * 1024),
        LARGE = 2ull * 1024 * (1024 * 1024)
    };

    std::vector<int> array;
    void generateArray(SIZE size);
    static SIZE parseSize(const std::string& sizeStr);
    void saveFile(const std::string& fileName, SIZE size) const;

};

#endif //CE2103_TAREA1_JOSEMANUELLORIA_GENERATOR_H
