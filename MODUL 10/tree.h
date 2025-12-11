#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *left;
    Node *right;
};

typedef Node* address;

// buat node baru
address newNode(int x);

// traversal
void preOrder(address root);
void postOrder(address root);

#endif
