/* file : multilist.h */
/* contoh ADT multi linked list (induk memiliki list anak) */
/* list induk dan list anak = doubly linked list */

#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL
typedef bool boolean;

typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* ===== STRUCT ANAK ===== */
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

/* ===== STRUCT INDUK ===== */
struct elemen_list_induk {
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

/********* pengecekan apakah list kosong ***********/
boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

/********* pembuatan list kosong *********/
void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

/********* manajemen memori *********/
address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);

void dealokasi(address P);
void dealokasiAnak(address_anak P);

/********* pencarian sebuah elemen list *********/
address findElm(listinduk L, infotypeinduk X);
address_anak findElm(listanak Lanak, infotypeanak X);

boolean fFindElm(listinduk L, address P);
boolean fFindElmanak(listanak Lanak, address_anak P);

address findBefore(listinduk L, address P);

/********* penambahan elemen **********/
void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);

void insertFirstAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void insertLastAnak(listanak &L, address_anak P);

/********* penghapusan sebuah elemen *********/
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);

void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);

/********** proses semua elemen list **********/
void printInfoInduk(listinduk L);
void printInfoAnak(listanak Lanak);

int nbListInduk(listinduk L);
int nbListAnak(listanak Lanak);

/********** proses terhadap list **********/
void delAll(listinduk &L);

#endif
