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

### 4. main2.cpp

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

### 1. Array
<img width="794" height="63" alt="Cuplikan layar 2025-10-08 223818" src="https://github.com/user-attachments/assets/7ee24b30-6b7d-4389-bd8a-dc48870dcb65" />

```C++
#include <iostream>
using namespace std;

int main(){
    int i,j,k;
    int A[3][3], B[3][3], C[3][3];
    int pilihan;

    cout << "\nMasukan elemen matriks A (3x3):\n";
    for ( i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << 
            "A[" << i << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
        
    }
    cout << "\nMasukan elemen matriks B (3x3) :\n";
    for ( i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++){
            cout << "B[" << i + 1 << "][" << j + 1 << "] = ";
             cin >> B[i][j];       
        }
    }
    
    cout << "\nPilih operasi:\n";
    cout << "1. Penjumlahan\n";
    cout << "2. Pengurangan\n";
    cout << "3. Perkalian\n";
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    C[i][j] = A[i][j] + B[i][j];
            cout << "\nHasil Penjumlahan Matriks (A + B):\n";
            break;

        case 2:
            for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                    C[i][j] = A[i][j] - B[i][j];
            cout << "\nHasil Pengurangan Matriks (A - B):\n";
            break;

        case 3:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    C[i][j] = 0;
                    for (k = 0; k < 3; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            cout << "\nHasil Perkalian Matriks (A x B):\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            return 0;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="1291" height="711" alt="Cuplikan layar 2025-10-08 224314" src="https://github.com/user-attachments/assets/df5578d8-e733-4299-9ddc-b5ac2da5723c" />

Kode tersebut digunakan untuk melakukan operasi aritmetika pada dua matriks berordo 3x3, yaitu penjumlahan, pengurangan, atau perkalian, sesuai pilihan pengguna.
#### Full code Screenshot:
<img width="1759" height="930" alt="Cuplikan layar 2025-10-08 230114" src="https://github.com/user-attachments/assets/a4cac099-05d9-460c-a287-7840105ae09d" />

### 2. Pointer
<img width="771" height="58" alt="Cuplikan layar 2025-10-08 224520" src="https://github.com/user-attachments/assets/0070adfd-77f7-4e88-97b0-f4e01e4ac117" />

```C++
#include <iostream>
using namespace std;

void tukar3(int *x,int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main(){
    int a = 10, b=20, c=30;

    cout << "Sebelum ditukar :\n";
    cout << "a = " << a << "b = " << b << "c = " << c << endl;

    tukar3(&a, &b,&c);

    cout << "Setelah Ditukar :\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
```
#### Output:
<img width="1220" height="134" alt="Cuplikan layar 2025-10-08 224645" src="https://github.com/user-attachments/assets/feb342f5-b15b-4e3a-8edf-3e6d74d68c06" />

Kode tersebut digunakan untuk menukar nilai tiga variabel (a, b, dan c) secara bergantian menggunakan pointer. Setelah fungsi tukar3 dijalankan, nilai a menjadi nilai b, b menjadi c, dan c menjadi a.

#### Full code Screenshot:
<img width="1759" height="926" alt="Cuplikan layar 2025-10-08 224658" src="https://github.com/user-attachments/assets/014dd419-4dee-4b27-a375-492164b3afe0" />


### 3. Array
<img width="819" height="370" alt="image" src="https://github.com/user-attachments/assets/fd5352d6-4f5a-4331-97bc-3faa2cfc57f8" />

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata = " << rata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
```
#### Output:
<img width="1303" height="788" alt="Cuplikan layar 2025-10-08 225644" src="https://github.com/user-attachments/assets/be63e7c8-6a69-4d2f-8372-5695b4bcf9f4" />

Kode tersebut digunakan untuk mengolah data array satu dimensi dengan menampilkan menu pilihan untuk:

Menampilkan isi array.

Mencari nilai maksimum.

Mencari nilai minimum.

Menghitung nilai rata-rata.

Program akan terus berjalan sampai pengguna memilih menu keluar (5).

#### Full code Screenshot:
<img width="1757" height="929" alt="Cuplikan layar 2025-10-08 225716" src="https://github.com/user-attachments/assets/fa46bf02-3edb-4039-8e12-34dbd7ae452c" />

## Kesimpulan
Modul ini menjelaskan dasar penggunaan fungsi, pointer, reference, dan array dalam bahasa C++. Melalui percobaan program, mahasiswa dapat memahami bagaimana fungsi digunakan untuk membagi program menjadi bagian yang lebih terstruktur, serta bagaimana pointer dan reference memungkinkan perubahan nilai variabel secara langsung melalui alamat memori. Selain itu, penggunaan array membantu dalam pengolahan data yang jumlahnya banyak secara lebih efisien. Dengan menguasai konsep-konsep ini, pemrogram dapat menulis kode yang lebih rapi, efisien, dan mudah dikembangkan.
## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
