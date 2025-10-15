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
