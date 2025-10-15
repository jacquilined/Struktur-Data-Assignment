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