#include "tree.h"

address newNode(int x) {
    address p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}
