#include "PagedArray.h"


PagedArray::PagedArray(const std::string &memDir) {
    memory.open(memDir, std::ios::in | std::ios::out);

    pageHit = 0;
    pageFault = 0;

    frame1 = Page();
    frame2 = Page();
    frame3 = Page();
    frame4 = Page();
}


int PagedArray::operator[](int index) {
    int relativeIndex = index % 128;
    int pageNum = index / 128;

    int frameID = frameLoaded(pageNum);

    if (frameID < 0) {
        pageFault ++;
        int frameNum = checkLoadedFrame();
        loadFrame(frameNum, pageNum);
    } else {
        pageHit ++;
    }

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


int PagedArray::checkLoadedFrame() {
    if(!frame1.getLoaded()) {
        return 1;
    } else if(!frame2.getLoaded()) {
        return 2;
    } else if(!frame3.getLoaded()) {
        return 3;
    } else if(!frame4.getLoaded()) {
        return 4;
    } else {
        return -1;
    }
}


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


void PagedArray::loadFrame(int frameNum, int pageNum) {
    int tempFrame [128];
    memory.seekg(pageNum * sizeof(int) * 128);
    memory.read((char*) &tempFrame, 128 * sizeof(int));

    switch(frameNum){
        case 1:
            // loadMemory
            frame1 = Page(tempFrame, pageNum);
            break;

        case 2:
            frame2 = Page(tempFrame, pageNum);
            break;

        case 3:
            frame3 = Page(tempFrame, pageNum);
            break;

        case 4:
            frame4 = Page(tempFrame, pageNum);
            break;

        default:
            int randFrame = 1 + rand() % 4;
            loadFrame(randFrame, pageNum);
            break;
    }
}


void PagedArray::printInfo() {
    std::cout << "Page hit = " << pageHit << std::endl <<  "Page fault = " << pageFault << std::endl;
}


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