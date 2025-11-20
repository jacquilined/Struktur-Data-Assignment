#include <iostream>
#include "DLLPlaylist.h"
using namespace std;

int main(){
    List L; 
    createList(L);

    lagu a ={"Senja di Kota","Nona Band",210,150,4.2};
    lagu b ={"Langkahmu","Delta",185,320,4.8};
    lagu c ={"Hujan Minggu","Arka",240,90,3.9};

    insertLast(L,a);
    insertLast(L,b);
    insertLast(L,c);

    viewList(L);
}
