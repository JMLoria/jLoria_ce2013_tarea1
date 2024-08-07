#include "Generator.h"
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


// 𝑪𝒐𝒏𝒔𝒕𝒓𝒖𝒄𝒕𝒐𝒓
Generator::Generator(const std::string& sizeStr, const std::string& fileName){
    std::srand(std::time(nullptr));

    SIZE size = parseSize(sizeStr);
    generateArray(size);
    saveFile(fileName, size);
}


// 𝑮𝒆𝒏𝒆𝒓𝒂𝒕𝒆 𝑨𝒓𝒓𝒂𝒚
void Generator::generateArray(Generator::SIZE size){
    // Calcular el tamaño del array
    std::size_t numElements = size / sizeof(int);
    // Alocar memoria para el array
    array.clear();
    array.reserve(numElements);
    // Escribir valores aleatorios
    for (std::size_t i = 0; i < numElements; i++){
        array.push_back(std::rand());
    }
}


// 𝑮𝒆𝒕 𝑨𝒓𝒓𝒂𝒚
const std::vector<int>& Generator::getArray() const {
    // Retorna el array
    return array;
}


// 𝑷𝒓𝒊𝒏𝒕 𝑨𝒓𝒓𝒂𝒚
void Generator::printArray() const {
    // Imprime en consola el array
    for (std::size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << ", ";
        // Cada 10 valores, salta a la siguiente linea
        if ((i+1) % 10 == 0){
            std::cout << std::endl;
        }
    }
}


//𝑺𝒂𝒗𝒆 𝑭𝒊𝒍𝒆
void Generator::saveFile(const std::string &fileName, SIZE size) const {
    // Crea el path con el nombre del archivo
    std::filesystem::path filePath = fileName;
    // Crea el archivo binario
    std::ofstream file(filePath, std::ios::binary);
    // Valida que el archivo se haya creado o abierto
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura");
    }
    // Escribe el array en el archivo
    file.write(reinterpret_cast<const char*>(array.data()), array.size() * sizeof(int));
    file.close();
}


// 𝑷𝒂𝒓𝒔𝒆 𝑺𝒊𝒛𝒆
Generator::SIZE Generator::parseSize(const std::string& sizeStr) {
    // Establece el tamaño que va a tener el archivo segun el string ingresado
    if (sizeStr == "SMALL") {
        // Establece el tamaño pequeño
        return SMALL;
    } else if (sizeStr == "MEDIUM") {
        // Establece el tamaño medio
        return MEDIUM;
    } else if (sizeStr == "LARGE") {
        // Establece el tamaño grande
        return LARGE;
    } else{
        throw std::invalid_argument("Tamaño no válido. Pruebe: 'SMALL', 'MEDIUM', 'LARGE'");
    }
}


// 𝑬𝒙𝒆𝒄𝒖𝒕𝒆
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