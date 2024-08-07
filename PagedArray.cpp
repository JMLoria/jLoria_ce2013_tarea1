#include "PagedArray.h"

/*
 *
░█████╗░██╗░░░░░░█████╗░░██████╗░██████╗░░░░░██████╗░░█████╗░░██████╗░███████╗██████╗░░█████╗░██████╗░██████╗░░█████╗░██╗░░░██╗
██╔══██╗██║░░░░░██╔══██╗██╔════╝██╔════╝░░░░░██╔══██╗██╔══██╗██╔════╝░██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗░██╔╝
██║░░╚═╝██║░░░░░███████║╚█████╗░╚█████╗░░░░░░██████╔╝███████║██║░░██╗░█████╗░░██║░░██║███████║██████╔╝██████╔╝███████║░╚████╔╝░
██║░░██╗██║░░░░░██╔══██║░╚═══██╗░╚═══██╗░░░░░██╔═══╝░██╔══██║██║░░╚██╗██╔══╝░░██║░░██║██╔══██║██╔══██╗██╔══██╗██╔══██║░░╚██╔╝░░
╚█████╔╝███████╗██║░░██║██████╔╝██████╔╝░░░░░██║░░░░░██║░░██║╚██████╔╝███████╗██████╔╝██║░░██║██║░░██║██║░░██║██║░░██║░░░██║░░░
░╚════╝░╚══════╝╚═╝░░╚═╝╚═════╝░╚═════╝░░░░░░╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░╚══════╝╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░
 */


// 𝑪𝒐𝒏𝒔𝒕𝒓𝒖𝒄𝒕𝒐𝒓
PagedArray::PagedArray(const std::string &memDir) {
    // Inicializar el documento binario (memoria)
    memory.open(memDir, std::ios::in | std::ios::out);
    // Inicializar pageHit y pageFault
    pageHit = 0;
    pageFault = 0;
     // Inicializar los frames del paged array
    frame1 = Page();
    frame2 = Page();
    frame3 = Page();
    frame4 = Page();
}


// 𝑶𝒑𝒆𝒓𝒂𝒅𝒐𝒓 []
int PagedArray::operator[](int index) {
    // Calcular el indice relativo y el numero de pagina
    int relativeIndex = index % 128;
    int pageNum = index / 128;
    // Generar un ID al frame que queremos cargar a partir de los frames cargados
    int frameID = frameLoaded(pageNum);
    // Validar si es un frame cargado
    if (frameID < 0) {
        // Cargar el nuevo frame
        pageFault ++;
        int frameNum = checkLoadedFrame();
        loadFrame(frameNum, pageNum);
    } else {
        // Frame cargado anteriormente
        pageHit ++;
    }

    // Retornar numero del frame cargado
    if(frame1.getNumPage() == pageNum) {
        return frame1[relativeIndex];
    } else if(frame2.getNumPage() == pageNum) {
        return frame2[relativeIndex];
    } else if(frame3.getNumPage() == pageNum) {
        return frame3[relativeIndex];
    } else if (frame4.getNumPage() == pageNum) {
        return frame4[relativeIndex];
    }
    return -1;
}


// 𝑪𝒉𝒆𝒄𝒌 𝑳𝒐𝒂𝒅𝒆𝒅 𝑭𝒓𝒂𝒎𝒆
int PagedArray::checkLoadedFrame() {
    // Verificar cuales frames estan ocupados y cuales estan vacios
    if(!frame1.getLoaded()) {
        // Frame 1 vacio
        return 1;
    } else if(!frame2.getLoaded()) {
        // Frame 2 vacio
        return 2;
    } else if(!frame3.getLoaded()) {
        // Frame 3 vacio
        return 3;
    } else if(!frame4.getLoaded()) {
        // Frame 4 vacio
        return 4;
    } else {
        // Paged Arrey lleno
        return -1;
    }
}


// 𝑭𝒓𝒂𝒎𝒆 𝑳𝒐𝒂𝒅𝒆𝒅
int PagedArray::frameLoaded(int pageNum) {
    if(frame1.getNumPage() == pageNum) {
        return 1;
    } else if(frame2.getNumPage() == pageNum) {
        return 2;
    } else if(frame3.getNumPage() == pageNum) {
        return 3;
    } else if (frame4.getNumPage() == pageNum) {
        return 4;
    } else {
        return -1;
    }
}


// 𝑳𝒐𝒂𝒅 𝑭𝒓𝒂𝒎𝒆
void PagedArray::loadFrame(int frameNum, int pageNum) {
    // Cargar nuevo frame al paged array
    int tempFrame [128];
    // Extraer del documento el frame que se va a cargar
    memory.seekg(pageNum * sizeof(int) * 128);
    memory.read((char*) &tempFrame, 128 * sizeof(int));
    // Definir a cual page se va a cargar el frame
    switch(frameNum){
        case 1:
            // Cargar a frame 1
            frame1 = Page(tempFrame, pageNum);
            break;

        case 2:
            // Cargar a frame 2
            frame2 = Page(tempFrame, pageNum);
            break;

        case 3:
            // Cargar a frame 3
            frame3 = Page(tempFrame, pageNum);
            break;

        case 4:
            // Cargar a frame 4
            frame4 = Page(tempFrame, pageNum);
            break;

        default:
            // Paged array lleno, seleccionar frame al que se va a sobreescribir
            int randFrame = 1 + rand() % 4;
            loadFrame(randFrame, pageNum);
            break;
    }
}


// 𝑷𝒓𝒊𝒏𝒕 𝑰𝒏𝒇𝒐
void PagedArray::printInfo() {
    std::cout << "Page hit = " << pageHit << std::endl <<  "Page fault = " << pageFault << std::endl;
}


// 𝑬𝒙𝒆𝒄𝒖𝒕𝒆
int main(int argc, char *argv[]){
    std::string inputFile = argv[2];
    std::string outputFile = argv[4];

    std::cout << "Tarea Extraclase I - Arreglos Paginados \n";
    std::cout << "Estudiante: Jose Manuel Loria Cordero \n";
    std::cout << "Está ejecutando PagedArray.cpp \n";
    std::cout << "Argumentos ingresados:\n";
    std::cout << "\tInput path:" << inputFile << "\n";
    std::cout << "\tOutput path:" << outputFile << "\n";

    PagedArray array(inputFile);
    for (int i = 0; i < 500; i ++){
        std::cout << array[i * 32] << ", ";
        if((i + 1) % 20 == 0) {
            std::cout << "\n";
        }
    }
    array.printInfo();

    return 0;
}