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