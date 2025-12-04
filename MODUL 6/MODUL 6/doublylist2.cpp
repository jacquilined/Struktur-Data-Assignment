#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == NULL) {
        cout << "List kosong.\n";
        return;
    }
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << "----------------------\n";
        P = P->next;
    }
}

bool isNopolExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return NULL;
}

void deleteElm(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == NULL) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan.\n";
        return;
    }

    if (P->prev != NULL) P->prev->next = P->next;
    else L.First = P->next;

    if (P->next != NULL) P->next->prev = P->prev;
    else L.Last = P->prev;

    dealokasi(P);
    cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
}
