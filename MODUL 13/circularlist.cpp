#include "circularlist.h"

/* Create List */
void createList(List &L) {
    L.first = Nil;
}

/* Alokasi */
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

/* Dealokasi */
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* Insert First */
void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        P->next = P;
        P->prev = P;
    } else {
        address last = L.first->prev;

        P->next = L.first;
        P->prev = last;

        last->next = P;
        L.first->prev = P;
        L.first = P;
    }
}

/* Insert Last */
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.first->prev;

        P->next = L.first;
        P->prev = last;

        last->next = P;
        L.first->prev = P;
    }
}

/* Insert After */
void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        address nextNode = Prec->next;

        P->next = nextNode;
        P->prev = Prec;

        Prec->next = P;
        nextNode->prev = P;
    }
}

/* Delete First */
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first->next == L.first) {
        P = L.first;
        L.first = Nil;
        P->next = Nil;
        P->prev = Nil;
    } else {
        address last = L.first->prev;

        P = L.first;
        L.first = L.first->next;

        L.first->prev = last;
        last->next = L.first;

        P->next = Nil;
        P->prev = Nil;
    }
}

/* Delete Last */
void deleteLast(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else if (L.first->next == L.first) {
        deleteFirst(L, P);
    } else {
        address last = L.first->prev;
        address beforeLast = last->prev;

        P = last;
        beforeLast->next = L.first;
        L.first->prev = beforeLast;

        P->next = Nil;
        P->prev = Nil;
    }
}

/* Delete After */
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && L.first != Nil) {
        P = Prec->next;

        if (P == L.first) { // kalau yang dihapus adalah first
            deleteFirst(L, P);
        } else {
            address nextNode = P->next;
            Prec->next = nextNode;
            nextNode->prev = Prec;

            P->next = Nil;
            P->prev = Nil;
        }
    } else {
        P = Nil;
    }
}

/* Find Elm (berdasarkan nim) */
address findElm(List L, infotype x) {
    if (L.first == Nil) return Nil;

    address P = L.first;
    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.first);

    return Nil;
}

/* Print Info */
void printInfo(List L) {
    if (L.first == Nil) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        do {
            cout << "Nama : " << P->info.nama << endl;
            cout << "NIM  : " << P->info.nim << endl;
            cout << "L/P  : " << P->info.jenis_kelamin << endl;
            cout << "IPK  : " << P->info.ipk << endl;
            cout << "---------------------" << endl;
            P = P->next;
        } while (P != L.first);
    }
}
