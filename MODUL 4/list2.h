#ifndef LISH_H
#define LiSH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};
// dekralasi isi data 
typedef mahasiswa dataMahasiswa;
typedef struct node *address; // alamat addres pada pointer

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty (linkedlist List);
void createList (linkedlist List);
address alokasi(string nama, string nim, int umur);
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

#endif