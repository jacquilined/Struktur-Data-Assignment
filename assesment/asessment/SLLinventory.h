#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
using namespace std;

typedef struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
} Product;

typedef struct Node *address;

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address P);

void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Q);

void updateAtPosition(List &L, int posisi, Product P);

void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

#endif