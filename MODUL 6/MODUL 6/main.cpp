#include <iostream>
#include <string>
#include "doublylist.h"
using namespace std;

bool isNopolExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);
    infotype data;
    string lagi = "y";

    while (lagi == "y" || lagi == "Y") {
        cout << "Masukkan nomor polisi: ";
        getline(cin, data.nopol);

        if (isNopolExist(L, data.nopol)) {
            cout << "Nomor polisi sudah terdaftar!\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, data.warna);

        cout << "Masukkan tahun kendaraan: ";
        string thnStr;
        getline(cin, thnStr);
        data.thnBuat = stoi(thnStr);

        address P = alokasi(data);
        insertLast(L, P);

        cout << "Input lagi? (y/n): ";
        getline(cin, lagi);
    }

    printInfo(L);

    return 0;
}