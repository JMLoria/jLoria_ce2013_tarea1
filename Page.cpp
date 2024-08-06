#include "Page.h"


Page::Page(){
    isLoaded = false;
    numPage = -1;
}


Page::Page(int a[], int pageNum){
    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++){
        array[i] = a[i];
    }
    numPage = pageNum;
    isLoaded = true;
}


int Page::operator[](int index) {
    return array[index];
}


bool Page::getLoaded() const{
    return isLoaded;
}


int Page::getNumPage() const {
    return numPage;
}
