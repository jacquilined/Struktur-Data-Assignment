# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori

Dalam pemrograman, operasi aritmatika merupakan salah satu konsep dasar yang digunakan untuk melakukan perhitungan matematis. Bahasa C++ menyediakan operator aritmatika seperti + (penjumlahan), - (pengurangan), * (perkalian), dan / (pembagian) yang dapat digunakan langsung pada variabel bertipe numerik.

Input dari pengguna dapat diterima menggunakan perintah cin, sedangkan hasil perhitungan ditampilkan ke layar menggunakan perintah cout. Program sederhana dengan operator aritmatika membantu praktikan memahami bagaimana data diproses dari input hingga menghasilkan output.

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1.  Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>

using namespace std;

int main(){
    int a;
    int b;

    cout << "Masukan Angka Pertama : ";
    cin >> a;
    cout << "Masukan Angka Kedua : ";
    cin >> b;

    cout << "a + b =" << (a+b) << endl;
    cout << "a - b =" << (a-b) << endl;
    cout << "a * b =" << (a*b) << endl;
    cout << "a / b =" << (a/b) << endl;

    return 0;
    
}
```
#### Output:
<img width="1184" height="225" alt="image" src="https://github.com/user-attachments/assets/ddd726fa-72b3-4b24-9986-8853dee806dd" />

kode ini digunakan untuk mendemonstrasikan operasi aritmatika dasar dengan input dari pengguna.
#### Full code Screenshot:
<img width="1759" height="929" alt="image" src="https://github.com/user-attachments/assets/0fa9d34e-27bc-443a-9389-00764b4ad601" />

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100 contoh: 79: tujuh puluh Sembilan

```C++
#include <iostream>
using namespace std;

int main(){
    int angka;

    cout << "Masukan angka(0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100){
        cout << "Input antara 0 - 100." << endl;
        return 0;
    }

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh",
                       "sebelas", "dua belas", "tiga belas", "empat belas",
                       "lima belas", "enam belas", "tujuh belas", "delapan belas",
                       "sembilan belas"};

                       if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka < 20) {
        cout << satuan[angka] << endl;
    } else {
        string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh",
                           "lima puluh", "enam puluh", "tujuh puluh",
                           "delapan puluh", "sembilan puluh"};
        int p = angka / 10;
        int s = angka % 10;
        cout << puluhan[p];
        if (s != 0) cout << " " << satuan[s];
        cout << endl;
    }
    return 0;

}
```
#### Output:
<img width="1147" height="108" alt="image" src="https://github.com/user-attachments/assets/d81f2154-88f9-4887-8799-5484517be79a" />
kode diatas digunakan untuk menerima input sebuah angka dari pengguna (dalam rentang 0–100), lalu mengubah angka tersebut menjadi bentuk tulisan kata dalam bahasa Indonesia.

#### Full code Screenshot:
<img width="1759" height="927" alt="image" src="https://github.com/user-attachments/assets/0be9e3f0-f677-4cab-a1b5-913a24319f53" />

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100 contoh: 79: tujuh puluh Sembilan

```C++
#include <iostream>
using namespace std;

int main(){
    int angka;

    cout << "Masukan angka(0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100){
        cout << "Input antara 0 - 100." << endl;
        return 0;
    }

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh",
                       "sebelas", "dua belas", "tiga belas", "empat belas",
                       "lima belas", "enam belas", "tujuh belas", "delapan belas",
                       "sembilan belas"};

                       if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka < 20) {
        cout << satuan[angka] << endl;
    } else {
        string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh",
                           "lima puluh", "enam puluh", "tujuh puluh",
                           "delapan puluh", "sembilan puluh"};
        int p = angka / 10;
        int s = angka % 10;
        cout << puluhan[p];
        if (s != 0) cout << " " << satuan[s];
        cout << endl;
    }
    return 0;

}
```
#### Output:
<img width="1147" height="108" alt="image" src="https://github.com/user-attachments/assets/d81f2154-88f9-4887-8799-5484517be79a" />
kode diatas digunakan untuk menerima input sebuah angka dari pengguna (dalam rentang 0–100), lalu mengubah angka tersebut menjadi bentuk tulisan kata dalam bahasa Indonesia.

#### Full code Screenshot:
<img width="1759" height="927" alt="image" src="https://github.com/user-attachments/assets/0be9e3f0-f677-4cab-a1b5-913a24319f53" />

### 3.  Buatlah program yang dapat memberikan input dan output sbb.
input: 3
output:
3 2 1 * 1 2 3
  2 1 * 1 2
    1 * 1
      *
Gambar 1. 25 Mirror

```C++
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output: "<< endl;

    for (int i = n; i >= 1; i--){

        for (int j = i; j >= 1; j--){
            cout << j << " ";
        }

        cout << "* ";

        for (int j =1; j <= i;  j++){
            cout << j;
            if (j != i) cout << " ";
        }

        cout << endl;
    }

    cout << "*" << endl;
    
    return 0;
}
```
#### Output:
<img width="1140" height="250" alt="image" src="https://github.com/user-attachments/assets/e9661a7d-fcc8-48e3-bd2f-629c86529606" />


kode ini digunakan untuk menghasilkan pola cermin (mirror) angka sesuai input.
#### Full code Screenshot:
<img width="1759" height="926" alt="image" src="https://github.com/user-attachments/assets/540e3561-09ac-4b88-9cfb-04d17146c5e6" />




## Kesimpulan
Program yang dibuat mampu menerima dua input bilangan dari pengguna dan menampilkan hasil dari operasi penjumlahan, pengurangan, perkalian, serta pembagian. Dari percobaan ini dapat disimpulkan bahwa operator aritmatika di C++ bekerja sesuai dengan aturan matematika dasar dan dapat diimplementasikan dengan mudah untuk berbagai kebutuhan perhitungan.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
