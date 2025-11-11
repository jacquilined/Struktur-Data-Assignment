# <h1 align="center">Laporan Praktikum Modul 5 Singly Linked List (Bagian Kedua)
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
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData (List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### listbuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}
```

### listbuah.h

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
// dekralasi isi data 
typedef buah dataBuah;
typedef struct node *address; // alamat addres pada pointer

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty (linkedlist List);
void createList (linkedlist List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast (linkedlist &List);
void delAfter(linkedlist &List, address nodeBaru, address Prev);
int nbList(linkedlist &List);
void deletList(linkedlist &List);

//materrimodul 5 update
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List);
void updateFirst(linkedlist List, address prev);

//materi modul 5 serching
void FineNodeByData(linkedlist List, string data);
void FineNodeByAddress(linkedlist List, address node);
void FineNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif
```

## Unguided 

<img width="725" height="475" alt="image" src="https://github.com/user-attachments/assets/5aa3e69c-ce07-49c9-973b-1fd8ad66fbd4" />

### singlylist.h

```C++
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

```
### singlylist.cpp

```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

```

### singlymain.cpp

```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;

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

<img width="799" height="69" alt="image" src="https://github.com/user-attachments/assets/59948802-22e9-4a99-a23b-a31076f58498" />


Program ini mengimplementasikan Single Linked List sederhana menggunakan tiga file: header, implementasi, dan main. Struktur data yang digunakan terdiri dari node yang menyimpan sebuah nilai integer (info) dan pointer menuju node berikutnya (next). List hanya menyimpan satu pointer yaitu First, yang menunjuk ke elemen pertama.

File singlylist.h berisi deklarasi struktur node, struktur list, dan prototype fungsi. File singlylist.cpp berisi implementasi fungsi–fungsi, yaitu:

createList() → menginisialisasi list agar kosong (First = NULL).

alokasi() → membuat node baru dan mengisi nilai info.

dealokasi() → menghapus node dari memori.

insertFirst() → menambahkan elemen baru pada bagian depan list.

printInfo() → menampilkan seluruh elemen list secara berurutan.

Pada file singlymain.cpp, program membuat sebuah list kosong, menambahkan lima elemen (9, 12, 8, 0, 2) dengan insertFirst(), lalu mencetak isi list. Karena elemen terus ditambahkan di depan, urutan yang tampil adalah: 9 12 8 0 2. Program kemudian selesai dengan kode keluar Process returned 0 (0x0) yang menunjukkan eksekusi berhasil tanpa error.

#### Full code Screenshot:
<img width="1326" height="858" alt="image" src="https://github.com/user-attachments/assets/0ee4cb5f-2f14-4e48-8d7f-82a44a139f15" />
<img width="1324" height="854" alt="image" src="https://github.com/user-attachments/assets/1404fb5a-20b6-4bb1-ba60-f5111ff5dcd0" />
<img width="1333" height="862" alt="image" src="https://github.com/user-attachments/assets/a8df144e-4f76-4a27-9612-016f5a35e592" />


### 
<img width="661" height="168" alt="image" src="https://github.com/user-attachments/assets/30f11c2d-fc0f-4b5d-a9df-22ab8b2e6aff" />

### singlylish.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);

// WAJIB ADA ↓↓↓
address findElm(List L, infotype x);

#endif


```
### singlymain.cpp
```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;

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

    // Panggil fungsi baru
    findElm(L, 8);

    return 0;
}

```
### singlylist.cpp
```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == x) {
            cout << x << " ditemukan dalam list" << endl;
            return P;
        }
        P = P->next;
    }
    cout << x << " tidak ditemukan dalam list" << endl;
    return NULL;
}


```
#### Output:
<img width="1089" height="213" alt="Cuplikan layar 2025-11-12 003607" src="https://github.com/user-attachments/assets/b8d27e92-e00a-4eaa-8925-b29a84b68922" />

Program ini menggunakan Singly Linked List yang terdiri dari node dengan info dan pointer next. File singlylist.cpp berisi implementasi fungsi dasar seperti membuat list (createList), membuat node baru (alokasi), menambah elemen di depan list (insertFirst), menampilkan isi list (printInfo), serta mencari elemen tertentu (findElm).

Di singlymain.cpp, program membuat list kosong lalu menambahkan lima elemen ke depan list. Setelah itu, isi list dicetak dan fungsi findElm digunakan untuk mencari nilai 8. Jika ditemukan, program menampilkan pesan bahwa elemen tersebut ada dalam list.

#### Full code Screenshot:
<img width="1333" height="862" alt="image" src="https://github.com/user-attachments/assets/a52c1f31-c139-4046-a7e1-ccea1842f095" />
<img width="1327" height="864" alt="image" src="https://github.com/user-attachments/assets/e2b8d5c4-a6a1-4813-b55d-9d9cca0f60a7" />
<img width="1334" height="863" alt="image" src="https://github.com/user-attachments/assets/1ec69304-b5da-43a2-8df6-dabddae47f67" />

### 
<img width="674" height="189" alt="image" src="https://github.com/user-attachments/assets/71eb9ee5-3bd0-4c8d-bc31-16f3b67cdd88" />

### singlylish.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int sumList(List L);

#endif

```
### singlymain.cpp
```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;

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

    findElm(L, 8);

    cout << "Total info seluruh elemen = " << sumList(L) << endl;

    return 0;
}


```
### singlylist.cpp
```C++
#include <iostream>
#include "singlylist.h"
using namespace std;

void createList(List &L) {
    L.First = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == x) {
            cout << x << " ditemukan dalam list" << endl;
            return P;
        }
        P = P->next;
    }
    cout << x << " tidak ditemukan dalam list" << endl;
    return NULL;
}

int sumList(List L) {
    int total = 0;
    address P = L.First;
    while (P != NULL) {
        total += P->info;
        P = P->next;
    }
    return total;
}


```
#### Output:
<img width="871" height="203" alt="image" src="https://github.com/user-attachments/assets/991bcff3-bc1b-455b-8778-18554ad91652" />

Program ini menggunakan struktur data *singly linked list* dengan node yang dialokasikan secara dinamis menggunakan pointer. Melalui fungsi-fungsi seperti `insertFirst`, `printInfo`, dan `findElm`, program dapat menambah elemen ke awal list, menampilkan isinya, serta mencari nilai tertentu dalam list. Selain itu, program juga menghitung total seluruh nilai elemen menggunakan fungsi `sumList`, yang pada data yang dimasukkan menghasilkan jumlah total 31.**

#### Full code Screenshot:
<img width="1331" height="860" alt="image" src="https://github.com/user-attachments/assets/707639d4-56ea-4438-9ec2-625ba3890e50" />
<img width="1324" height="860" alt="image" src="https://github.com/user-attachments/assets/4e97d6f0-5925-486c-b6ab-3a292c999e75" />
<img width="1334" height="863" alt="image" src="https://github.com/user-attachments/assets/0eecd870-521a-4114-9bff-5e0dd632d183" />



## Kesimpulan

Modul ini memberikan pemahaman tentang cara mengimplementasikan *singly linked list* menggunakan pointer, termasuk proses membuat list, menambah elemen, menelusuri elemen, mencari data tertentu, dan menghitung total nilai dari seluruh node. Melalui latihan ini, mahasiswa belajar bagaimana struktur data dinamis bekerja, bagaimana pengelolaan memori dilakukan dengan alokasi–dealokasi, serta bagaimana operasi dasar pada linked list dijalankan secara efektif.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
