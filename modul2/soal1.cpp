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
