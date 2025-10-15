# <h1 align="center">LAPORAN PRAKTIKUM MODUL 3 ABSTRACT DATA TYPE (ADT) 
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori

Abstract Data Type (ADT) atau Tipe Data Abstrak merupakan konsep pemrograman yang memisahkan antara definisi suatu tipe data dengan implementasi dari operasinya. ADT mendeskripsikan apa yang dapat dilakukan oleh suatu tipe data tanpa harus mengetahui bagaimana cara kerja di dalamnya. Dengan menggunakan ADT, pemrograman menjadi lebih terstruktur, mudah dipelihara, dan mendukung prinsip modularitas.

Tujuan utama dari penerapan ADT adalah agar program dapat dikelola dengan lebih baik melalui pemisahan bagian spesifikasi dan implementasi. Spesifikasi berisi deklarasi tipe dan fungsi yang menjelaskan operasi apa saja yang tersedia, sedangkan implementasi berisi kode nyata dari operasi-operasi tersebut. Dengan cara ini, perubahan pada implementasi tidak akan memengaruhi bagian lain dari program selama spesifikasinya tetap sama.

Komponen utama dalam ADT meliputi:

- Tipe data: struktur atau bentuk data yang didefinisikan, misalnya struct mahasiswa atau struct pelajaran.

- Konstruktor: fungsi pembentuk untuk membuat objek bertipe tersebut.

- Selector: fungsi untuk mengambil atau membaca nilai dari komponen data.

- Mutator: fungsi untuk mengubah nilai komponen data.

- Validator dan Destruktor: berfungsi untuk memeriksa validitas data dan menghapus data dari memori.

- Fungsi input/output: digunakan untuk membaca dan menampilkan data ke pengguna.

Dalam implementasi menggunakan bahasa C++, ADT biasanya dipisahkan menjadi tiga bagian file:

1. File header (.h) → berisi definisi tipe dan deklarasi fungsi (spesifikasi).

2. File implementasi (.cpp) → berisi kode fungsi secara lengkap (realisasi dari spesifikasi).

3. File utama (main.cpp) → berisi program utama yang menggunakan fungsi-fungsi dari ADT (driver).

Pada praktikum ini, konsep ADT diterapkan dengan membuat tipe data seperti mahasiswa dan pelajaran, serta mendefinisikan operasi untuk menginput, menghitung nilai, dan menampilkan data tersebut. Selain itu, latihan juga mencakup penggunaan array 2 dimensi dan pointer yang diolah menggunakan fungsi dan prosedur, untuk memperkuat pemahaman tentang cara kerja ADT dalam mengelola data secara modular dan terstruktur.
## Guided 

### Mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif 
```

### Mahasiswa.cpp

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m) {
    cout << "Input nama = ";
    cin >> m.nim;
    cout << "Input nilai 1 = ";
    cin >> m.nilai1;
    cout << "Input nilai 2 = ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2.0;
}
//realisasi
```
### Main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
 
```

## Unguided 

### 1. Soal 1
<img width="861" height="82" alt="image" src="https://github.com/user-attachments/assets/ef37c54a-7c66-42b1-be0f-456f0d0f0341" />

# soal1.h
```C++
#ifndef SOAL1_H
#define SOAL1_H

#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    int NIM;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// deklarasi fungsi
void inputMhs(mahasiswa &m);
float average(mahasiswa m);

#endif


```
# soal1.cpp
```C++
#include <iostream>
#include "soal1.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Nama : ";
    cin >> m.nama;
    cout << "NIM : ";
    cin >> m.NIM;
    cout << "Nilai UTS : ";
    cin >> m.uts;
    cout << "Nilai UAS : ";
    cin >> m.uas;
    cout << "Nilai Tugas Akhir : ";
    cin >> m.tugas;
}

float average(mahasiswa m) {
    return 0.3f * m.uts + 0.4f * m.uas + 0.3f * m.tugas;
}

```
# main1.h
```C++
#include <iostream>
#include "soal1.h"
using namespace std;

int main() {
    mahasiswa data[10];
    int n;

    cout << "Masukan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Maximal hanya 10 Mahasiswa!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        inputMhs(data[i]);
        data[i].nilaiAkhir = average(data[i]);
    }

    cout << "\n== Data Mahasiswa ==\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama         : " << data[i].nama << endl;
        cout << "NIM          : " << data[i].NIM << endl;
        cout << "UTS          : " << data[i].uts << endl;
        cout << "UAS          : " << data[i].uas << endl;
        cout << "Tugas        : " << data[i].tugas << endl;
        cout << "Nilai Akhir  : " << data[i].nilaiAkhir << endl;
        cout << "------------------------------\n";
    }

    return 0;
}


```
#### Output:
<img width="896" height="819" alt="image" src="https://github.com/user-attachments/assets/266e3c46-b39b-4a48-b82f-3f2727555657" />


Ketiga kode tersebut digunakan untuk menerapkan konsep **Abstract Data Type (ADT)** dengan memisahkan deklarasi, implementasi, dan program utama agar program lebih terstruktur dan mudah dikelola.

#### Full code Screenshot:
<img width="1759" height="933" alt="image" src="https://github.com/user-attachments/assets/577f7008-e40c-43c2-951b-0b0cd60931e1" />
<img width="1759" height="929" alt="image" src="https://github.com/user-attachments/assets/930fff7f-0e4c-448c-a815-d300cd7da723" />
<img width="1758" height="929" alt="image" src="https://github.com/user-attachments/assets/5368056f-17b1-4994-b065-349b0cd287df" />




### 2. Soal 2
<img width="729" height="512" alt="image" src="https://github.com/user-attachments/assets/7cdedca4-2c1a-43fc-a815-32523fbd09d1" />
# soal2.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);

void tampilkan_pelajaran(pelajaran pel);

#endif
```
# soal2.cpp
```C++
#include "soal2.h"

pelajaran create_pelajaran(string namaMapel, string kodeMapel){
    pelajaran pel;
    pel .namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

void tampilkan_pelajaran(pelajaran pel){
    cout << "Nama Mata Pelajaran :" << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran :" << pel. kodeMapel << endl;
}
```
# main2.cpp
```C++
#include <iostream>
#include "soal2.h"
using namespace std;

int main(){
    string namapel ;
    string kodepel;

    cout << "Struktur Data";
    cin >> namapel;
    cout << "SDT";
    cin >> kodepel;

    pelajaran pel = create_pelajaran(namapel,kodepel);
    tampilkan_pelajaran(pel);

    return 0;
}
```
#### Output:
<img width="833" height="107" alt="image" src="https://github.com/user-attachments/assets/2b480f18-c46c-436e-9556-2936ed794b22" />

#### Full code Screenshot:
<img width="1759" height="930" alt="image" src="https://github.com/user-attachments/assets/4341b486-5dc0-4488-9a85-fb3bcd556a48" />
<img width="1759" height="930" alt="image" src="https://github.com/user-attachments/assets/e601c51d-4932-4607-a419-81d1720f022c" />
<img width="1759" height="930" alt="image" src="https://github.com/user-attachments/assets/cc8c2cc7-6d72-4d11-8437-45a33321d604" />



### 3. Soal 3
<img width="677" height="89" alt="image" src="https://github.com/user-attachments/assets/e62b2cba-d92a-409f-86f8-c7cb3d8af9f2" />
<img width="641" height="42" alt="image" src="https://github.com/user-attachments/assets/0b1c8fca-9f8b-4128-baa1-a1acb4718b63" />

```C++
#include <iostream>
using namespace std;

void tampilkanArray(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int array1[3][3], int array2[3][3], int baris, int kolom) {
    int temp = array1[baris][kolom];
    array1[baris][kolom] = array2[baris][kolom];
    array2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *ptr1, *ptr2;
    int x = 10, y = 20;
    ptr1 = &x;
    ptr2 = &y;

    cout << "Array A sebelum ditukar:\n";
    tampilkanArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilkanArray(B);

    cout << "\nMenukar elemen baris 1 kolom 2 antara A dan B...\n\n";
    tukarPosisi(A, B, 1, 2);

    cout << "Array A setelah ditukar:\n";
    tampilkanArray(A);
    cout << "\nArray B setelah ditukar:\n";
    tampilkanArray(B);

    cout << "\nSebelum tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Setelah tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

```
#### Output:
<img width="1262" height="642" alt="image" src="https://github.com/user-attachments/assets/45ea11dd-ff52-403a-b315-27f460f70390" />

Program ini digunakan untuk menampilkan isi dua array 2D, menukar elemen tertentu antara dua array, dan menukar nilai dua variabel melalui pointer sebagai penerapan konsep array, fungsi, dan pointer dalam C++.

#### Full code Screenshot:
<img width="1759" height="930" alt="image" src="https://github.com/user-attachments/assets/d96c3b96-961f-4905-acc7-33f3978af7ff" />


## Kesimpulan
Kesimpulan dari modul ini adalah bahwa penggunaan array, fungsi, dan pointer memungkinkan pengelolaan data menjadi lebih efisien dan terstruktur. Dengan memahami cara menampilkan data, menukar elemen array, serta memanipulasi nilai melalui pointer, kita dapat mengimplementasikan konsep Abstract Data Type (ADT) dan pengolahan data secara dinamis dalam pemrograman C++.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
