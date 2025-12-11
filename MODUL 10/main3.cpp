#include "tree.h"

int main() {

    address root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(7);

    root->left->left = newNode(2);
    root->left->right = newNode(5);

    root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);

    cout << "Pre-Order  : ";
    preOrder(root);
    cout << endl;

    cout << "Post-Order : ";
    postOrder(root);
    cout << endl;

    return 0;
}
