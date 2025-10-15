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