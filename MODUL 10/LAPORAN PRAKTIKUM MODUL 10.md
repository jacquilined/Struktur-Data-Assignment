# <h1 align="center">Laporan Praktikum Modul 10 TREE (BAGIAN PERTAMA)
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori
Rekursif adalah metode pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan masalah yang dapat dipecah menjadi sub-masalah yang lebih kecil. Setiap fungsi rekursif harus memiliki base case sebagai kondisi berhenti dan recursive case yang terus memecah masalah hingga mencapai base case. Rekursif membuat kode lebih sederhana dan mudah dibaca, tetapi dapat lebih lambat dan menghabiskan memori karena banyaknya pemanggilan fungsi.

Tree merupakan struktur data non-linear yang tersusun dari node-node yang terhubung secara hierarkis. Sebuah tree memiliki root sebagai node utama, kemudian node lain yang dapat menjadi parent, child, sibling, atau leaf (node tanpa anak). Hubungan-hubungan ini membentuk hierarki yang merepresentasikan data bertingkat. Salah satu jenis tree yang paling banyak digunakan adalah Binary Tree, yaitu tree di mana setiap node memiliki maksimal dua anak. Bentuk khususnya adalah Binary Search Tree (BST), yang menyimpan data dengan aturan: nilai yang lebih kecil berada di subtree kiri dan nilai yang lebih besar berada di subtree kanan. Aturan ini memudahkan operasi pencarian, penyisipan, dan traversal. Traversal tree dapat dilakukan dengan beberapa cara, seperti in-order, pre-order, dan post-order, masing-masing digunakan untuk tujuan yang berbeda dalam pengolahan data.

## Guided 

### bst.h

```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST{
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree tree);
int size(BinTree tree);
int height(BinTree tree);

#endif

```

### bst.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksaaaudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}


bool deleteNode(BinTree tree, int angka){
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```

### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    // insert nodes
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 0);
    insertNode(root, 7);

    // print in-order
    inOrder(root);
    cout << endl;

    // menahan console seperti CodeBlocks
    system("pause");

    return 0;
}

```

## Unguided 
<img width="781" height="817" alt="image" src="https://github.com/user-attachments/assets/22b4e2f9-b52d-468f-b03d-f8e164d91482" />

### main1.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    // insert nodes
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 0);
    insertNode(root, 7);

    // print in-order
    inOrder(root);
    cout << endl;

    return 0;
}

```
### bstree.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == NULL)
        return NULL;
    else if (x == root->info)
        return root;
    else if (x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

void inOrder(address root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

```

### bstree.h

```C++
#ifndef BSTREE_H
#define BSTREE_H

typedef int infotype;

typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void inOrder(address root);

#endif

```
#### Output:
<img width="633" height="128" alt="image" src="https://github.com/user-attachments/assets/87551b3e-a242-4be4-88bf-a452dce348e6" />

Program ini menjelaskan tentang pembuatan dan penggunaan Binary Search Tree (BST) secara dasar, yaitu bagaimana memasukkan data ke dalam BST, mencari node tertentu, dan mencetak isi tree dalam urutan yang terurut (in-order). File `bstree.h` mendefinisikan struktur Node dan deklarasi fungsi, `bstree.cpp` berisi implementasi fungsi seperti `alokasi()` untuk membuat node baru, `insertNode()` untuk memasukkan nilai ke BST sesuai aturan kiri-lebih-kecil dan kanan-lebih-besar, `findNode()` untuk mencari nilai tertentu, serta `inOrder()` untuk mencetak data dari kecil ke besar. File `main1.cpp` kemudian menggunakan fungsi-fungsi tersebut untuk membangun sebuah BST dari beberapa nilai, lalu menampilkan hasil traversal in-order. Singkatnya, program ini adalah contoh implementasi struktur data Binary Search Tree lengkap dengan insert, search, dan traversal.

#### Full code Screenshot:
<img width="1919" height="1141" alt="image" src="https://github.com/user-attachments/assets/47de5ca5-96b4-4f17-a378-227892965c72" />
<img width="1912" height="1127" alt="image" src="https://github.com/user-attachments/assets/0e763156-e740-4e8f-8dc4-a142be2b2d5d" />
<img width="1919" height="1127" alt="image" src="https://github.com/user-attachments/assets/8fde0bcc-f92b-4cda-a203-ba182eefdeaa" />

### 
<img width="783" height="907" alt="image" src="https://github.com/user-attachments/assets/5ef48789-98e8-418d-b0a6-0e7346cfe8e5" />

### main2.cpp
```C++
#include "soal2.h"

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    InOrder(root);
    cout << "\n\n";

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}

```
### soal2.cpp
```C++

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

```
### soal2.h
```C++
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

```
#### Output:
<img width="750" height="246" alt="image" src="https://github.com/user-attachments/assets/b4e57284-ef76-4eda-93d9-fa93c0e6cd3d" />

Program ini menjelaskan cara membangun dan memproses sebuah Binary Search Tree (BST) menggunakan C++, termasuk menambah node, melakukan traversal, serta menghitung informasi penting dari tree. Melalui fungsi `insertNode()`, program membentuk BST dari data yang dimasukkan; fungsi `InOrder()` menampilkan urutan data secara terurut; fungsi `hitungJumlahNode()` menghitung total banyaknya node; `hitungTotalInfo()` menjumlahkan semua nilai yang ada di dalam tree; dan `hitungKedalaman()` menghitung kedalaman maksimum tree. Semua fungsi ini dipisah dalam file header (`soal2.h`), implementasi (`soal2.cpp`), dan program utama (`main2.cpp`) untuk menunjukkan pemrograman terstruktur. Hasil akhirnya menampilkan traversal in-order, kedalaman tree, jumlah node, dan total nilai node dalam BST.

#### Full code Screenshot:
<img width="1919" height="1137" alt="image" src="https://github.com/user-attachments/assets/07794a46-ae21-4c1f-85c5-43e8bddd5921" />
<img width="1914" height="1135" alt="image" src="https://github.com/user-attachments/assets/1602942b-37ee-4816-891d-6c658d184267" />
<img width="1919" height="1137" alt="image" src="https://github.com/user-attachments/assets/eb0da926-535f-4fe1-8d23-fbb5b384b0bb" />

####

<img width="634" height="332" alt="image" src="https://github.com/user-attachments/assets/e1f0130b-a2df-4f53-9c20-eb15880d676c" />

### tree.h
```C++
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

```
### tree.cpp
```C++
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
```
### main3.cpp
```C++
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

```
#### Output:

<img width="736" height="123" alt="image" src="https://github.com/user-attachments/assets/7e0da222-f748-4a13-96c4-b95d0bbaa11a" />

Program ini membangun sebuah Binary Tree sesuai gambar modul dengan membuat struktur `Node` yang memiliki data dan pointer ke anak kiri/kanan. File `tree.h` hanya berisi deklarasi struktur serta fungsi pembuat node dan fungsi traversal. Implementasinya ada di `tree.cpp`, yaitu `newNode()` untuk membuat node baru, serta `preOrder()` dan `postOrder()` untuk mencetak tree secara pre-order (root–left–right) dan post-order (left–right–root). Pada `main.cpp`, pohon dibentuk secara manual dengan menghubungkan node-node sehingga sesuai ilustrasi, lalu program memanggil fungsi traversal untuk menampilkan hasil pre-order dan post-order. Hasil akhirnya: pre-order menghasilkan `6 4 2 1 3 5 7`, dan post-order menghasilkan `1 3 2 5 4 7 6`.

#### Full code Screenshot:
<img width="1909" height="1132" alt="image" src="https://github.com/user-attachments/assets/160e2287-c7c2-4ae8-b451-27b354b1dfbd" />
<img width="1905" height="1136" alt="image" src="https://github.com/user-attachments/assets/86e9e9e6-e61c-4e69-a9ca-332db89d0d42" />
<img width="1917" height="1138" alt="image" src="https://github.com/user-attachments/assets/3cad6859-9798-46b6-b81f-f0406d9a9263" />

## Kesimpulan

Rekursif adalah teknik pemrograman yang memecah masalah menjadi versi yang lebih kecil melalui fungsi yang memanggil dirinya sendiri, dengan syarat adanya kondisi berhenti agar proses tidak berjalan tanpa batas. Struktur data tree, khususnya **Binary Search Tree (BST)**, menyimpan data secara hierarkis dengan aturan bahwa nilai lebih kecil berada di kiri dan nilai lebih besar berada di kanan, sehingga operasi seperti pencarian, penyisipan, dan traversal dapat dilakukan secara lebih efisien. Dengan menggabungkan konsep rekursif dan BST, berbagai operasi pada tree dapat dituliskan secara lebih sederhana dan terstruktur.

## Referensi
MODUL 10 TREE (BAGIAN PERTAMA)
