#include "Generator.h"
#include <filesystem>

Generator::Generator(const std::string& sizeStr, const std::string& fileName){
    std::srand(std::time(nullptr));

    Size size = parseSize(sizeStr);

    generateArray(size);

    saveFile(fileName, size);
}

void Generator::generateArray(Generator::Size size){
    std::size_t numElements = size / sizeof(int);

    array.clear();
    array.reserve(numElements);

    for (std::size_t i = 0; i < numElements; i++){
        array.push_back(std::rand());
    }
}


const std::vector<int>& Generator::getArray() const {
    return array;
}

void Generator::printArray() const {
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << ", ";
        if ((i+1) % 10 == 0){
            std::cout << std::endl;
        }
    }

}

void Generator::saveFile(const std::string &fileName, Size size) const {
    std::filesystem::path proyectPath = getProjectPath();

    std::string fileBin = fileName + ".bin";

    std::filesystem::path filePath = proyectPath / fileBin;

    std::ofstream file(filePath);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura");
    }

    std::size_t bytesWritten = 0;
    for (std::size_t i = 0; i < array.size() && bytesWritten < size; i++) {
        file << array[i];
        bytesWritten += sizeof(array[i]);
    }
    file.close();
}

Generator::Size Generator::parseSize(const std::string& sizeStr) {
    if (sizeStr == "SMALL") {
        return SMALL;
    } else if (sizeStr == "MEDIUM") {
        return MEDIUM;
    } else if (sizeStr == "LARGE") {
        return LARGE;
    } else{
        throw std::invalid_argument("Tamaño no válido. Pruebe: 'SMALL', 'MEDIUM', 'LARGE'");
    }
}

std::filesystem::path Generator::getProjectPath() {
    std::filesystem::path currentPath = std::filesystem::current_path();
    while (currentPath.has_parent_path()) {
        currentPath = currentPath.parent_path();
        if (std::filesystem::exists(currentPath / "CMakeLists.txt")) {
            return currentPath;
        }
    }
    throw std::runtime_error("No se pudo encontrar la ruta del proyecto");
}
