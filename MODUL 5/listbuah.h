#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
// dekralasi isi data 
typedef buah dataBuah;
typedef struct node *address; // alamat addres pada pointer

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty (linkedlist List);
void createList (linkedlist List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast (linkedlist &List);
void delAfter(linkedlist &List, address nodeBaru, address Prev);
int nbList(linkedlist &List);
void deletList(linkedlist &List);

//materrimodul 5 update
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List);
void updateFirst(linkedlist List, address prev);

//materi modul 5 serching
void FineNodeByData(linkedlist List, string data);
void FineNodeByAddress(linkedlist List, address node);
void FineNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif