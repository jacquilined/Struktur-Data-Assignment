# <h1 align="center">Laporan Praktikum Singly Linked Link Modul 4
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori

Linked List merupakan salah satu struktur data dinamis yang digunakan untuk menyimpan sekumpulan data secara berurutan, namun tidak menggunakan lokasi memori yang berurutan seperti pada array. Setiap elemen dalam linked list disebut node, dan setiap node terdiri dari dua bagian utama, yaitu:

1. Data, yang berisi nilai atau informasi yang akan disimpan.

2. Pointer (next), yang berisi alamat dari node berikutnya dalam daftar.

Karena menggunakan pointer, ukuran linked list dapat bertambah atau berkurang secara dinamis sesuai kebutuhan program. Hal ini berbeda dengan array yang memiliki ukuran tetap setelah dideklarasikan.

Jenis Linked List

1. Singly Linked List
Setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya. Traversal (penelusuran) hanya dapat dilakukan dari node pertama (head) menuju node terakhir (NULL).

2. Doubly Linked List
Setiap node memiliki dua pointer, yaitu pointer ke node berikutnya (next) dan pointer ke node sebelumnya (prev).

3. Circular Linked List
Node terakhir akan menunjuk kembali ke node pertama, sehingga membentuk struktur data yang melingkar.

Operasi Dasar pada Singly Linked List

1. Create List – Membuat list baru yang masih kosong dengan inisialisasi pointer head = NULL.

2. Insert (Add) – Menambahkan node baru ke dalam list. Operasi ini dapat dilakukan di beberapa posisi, yaitu:

- Di awal list (Insert First)

- Di akhir list (Insert Last)

- Setelah node tertentu (Insert After)

3. Delete – Menghapus node dari list. Operasi ini juga dapat dilakukan pada beberapa posisi, yaitu:

- Menghapus node pertama (Delete First)

- Menghapus node terakhir (Delete Last)

- Menghapus node setelah node tertentu (Delete After)

4. Traversal / Print Info – Menelusuri seluruh node untuk menampilkan isi data dari setiap node.

Kelebihan dan Kekurangan

- Kelebihan:

Ukuran list bersifat dinamis dan dapat menyesuaikan kebutuhan program.

Operasi penambahan dan penghapusan node lebih efisien karena tidak perlu menggeser elemen seperti pada array.

- Kekurangan:

Akses terhadap elemen tidak bisa dilakukan secara langsung, harus melalui proses penelusuran dari node pertama.

Membutuhkan memori tambahan untuk menyimpan pointer di setiap node.
## Guided 

### main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

### list.h

```C++
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
// smua procedure da func yang dipakai
bool isEmpty (linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

### main2.cpp

```C++
#include "list2.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deletList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### list2.cpp

```C++
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```

### list2.h

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

## Unguided 

<img width="740" height="341" alt="image" src="https://github.com/user-attachments/assets/fbb6a37a-f65d-46b9-9bbd-1e01c7a6c34d" />

### singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address first;
};

// Prototype
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif

```
### singlylist.cpp

```C++
#include "singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
```

### singlymain.cpp

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```

#### Output:
<img width="1317" height="236" alt="image" src="https://github.com/user-attachments/assets/5ea90e64-84e4-451d-8f0b-13670b510873" />


Kode ini menunjukkan cara kerja Singly Linked List dasar:

1. Elemen disimpan dalam node terpisah yang dihubungkan pointer.

2. Penambahan data di awal list menggunakan insertFirst.

3. Traversal dilakukan lewat printInfo.

Bersifat dinamis, artinya ukuran list bisa bertambah tanpa batas selama masih ada memori.
#### Full code Screenshot:
<img width="1491" height="773" alt="image" src="https://github.com/user-attachments/assets/363bc936-b5dd-45be-a09e-e129173dba7b" />
<img width="1485" height="859" alt="image" src="https://github.com/user-attachments/assets/8e3f7ea9-8641-48d6-8fd2-137fc65e5e0f" />
<img width="1491" height="866" alt="image" src="https://github.com/user-attachments/assets/1b53a9d0-444b-4eb1-a8a5-3d12f0da123e" />




### 2.
<img width="763" height="264" alt="image" src="https://github.com/user-attachments/assets/7703fc1c-8f6f-4dbb-b751-1491464d3ac9" />

### singlylish.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address first;
};

// Prototype
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif

```
### singlymain.cpp
```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, Pdel;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // Awal list: 9 -> 12 -> 8 -> 0 -> 2
    deleteFirst(L, Pdel);   // hapus node 9
    dealokasi(Pdel);

    deleteLast(L, Pdel);    // hapus node 2
    dealokasi(Pdel);

    deleteAfter(L.first, Pdel); // hapus node setelah 12 (yaitu 8)
    dealokasi(Pdel);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << endl << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### singlylist.cpp
```C++
#include "singlylist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first->next == NULL) {
        P = L.first;
        L.first = NULL;
    } else {
        address Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    } else {
        P = NULL;
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != NULL) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}

```
#### Output:
<img width="828" height="252" alt="image" src="https://github.com/user-attachments/assets/9f86a247-7bc1-4d71-a79f-c31b2211fb1c" />


Program ini meniru cara kerja struktur data dinamis yang bisa:

 1. Menambah dan menghapus elemen (node) kapan pun.

2. Menelusuri dan menghitung jumlah node.

3. Membersihkan seluruh isi list dari memori setelah selesai.

Ini sangat berguna buat memahami dasar-dasar pengelolaan memori di C++.

#### Full code Screenshot:
<img width="1332" height="857" alt="image" src="https://github.com/user-attachments/assets/aa790607-277b-40da-8ad7-431ceb333897" />
<img width="1322" height="867" alt="image" src="https://github.com/user-attachments/assets/a9f6d763-e0dd-440a-b227-678ba1396aab" />
<img width="1332" height="861" alt="image" src="https://github.com/user-attachments/assets/9ec5e9a0-20d1-421a-b789-5351b1446713" />


## Kesimpulan
Pada modul ini dipelajari konsep dasar struktur data dinamis menggunakan Singly Linked List, yaitu kumpulan elemen (node) yang saling terhubung melalui pointer. Melalui praktikum ini, mahasiswa memahami bagaimana cara membuat list, menambah elemen di awal list (insertFirst), menampilkan isi list (printInfo), serta melakukan operasi penghapusan node (deleteFirst, deleteLast, deleteAfter).
Selain itu, fungsi nbList digunakan untuk menghitung jumlah node, dan deleteList untuk menghapus seluruh isi list dari memori. Dengan demikian, modul ini menekankan pentingnya pengelolaan memori dan implementasi pointer dalam membangun struktur data yang fleksibel dan efisien.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
