#include "Page.h"

/*
 *
░█████╗░██╗░░░░░░█████╗░░██████╗░██████╗░░░░░██████╗░░█████╗░░██████╗░███████╗
██╔══██╗██║░░░░░██╔══██╗██╔════╝██╔════╝░░░░░██╔══██╗██╔══██╗██╔════╝░██╔════╝
██║░░╚═╝██║░░░░░███████║╚█████╗░╚█████╗░░░░░░██████╔╝███████║██║░░██╗░█████╗░░
██║░░██╗██║░░░░░██╔══██║░╚═══██╗░╚═══██╗░░░░░██╔═══╝░██╔══██║██║░░╚██╗██╔══╝░░
╚█████╔╝███████╗██║░░██║██████╔╝██████╔╝░░░░░██║░░░░░██║░░██║╚██████╔╝███████╗
░╚════╝░╚══════╝╚═╝░░╚═╝╚═════╝░╚═════╝░░░░░░╚═╝░░░░░╚═╝░░╚═╝░╚═════╝░╚══════╝
 */


// 𝑪𝒐𝒏𝒔𝒕𝒓𝒖𝒄𝒕𝒐𝒓
Page::Page(){
    // Inicializar atributos necesarios
    isLoaded = false;
    numPage = -1;
}


// 𝑪𝒐𝒏𝒔𝒕𝒓𝒖𝒄𝒕𝒐𝒓
Page::Page(int a[], int pageNum){
    // Inicializar el array del frame
    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++){
        array[i] = a[i];
    }
    // Inicializar atributos del frame
    numPage = pageNum;
    isLoaded = true;
}


// 𝑶𝒑𝒆𝒓𝒂𝒅𝒐𝒓 []
int Page::operator[](int index) {
    // Operador sobrecargado
    return array[index];
}


// 𝑮𝒆𝒕 𝑳𝒐𝒂𝒅𝒆𝒅
bool Page::getLoaded() const{
    // Rentorna si hay un frame cargado
    return isLoaded;
}


// 𝑮𝒆𝒕 𝑵𝒖𝒎𝒃𝒆𝒓 𝑷𝒂𝒈𝒆
int Page::getNumPage() const {
    // Retorna el numero de pagina cargado
    return numPage;
}
