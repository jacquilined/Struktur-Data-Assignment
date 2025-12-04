# <h1 align="center">Laporan Praktikum Doubly Linked List Modul 6
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori

Doubly Linked List (DLL) adalah salah satu struktur data linear yang terdiri dari serangkaian elemen yang disebut node, di mana setiap node menyimpan data dan dua penunjuk (pointer). Satu penunjuk menunjuk ke node berikutnya (next), dan penunjuk lainnya menunjuk ke node sebelumnya (prev). Struktur ini memungkinkan kita melakukan navigasi ke depan maupun ke belakang, berbeda dengan singly linked list yang hanya bisa traversing ke arah satu sisi saja.

Setiap node pada DLL biasanya memiliki tiga bagian utama: data, pointer ke node sebelumnya, dan pointer ke node berikutnya. Node pertama disebut head (atau first), dan node terakhir disebut tail (atau last). Kelebihan dari doubly linked list antara lain fleksibilitas dalam menambahkan atau menghapus elemen di awal, akhir, atau tengah list dengan efisien, karena hanya perlu mengubah beberapa pointer saja, tanpa harus memindahkan seluruh elemen. DLL sering digunakan ketika aplikasi membutuhkan traversal dua arah, seperti dalam manajemen antrean, riwayat browser, undo-redo editor, atau pengelolaan playlist musik.

Operasi dasar yang umum pada DLL meliputi: pembuatan list kosong, penambahan node di awal atau akhir, penghapusan node, pencarian node berdasarkan nilai tertentu, dan traversing maju maupun mundur untuk menampilkan seluruh data. Keuntungan utama dari DLL adalah kemampuan traversal dua arah dan efisiensi dalam manipulasi node, meskipun penggunaan memori lebih besar dibanding singly linked list karena ada dua pointer per node.
## Guided 

### dll_delete.cpp

```C++
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
```

### dll_insert.cpp

```C++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```

## Unguided 

<img width="888" height="507" alt="image" src="https://github.com/user-attachments/assets/84db655a-9b10-430c-9776-98f8a7f96693" />


### singlylist.h

```C++
#include <iostream>
#include "doublylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST:\n";
    while (P != NULL) {
        cout << "No polisi : " << P->info.nopol << endl;
        cout << "Warna    : " << P->info.warna << endl;
        cout << "Tahun    : " << P->info.thnBuat << endl;
        P = P->next;
    }
}


```
### doublylylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

struct ElmList;
typedef ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

#endif

```

### main.cpp

```C++
#include <iostream>
#include <string>
#include "doublylist.h"
using namespace std;

bool isNopolExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
}

int main() {
    List L;
    CreateList(L);
    infotype data;
    string lagi = "y";

    while (lagi == "y" || lagi == "Y") {
        cout << "Masukkan nomor polisi: ";
        getline(cin, data.nopol);

        if (isNopolExist(L, data.nopol)) {
            cout << "Nomor polisi sudah terdaftar!\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, data.warna);

        cout << "Masukkan tahun kendaraan: ";
        string thnStr;
        getline(cin, thnStr);
        data.thnBuat = stoi(thnStr);

        address P = alokasi(data);
        insertLast(L, P);

        cout << "Input lagi? (y/n): ";
        getline(cin, lagi);
    }

    printInfo(L);

    return 0;
}
```

#### Output:
<img width="852" height="431" alt="image" src="https://github.com/user-attachments/assets/fb7a8113-93f9-4aa5-b61d-7c1ce4bc3a9c" />

Kode doubly linked list ini mengimplementasikan struktur data yang menyimpan informasi kendaraan secara dinamis dengan setiap elemen (node) berisi data kendaraan dan dua penunjuk—ke elemen sebelumnya dan berikutnya—memungkinkan navigasi dua arah; program ini membuat list kosong, menambah data kendaraan baru di akhir list tanpa duplikasi nomor polisi, dan menampilkan seluruh data yang tersimpan.

#### Full code Screenshot:
<img width="1917" height="1138" alt="image" src="https://github.com/user-attachments/assets/923c8b5a-c749-4bf3-b2f3-c66287f81b0b" />
<img width="1919" height="1141" alt="image" src="https://github.com/user-attachments/assets/5e3437c2-8a1f-4d3c-9c41-c4a74c50d231" />
<img width="1897" height="1117" alt="image" src="https://github.com/user-attachments/assets/3ab77cb5-6df8-4b10-84cf-99841c1f5cd6" />

### 2.
<img width="671" height="204" alt="image" src="https://github.com/user-attachments/assets/62fb8162-a95a-42ce-a050-89da97177a47" />

### doublylish2.h
```C++
#ifndef DOUBLYLIST2_H
#define DOUBLYLIST2_H

#include <string>
using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteElm(List &L, string nopol);
bool isNopolExist(List L, string nopol);

#endif

```
### doublylist2.cpp
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == NULL) {
        cout << "List kosong.\n";
        return;
    }
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << "----------------------\n";
        P = P->next;
    }
}

bool isNopolExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return NULL;
}

void deleteElm(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == NULL) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan.\n";
        return;
    }

    if (P->prev != NULL) P->prev->next = P->next;
    else L.First = P->next;

    if (P->next != NULL) P->next->prev = P->prev;
    else L.Last = P->prev;

    dealokasi(P);
    cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
}

```
### main2.cpp
```C++
#include <iostream>
#include <string>
#include "doublylist2.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    string lagi = "y";

    while (lagi == "y" || lagi == "Y") {
        cout << "Masukkan nomor polisi: ";
        getline(cin, data.nopol);

        if (isNopolExist(L, data.nopol)) {
            cout << "Nomor polisi sudah terdaftar!\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, data.warna);

        cout << "Masukkan tahun kendaraan: ";
        string thnStr;
        getline(cin, thnStr);
        data.thnBuat = stoi(thnStr);

        insertLast(L, alokasi(data));

        cout << "Input lagi? (y/n): ";
        getline(cin, lagi);
    }

    cout << "\nDATA LIST:\n";
    printInfo(L);

    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dicari: ";
    getline(cin, cariNopol);

    address P = findElm(L, cariNopol);
    if (P != NULL) {
        cout << "\nData kendaraan ditemukan:\n";
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }

    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    deleteElm(L, hapusNopol);

    cout << "\nDATA LIST SESUDAH HAPUS:\n";
    printInfo(L);

    return 0;
}

```
#### Output:
<img width="1340" height="399" alt="image" src="https://github.com/user-attachments/assets/119c3168-5a81-4a7a-800c-6e0ddebc6843" />

Kode program ini digunakan untuk mencari data polisi dengan menginputtkan kode.
#### Full code Screenshot:
<img width="1919" height="1137" alt="image" src="https://github.com/user-attachments/assets/7ce365da-fea4-4357-9df0-9099c686f113" />
<img width="1911" height="1125" alt="image" src="https://github.com/user-attachments/assets/32fcd35f-6aa5-415a-84f8-f3ae42ea1d72" />
<img width="1919" height="1139" alt="image" src="https://github.com/user-attachments/assets/bb12a612-1a64-4c65-bfdd-d4e78402991d" />


### 3.
<img width="633" height="374" alt="image" src="https://github.com/user-attachments/assets/da2a7550-c78f-4b46-831a-3e45ee5fb9d7" />

### doublylish2.h
```C++
#ifndef DOUBLYLIST2_H
#define DOUBLYLIST2_H

#include <string>
using namespace std;

struct infotype {
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteElm(List &L, string nopol);
bool isNopolExist(List L, string nopol);

#endif

```
### doublylist2.cpp
```C++
#include "doublylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    if (P == NULL) {
        cout << "List kosong.\n";
        return;
    }
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << "----------------------\n";
        P = P->next;
    }
}

bool isNopolExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
}

address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return NULL;
}

void deleteElm(List &L, string nopol) {
    address P = findElm(L, nopol);
    if (P == NULL) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan.\n";
        return;
    }

    if (P->prev != NULL) P->prev->next = P->next;
    else L.First = P->next;

    if (P->next != NULL) P->next->prev = P->prev;
    else L.Last = P->prev;

    dealokasi(P);
    cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
}

```
### main2.cpp
```C++
#include <iostream>
#include <string>
#include "doublylist2.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    infotype data;
    string lagi = "y";

    while (lagi == "y" || lagi == "Y") {
        cout << "Masukkan nomor polisi: ";
        getline(cin, data.nopol);

        if (isNopolExist(L, data.nopol)) {
            cout << "Nomor polisi sudah terdaftar!\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, data.warna);

        cout << "Masukkan tahun kendaraan: ";
        string thnStr;
        getline(cin, thnStr);
        data.thnBuat = stoi(thnStr);

        insertLast(L, alokasi(data));

        cout << "Input lagi? (y/n): ";
        getline(cin, lagi);
    }

    cout << "\nDATA LIST:\n";
    printInfo(L);

    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dicari: ";
    getline(cin, cariNopol);

    address P = findElm(L, cariNopol);
    if (P != NULL) {
        cout << "\nData kendaraan ditemukan:\n";
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cariNopol << " tidak ditemukan.\n";
    }

    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapusNopol);
    deleteElm(L, hapusNopol);

    cout << "\nDATA LIST SESUDAH HAPUS:\n";
    printInfo(L);

    return 0;
}

```
#### Output:
<img width="701" height="344" alt="image" src="https://github.com/user-attachments/assets/86ee04e1-e4a5-4cad-bbea-90c8e2fbdf36" />


Kode program ini digunakan untuk menghapus data mobil polisi kode ini juga merupakan kode lanjutan dari soal kedua. 
#### Full code Screenshot:
<img width="1919" height="1137" alt="image" src="https://github.com/user-attachments/assets/7ce365da-fea4-4357-9df0-9099c686f113" />
<img width="1911" height="1125" alt="image" src="https://github.com/user-attachments/assets/32fcd35f-6aa5-415a-84f8-f3ae42ea1d72" />
<img width="1919" height="1139" alt="image" src="https://github.com/user-attachments/assets/bb12a612-1a64-4c65-bfdd-d4e78402991d" />

## Kesimpulan

Modul ini membahas tentang struktur data Doubly Linked List, yaitu daftar linear dinamis di mana setiap elemen (node) memiliki penunjuk ke node sebelumnya dan berikutnya, memungkinkan traversing dua arah. Dalam modul ini, dipelajari cara membuat list kosong, menambah node di awal atau akhir, mencari node berdasarkan kriteria tertentu, menghapus node, dan menampilkan seluruh isi list. DLL sangat berguna ketika aplikasi membutuhkan navigasi maju-mundur atau manipulasi data yang efisien di tengah list. Modul ini juga menekankan pentingnya alokasi dan dealokasi memori, pengecekan duplikasi data, serta penerapan konsep DLL dalam program nyata, seperti pengelolaan data kendaraan.

## Referensi
Modul 6 Doubly Linked List 
