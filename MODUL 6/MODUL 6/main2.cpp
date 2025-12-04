#include <iostream>
#include <string>
#include "doublylist2.h"
using namespace std;

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

        insertLast(L, alokasi(data));

        cout << "Input lagi? (y/n): ";
        getline(cin, lagi);
    }

    cout << "\nDATA LIST:\n";
    printInfo(L);

    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dicari: ";
    getline(cin, cariNopol);

    address P = findElm(L, cariNopol);
    if (P != NULL) {
        cout << "\nData kendaraan ditemukan:\n";
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }

    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    deleteElm(L, hapusNopol);

    cout << "\nDATA LIST SESUDAH HAPUS:\n";
    printInfo(L);

    return 0;
}
