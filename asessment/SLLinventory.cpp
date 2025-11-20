#include "SLLinventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
}

address allocate(Product P) {
    address N = new Node;
    N->info = P;
    N->next = nullptr;
    return N;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, Product P) {
    address N = allocate(P);
    N->next = L.head;
    L.head = N;
}

void insertLast(List &L, Product P) {
    address N = allocate(P);
    if (isEmpty(L)) {
        L.head = N;
    } else {
        address Q = L.head;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = N;
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != nullptr) {
        address N = allocate(P);
        N->next = Q->next;
        Q->next = N;
    }
}

void deleteFirst(List &L) {
    if (!isEmpty(L)) {
        address P = L.head;
        L.head = P->next;
        deallocate(P);
    }
}

void deleteLast(List &L) {
    if (!isEmpty(L)) {
        if (L.head->next == nullptr) {
            deallocate(L.head);
            L.head = nullptr;
        } else {
            address Q = L.head;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            address P = Q->next;
            Q->next = nullptr;
            deallocate(P);
        }
    }
}

void deleteAfter(List &L, address Q) {
    if (Q != nullptr && Q->next != nullptr) {
        address P = Q->next;
        Q->next = P->next;
        deallocate(P);
    }
}

void updateAtPosition(List &L, int posisi, Product P) {
    address Q = L.head;
    int idx = 1;
    while (Q != nullptr && idx < posisi) {
        Q = Q->next;
        idx++;
    }
    if (Q != nullptr) {
        Q->info = P;
    }
}

float finalPrice(Product P) {
    return P.HargaSatuan * (1 - P.DiskonPersen / 100);
}

void viewList(List L) {
    address Q = L.head;
    int pos = 1;
    while (Q != nullptr) {
        cout << "Posisi: " << pos << endl;
        cout << "Nama: " << Q->info.Nama << endl;
        cout << "SKU: " << Q->info.SKU << endl;
        cout << "Jumlah: " << Q->info.Jumlah << endl;
        cout << "HargaSatuan: " << Q->info.HargaSatuan << endl;
        cout << "DiskonPersen: " << Q->info.DiskonPersen << endl;
        cout << "HargaAkhir: " << finalPrice(Q->info) << endl;
        cout << "----------------------\n";

        Q = Q->next;
        pos++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    address Q = L.head;
    int pos = 1;
    while (Q != nullptr) {
        float h = finalPrice(Q->info);
        if (h >= minPrice && h <= maxPrice) {
            cout << "Posisi: " << pos << endl;
            cout << "Nama: " << Q->info.Nama << endl;
            cout << "SKU: " << Q->info.SKU << endl;
            cout << "HargaAkhir: " << h << endl;
            cout << "----------------------\n";
        }
        Q = Q->next;
        pos++;
    }
}
