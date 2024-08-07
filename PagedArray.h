#ifndef CE2103_TAREA1_JOSEMANUELLORIA_PAGEDARRAY_H
#define CE2103_TAREA1_JOSEMANUELLORIA_PAGEDARRAY_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include "Page.h"

/*
 *
░█████╗░██╗░░░░░░█████╗░░██████╗░██████╗░░░░░██████╗░░█████╗░░██████╗░███████╗██████╗░░█████╗░██████╗░██████╗░░█████╗░██╗░░░██╗
██╔══██╗██║░░░░░██╔══██╗██╔════╝██╔════╝░░░░░██╔══██╗██╔══██╗██╔════╝░██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗░██╔╝
██║░░╚═╝██║░░░░░███████║╚█████╗░╚█████╗░░░░░░██████╔╝███████║██║░░██╗░█████╗░░██║░░██║███████║██████╔╝██████╔╝███████║░╚████╔╝░
██║░░██╗██║░░░░░██╔══██║░╚═══██╗░╚═══██╗░░░░░██╔═══╝░██╔══██║██║░░╚██╗██╔══╝░░██║░░██║██╔══██║██╔══██╗██╔══██╗██╔══██║░░╚██╔╝░░
╚█████╔╝███████╗██║░░██║██████╔╝██████╔╝░░░░░██║░░░░░██║░░██║╚██████╔╝███████╗██████╔╝██║░░██║██║░░██║██║░░██║██║░░██║░░░██║░░░
░╚════╝░╚══════╝╚═╝░░╚═╝╚═════╝░╚═════╝░░░░░░╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░╚══════╝╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░
 */


class PagedArray {

private:
    int pageHit;
    int pageFault;

    Page frame1;
    Page frame2;
    Page frame3;
    Page frame4;

    std::fstream memory;

    int checkLoadedFrame();
    int frameLoaded(int pageNum);
    void loadFrame(int frameNum, int pageNum);

public:
    PagedArray(const std::string& memDir);
    int operator [](int index);
    void printInfo();
};


#endif //CE2103_TAREA1_JOSEMANUELLORIA_PAGEDARRAY_H
