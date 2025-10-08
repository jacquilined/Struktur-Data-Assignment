# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ 2>
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori

Program pertukaran tiga variabel menggunakan pointer didasarkan pada konsep dari fungsi, parameter, dan pointer dengan menggunakan bahasa C++.

1. Fungsi dan Parameter

Fungsi digunakan untuk memecah program menjadi bagian-bagian yang lebih kecil. Data dapat dikirim ke fungsi melalui parameter. Jika parameter dikirim dengan cara by value, maka hanya salinan nilainya yang dikirim dan variabel asli tidak berubah. Namun jika dikirim dengan pointer atau by reference, maka alamat memori variabel dikirim sehingga fungsi dapat langsung mengubah nilai asli variabel tersebut.

2. Pointer

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, fungsi dapat mengakses dan memodifikasi nilai variabel yang berada di luar fungsi. Penggunaan operator * (dereference) berfungsi untuk mengakses nilai yang disimpan pada alamat memori tersebut.

3. Variabel Sementara (temp)

Variabel sementara digunakan untuk menyimpan nilai salah satu variabel agar nilainya tidak hilang saat proses pertukaran berlangsung. Tanpa temp, nilai awal variabel akan tertimpa oleh nilai variabel lain.

4. Proses Pertukaran Nilai

Langkah pertukaran pada fungsi tukar3 yaitu:

Simpan nilai pertama ke variabel temp
Geser nilai kedua ke variabel pertama
Geser nilai ketiga ke variabel kedua
Geser nilai dari temp ke variabel ketiga
Hasilnya, ketiga nilai saling berpindah posisi sesuai urutan logika fungsi.

Secara keseluruhan, konsep ini menunjukkan bagaimana penggunaan pointer memungkinkan perubahan nilai variabel secara langsung di luar fungsi tanpa perlu mengembalikan nilai dari fungsi tersebut.
## Guided 

### 1. Reference

```C++
#include <iostream>
using namespace std;

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl; 
    cout << "Alamat ref (&ref): " << &ref << endl; 

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; 

    return 0;
}

```
Program ini digunakan untuk mempelajari konsep reference pada bahasa C++ dan penggunaannya dalam pertukaran nilai dua variabel melalui fungsi. Dengan menggunakan parameter reference (&), nilai variabel asli dapat diubah langsung di dalam fungsi tanpa harus menggunakan pointer.

### 2. Pointer

```C++
#include <iostream>
using namespace std;

void tukar (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl; 
    cout << "Value pointed to by ptr: " << *ptr << endl; //ditunjuk pointer yg isinya 20

    tukar(&a, &b); //&a->*
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; //berhasil ditukar

    return 0;
}
```
Program ini menunjukkan cara kerja pointer untuk menukar nilai dua variabel melalui alamat memori. Pointer menyimpan alamat variabel lain, sehingga fungsi dapat mengubah nilai aslinya menggunakan operator *.

### 3. Array

```C++
#include <iostream>
using namespace std;

int main() {
    // Array 1 Dimensi
    int arr1D[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 Dimensi:" << endl;
    for (int i = 0; i < 5; i++) { //
        cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
    }
    cout << endl;

    // Array 2 Dimensi (baris x kolom)
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Array Multi Dimensi (3D)
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };
    cout << "Array 3 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = "<< arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
Program ini dibuat untuk menampilkan isi array 1 dimensi, 2 dimensi, dan 3 dimensi di C++. Tujuannya agar dapat memahami struktur dan cara akses elemen array dengan indeks baris, kolom, dan dimensi.

### 4. Fungsi Prosedur

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
Kode di atas digunakan untuk menampilkan tulisan “Baris ke-” sebanyak jumlah yang dimasukkan user.

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
