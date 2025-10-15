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
