#include "soal2.h"

void insertNode(address &root, int x) {
    if (root == NULL) {
        root = new Node;
        root->info = x;
        root->left = root->right = NULL;
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    } 
    else if (x > root->info) {
        insertNode(root->right, x);
    }
    else {
        // nilai sama → jangan dimasukkan (BST modul tidak menerima duplikat)
    }
}


void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int depth) {
    if (root == NULL) return depth - 1;
    int leftDepth  = hitungKedalaman(root->left, depth + 1);
    int rightDepth = hitungKedalaman(root->right, depth + 1);
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}
