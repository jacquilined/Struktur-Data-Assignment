#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    listinduk L;
    CreateList(L);

    // buat induk
    address P1 = alokasi(10);
    address P2 = alokasi(20);
    address P3 = alokasi(30);

    insertFirst(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    // tambahkan anak ke induk 10
    address_anak A1 = alokasiAnak(100);
    address_anak A2 = alokasiAnak(200);

    insertFirstAnak(P1->lanak, A1);
    insertLastAnak(P1->lanak, A2);

    // tambahkan anak ke induk 20
    address_anak B1 = alokasiAnak(300);
    insertFirstAnak(P2->lanak, B1);

    cout << "=== DATA MULTI LIST ===" << endl;
    printInfoInduk(L);

    cout << "\nCari induk 20: ";
    address cari = findElm(L, 20);
    if (cari != Nil) cout << "ketemu (" << cari->info << ")" << endl;
    else cout << "tidak ketemu" << endl;

    cout << "\nHapus induk 20" << endl;
    delP(L, 20);

    cout << "\n=== SETELAH HAPUS INDUK 20 ===" << endl;
    printInfoInduk(L);

    cout << "\nHapus semua" << endl;
    delAll(L);

    cout << "\nJumlah induk: " << nbListInduk(L) << endl;

    return 0;
}
