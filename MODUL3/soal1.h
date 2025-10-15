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
