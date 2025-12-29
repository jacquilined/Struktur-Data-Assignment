# <h1 align="center">Laporan Praktikum Modul 8 QUEUE
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori
Queue (dibaca: kyu) merupakan struktur data yang dapat diumpamakan seperti sebuah antrean. Misalkan antrean pada loket pembelian tiket Kereta Api, di mana orang-orang berdiri berurutan menunggu giliran mereka. Orang yang akan mendapatkan pelayanan yang pertama adalah orang yang pertamakali masuk dalam antrean tersebut, sedangkan yang terakhir masuk dia akan mendapatkan layanan yang terakhir pula. Hal ini menunjukkan bahwa prinsip dasar dalam Queue adalah FIFO (First In First Out), yang artinya proses yang pertama masuk akan diakses terlebih dahulu, dan proses yang terakhir masuk akan diakses paling akhir. Konsep ini sangat penting dalam berbagai sistem komputer, misalnya pada antrian print di printer, penjadwalan proses di sistem operasi, atau penanganan permintaan data pada jaringan komputer. Dalam pengimplementasian struktur Queue dalam bahasa pemrograman C, Queue dapat dibuat menggunakan tipe data array, di mana elemen-elemen disimpan secara berurutan dalam indeks tertentu, atau menggunakan linked list, yang memungkinkan penambahan dan penghapusan elemen secara dinamis tanpa batasan ukuran tetap. Dengan demikian, Queue menjadi salah satu struktur data fundamental yang efisien untuk mengatur urutan proses atau data yang masuk dan keluar berdasarkan prinsip FIFO.
## Guided 

### queue.h

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

### queue.cpp

```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```

### main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
### queue.h

```C++
// guided2 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1 
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```
### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

// //isFull implmenetasi 1 & 2
// bool isFull(queue Q){
//     if(Q.tail == MAKSIMAL - 1){
//         return true;
//     } else {
//         return false;
//     }
// }

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 
// //enqueue implementasi 1 & 2
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //dequeue implementasi 1
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         for(int i = 0; i < Q.tail; i++){
//             Q.nama[i] =  Q.nama[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// //viewQueue implementasi 1 & 2
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = Q.head; i <= Q.tail; i++){
//             cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
//         }
//     }
//     cout << endl;
// }

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}
```
### main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
## Unguided 
<img width="838" height="710" alt="image" src="https://github.com/user-attachments/assets/ad458da5-e8b8-4d64-b774-21bc19538be4" />

### main1.cpp

```C++
#include <iostream>
#include "soal1.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    return 0;
}

```
### soal1.cpp

```C++
#include <iostream>
#include "soal1.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

// --------- ENQUEUE (head diam, tail maju) ---------
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    // Geser elemen ke kiri
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < Q.head) {  
        Q.head = -1;
        Q.tail = -1;
    }

    return temp;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```

### soal1.h

```C++
#include <iostream>
#include "soal1.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype temp = Q.info[Q.head];

    // Geser elemen ke kiri
    for (int i = Q.head; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < Q.head) {  
        Q.head = -1;
        Q.tail = -1;
    }

    return temp;
}

// --------- PRINT INFO ---------
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

```
#### Output:
<img width="792" height="339" alt="Screenshot 2025-11-27 201647" src="https://github.com/user-attachments/assets/a2e1a7bd-b64f-435c-9714-5b527b7e66aa" />

#### Full code Screenshot:
<img width="1919" height="1141" alt="image" src="https://github.com/user-attachments/assets/472045d1-94ed-4a8c-bdcc-dec3ef5c57a9" />
<img width="1912" height="1130" alt="image" src="https://github.com/user-attachments/assets/3c579b5e-a935-49a0-91e4-02f12ec0a64d" />
<img width="1919" height="1139" alt="image" src="https://github.com/user-attachments/assets/0b079e59-8ebe-4786-b504-d509291e9fac" />


### 
<img width="565" height="40" alt="image" src="https://github.com/user-attachments/assets/952640ad-0202-4eac-8b46-31cb6614ecf6" />

### main2.cpp
```C++
#include <iostream>
#include "soal2.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    return 0;
}

```
### soal2.cpp
```C++
#include <iostream>
#include "soal2.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) { 
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << "\t| ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

```
### soal2.h
```C++
#ifndef SOAL2_H
#define SOAL2_H

const int MAX = 5;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head, tail;
} Queue;

// Prosedur dan fungsi
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### Output:
<img width="878" height="269" alt="image" src="https://github.com/user-attachments/assets/f5f8d059-d8e1-486e-90c0-a8888ddb686a" />


#### Full code Screenshot:
<img width="1919" height="1136" alt="image" src="https://github.com/user-attachments/assets/9329d1ae-752c-4355-8bb9-5678efc0fd42" />
<img width="1917" height="1140" alt="image" src="https://github.com/user-attachments/assets/8d99bfc5-eff8-4ecc-9a97-d5f1afd2cb0a" />
<img width="1917" height="1136" alt="image" src="https://github.com/user-attachments/assets/d7b216b4-e397-456a-b991-7fc08e82b6b7" />


####
<img width="556" height="40" alt="image" src="https://github.com/user-attachments/assets/77a82d8a-08f2-44f1-8e20-008ba0bf631f" />

### main3.cpp
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

#endif

```
### stack3.main
```C++
#include <iostream>
#include "soal3.h"
using namespace std;

int main() {
    cout << "Circular Queue" << endl;

    Queue Q;
    createQueue(Q);

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    return 0;
}

```
### stack3.cpp
```C++
#include <iostream>
#include "soal3.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {  
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
        return;
    }

    cout << Q.head << " - " << Q.tail << "\t| ";

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

```
### stack3.h
```C++
#ifndef SOAL3_H
#define SOAL3_H

const int MAX = 5;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head, tail;
} Queue;

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```
#### Output:
<img width="763" height="264" alt="image" src="https://github.com/user-attachments/assets/decf69d8-970e-40ae-a854-bd09fd4ba60a" />

#### Full code Screenshot:
<img width="1911" height="1132" alt="image" src="https://github.com/user-attachments/assets/8e8fbfa6-6011-4831-80c3-52cfe03c3d6e" />
<img width="1908" height="1130" alt="image" src="https://github.com/user-attachments/assets/0de2398f-466b-4490-af30-8fa6ac149c76" />
<img width="1915" height="1137" alt="image" src="https://github.com/user-attachments/assets/91b3a65b-a921-4f4a-a9a9-7e22f4737934" />

## Kesimpulan
Queue adalah struktur data linear yang menggunakan prinsip FIFO (First In First Out), di mana elemen pertama yang masuk akan keluar lebih dulu. Queue memiliki operasi dasar seperti enqueue (menambah elemen), dequeue (menghapus elemen), serta pengecekan kosong/penuh. Implementasinya bisa berupa head diam – tail bergerak, head dan tail bergerak, atau circular queue, di mana circular queue paling efisien karena memanfaatkan seluruh array tanpa penggeseran. Queue banyak digunakan untuk mengatur antrian dalam sistem nyata seperti printer, buffering data, dan task scheduling.


## Referensi
Modul 8 queue
