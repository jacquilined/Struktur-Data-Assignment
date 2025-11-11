#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;

typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
