#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

Mahasiswa M(string n, string nim, float t, float u, float a){
    return {n,nim,t,u,a};
}

int main(){
    StackMahasiswa S;
    createStack(S);

    Push(S, M("Venti","11111",75.7,82.1,65.5));
    Push(S, M("Xiao","22222",87.4,88.9,81.9));
    Push(S, M("Kazuha","33333",92.3,88.8,82.4));
    Push(S, M("Wanderer","44444",95.5,85.5,90.5));
    Push(S, M("Lynette","55555",77.7,65.4,79.9));
    Push(S, M("Chasca","66666",99.9,93.6,87.3));

    cout << "\n=== Stack Awal ===\n";
    View(S);

    Pop(S);

    cout << "\n=== Setelah Pop 1x ===\n";
    View(S);

    Update(S, 3, M("Heizou","77777",99.9,88.8,77.7));

    cout << "\n=== Setelah Update Posisi 3 ===\n";
    View(S);

    cout << "\n=== Searching NilaiAkhir 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    cout << "\n=== Nilai Akhir Terbesar ===\n";
    MaxNilaiAkhir(S);

    return 0;
}
