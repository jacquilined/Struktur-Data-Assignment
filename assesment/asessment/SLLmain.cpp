#include <iostream>
#include "SLLinventory.h"
using namespace std;

int main() {
    List L;
    createList(L);

    Product P;
    P.Nama = "Pulpen";
    P.SKU = "A001";
    P.Jumlah = 20;
    P.HargaSatuan = 2500;
    P.DiskonPersen = 0;
    insertLast(L, P);

    P.Nama = "Buku Tulis";
    P.SKU = "A002";
    P.Jumlah = 15;
    P.HargaSatuan = 5000;
    P.DiskonPersen = 10;
    insertLast(L, P);

    P.Nama = "Penghapus";
    P.SKU = "A003";
    P.Jumlah = 30;
    P.HargaSatuan = 1500;
    P.DiskonPersen = 0;
    insertLast(L, P);

    viewList(L);

    deleteFirst(L);

    viewList(L);

    P.Nama = "Stabilo";
    P.SKU = "A010";
    P.Jumlah = 40;
    P.HargaSatuan = 9000;
    P.DiskonPersen = 5;
    updateAtPosition(L, 2, P);

    viewList(L);

    searchByFinalPriceRange(L, 2000, 7000);

    return 0;
}