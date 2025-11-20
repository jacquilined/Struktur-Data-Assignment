#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>

const int MAX = 6;

struct Mahasiswa {
    std::string Nama;
    std::string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa data[MAX];
    int top;
};

bool isEmpty(const StackMahasiswa &S);
bool isFull(const StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, const Mahasiswa &mhs);
void Pop(StackMahasiswa &S);
void View(const StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi, const Mahasiswa &mhsBaru);
float HitungNilaiAkhir(const Mahasiswa &m);
void SearchNilaiAkhir(const StackMahasiswa &S, float minAkhir, float maxAkhir);
void MaxNilaiAkhir(const StackMahasiswa &S);

#endif