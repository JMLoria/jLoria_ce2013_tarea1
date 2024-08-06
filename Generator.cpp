#include "Generator.h"
#include <filesystem>

Generator::Generator(const std::string& sizeStr, const std::string& fileName){
    std::srand(std::time(nullptr));

    SIZE size = parseSize(sizeStr);
    generateArray(size);
    saveFile(fileName, size);
}


void Generator::generateArray(Generator::SIZE size){
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


void Generator::saveFile(const std::string &fileName, SIZE size) const {
    std::filesystem::path filePath = fileName;
    std::ofstream file(filePath, std::ios::binary);

    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura");
    }

    file.write(reinterpret_cast<const char*>(array.data()), array.size() * sizeof(int));
    file.close();
}


Generator::SIZE Generator::parseSize(const std::string& sizeStr) {
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


int main(int argc, char *argv[]){
    std::string sizeFile = argv[2];
    std::string pathFile = argv[4];

    std::cout << "Tarea Extraclase I - Arreglos Paginados \n";
    std::cout << "Estudiante: Jose Manuel Loria Cordero \n";
    std::cout << "Está ejecutando Generator.cpp \n";
    std::cout << "Argumentos ingresados:\n";
    std::cout << "\tSize:" << sizeFile << "\n";
    std::cout << "\tOutput path:" << pathFile << "\n";

    Generator generator(sizeFile, pathFile);

    return 0;
}