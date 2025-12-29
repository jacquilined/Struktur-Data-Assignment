#ifndef SOAL2_H
#define SOAL2_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
};

typedef Node* address;

// Deklarasi fungsi
void insertNode(address &root, int x);
void InOrder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int depth);

#endif
