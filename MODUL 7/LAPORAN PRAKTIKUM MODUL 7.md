# <h1 align="center">Laporan Praktikum Modul 7 STACK
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori

Stack adalah salah satu struktur data linear yang menerapkan prinsip LIFO (Last In, First Out), yaitu elemen yang terakhir dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan. Stack hanya memiliki satu titik akses data, yaitu bagian atas yang disebut top. Pada implementasinya, stack dapat dibuat menggunakan array maupun linked list, dengan pengelolaan pointer atau indeks untuk menunjukkan posisi elemen teratas.

Operasi dasar pada stack terdiri dari:

Push: memasukkan elemen ke bagian atas stack.

Pop: menghapus elemen dari bagian atas stack.

Peek/Top: melihat elemen teratas tanpa menghapusnya.

isEmpty: memeriksa apakah stack kosong.

isFull: memeriksa apakah stack penuh (khusus implementasi berbasis array).

Stack digunakan dalam berbagai aplikasi, seperti pengelolaan undo-redo, struktur call stack pada proses rekursi, evaluasi ekspresi aritmatika (postfix dan prefix), serta proses parsing dalam compiler.
## Guided 

### main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    
    return 0;
}
```

### stack.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### stack.h

```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack lisStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru); 
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
### main2.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
### stack.cpp

```C++
stack.h 
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
### stack.h

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
## Unguided 

<img width="778" height="691" alt="Cuplikan layar 2025-11-18 225204" src="https://github.com/user-attachments/assets/36e85885-d647-4a1e-8b13-84c4aa027ba2" />


### main1.cpp

```C++
#include <iostream>
#include "stack1.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);


    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```
### stack1.cpp

```C++
#include <iostream>
#include "stack1.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype temp = S.info[S.top];
        S.top--;
        return temp;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }
    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

```

### stack1.h

```C++
#ifndef STACK1_H
#define STACK1_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(const Stack &S);
void balikStack(Stack &S);

// tambahan
void pushAscending(Stack &S, infotype x);

#endif


```


#### Output:

<img width="799" height="69" alt="image" src="https://github.com/user-attachments/assets/59948802-22e9-4a99-a23b-a31076f58498" />


#### Full code Screenshot:
<img width="1474" height="720" alt="Cuplikan layar 2025-11-18 235836" src="https://github.com/user-attachments/assets/669fdf0a-7df0-494e-ba39-05e35de095f4" />
<img width="1478" height="722" alt="Cuplikan layar 2025-11-18 235901" src="https://github.com/user-attachments/assets/fabdf36f-6c69-4109-9a2e-5584c7b72b0a" />
<img width="1476" height="722" alt="Cuplikan layar 2025-11-18 235929" src="https://github.com/user-attachments/assets/9c9c773e-ea8e-486b-a260-532ac9019b2c" />


### 
<img width="699" height="538" alt="Cuplikan layar 2025-11-19 001339" src="https://github.com/user-attachments/assets/29756769-9be0-4a97-afc9-d4ba06fdbc28" />


### main2.cpp
```C++
#include "stack2.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

```
### stack2.cpp
```C++
#include "stack2.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s) {
    if (isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    if (posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s) {
    if (isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i) {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data) {
    if (isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i) {
        if (s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found) {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```
### stack2.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

```
### 
<img width="622" height="307" alt="image" src="https://github.com/user-attachments/assets/2564ecaa-8864-4a22-bd2d-a7b5ba26f6fd" />


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

// WAJIB ADA ↓↓↓
address findElm(List L, infotype x);

#endif

```
#### Output:
<img width="829" height="168" alt="Cuplikan layar 2025-11-19 010405" src="https://github.com/user-attachments/assets/d67aaf01-acb5-4eac-a39b-50e6a7510ce0" />

#### Full code Screenshot:
<img width="1486" height="758" alt="image" src="https://github.com/user-attachments/assets/82338416-37e2-4d6e-a15e-655b6ad8a4cc" />
<img width="1470" height="708" alt="image" src="https://github.com/user-attachments/assets/1462471d-90f2-4862-9f99-2c7fdcf379f0" />
<img width="1469" height="754" alt="image" src="https://github.com/user-attachments/assets/c290c6d7-360e-411a-9629-076467ea4e93" />

### stack3.main
```C++
#include "stack3.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);

    getInputStream(S);

    cout << "\nStack awal:\n";
    printInfo(S);

    cout << "\nBalik stack...\n";
    balikStack(S);

    cout << "Stack setelah dibalik:\n";
    printInfo(S);

    return 0;
}

```
### stack3.cpp
```C++
#include "stack3.h"
#include <iostream>
using namespace std;

void createStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int x) {
    if (isFull(s)) return;
    s.top++;
    s.data[s.top] = x;
}

void pop(Stack &s) {
    if (isEmpty(s)) return;
    s.top--;
}

void printInfo(Stack s) {
    if (isEmpty(s)) {
        cout << "[TOP] (kosong)\n";
        return;
    }

    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void getInputStream(Stack &s) {
    cout << "Masukkan input (tekan ENTER untuk berhenti): ";
    string input;
    getline(cin, input);

    for (char c : input) {
        if (isdigit(c)) {
            push(s, c - '0');
        }
    }
}

// versi balik stack yang TERBUKTI JALAN
void balikStack(Stack &s) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(s)) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    while (!isEmpty(temp)) {
        push(s, temp.data[temp.top]);
        pop(temp);
    }
}

```
### stack3.h
```C++
#ifndef STACK3_H
#define STACK3_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);
void push(Stack &s, int x);
void pop(Stack &s);
void printInfo(Stack s);
void getInputStream(Stack &s);
void balikStack(Stack &s);

#endif


```
#### Output:
<img width="1318" height="358" alt="image" src="https://github.com/user-attachments/assets/7f54b560-5977-43f9-80cc-b33497240be9" />

#### Full code Screenshot:
<img width="1468" height="816" alt="image" src="https://github.com/user-attachments/assets/b05b983e-0031-4078-8026-f05ad41b5c89" />
<img width="1473" height="875" alt="image" src="https://github.com/user-attachments/assets/4e425c8e-918d-47f8-94f6-4cd00f4b9b16" />
<img width="1467" height="848" alt="image" src="https://github.com/user-attachments/assets/ed7a5329-8224-4803-bef7-1901ff3a3854" />



## Kesimpulan

Stack adalah struktur data linear yang menggunakan prinsip LIFO (Last In, First Out), di mana data terakhir yang masuk akan menjadi data pertama yang keluar. Operasi utama pada stack meliputi push, pop, isEmpty, dan isFull. Dari praktikum, dapat disimpulkan bahwa stack hanya dapat diakses melalui satu posisi yaitu TOP, sehingga urutan data sangat bergantung pada perubahan nilai TOP. Stack juga efektif digunakan untuk operasi seperti pembalikan data dan pengolahan data berurutan, namun memiliki keterbatasan kapasitas jika menggunakan array statis.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
