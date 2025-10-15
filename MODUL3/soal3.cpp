#include <iostream>
using namespace std;

void tampilkanArray(int array[3][3]){ //nampilin array
    for (int i = 0; i < 3; i++){
        for (int j = 0; i < 3; j++){
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

//tukar isi dua elemen array 2D

void tukarPosisi(int array1[3][3], int array2[3][3], int baris, int kolom){
    int temp = array1[baris][kolom];
    array1[baris][kolom] = array2[baris][kolom];
    array2[baris][kolom] = temp;
}

//tukar fungsi u/ menukar isi dua variabel yang ditunjuk oleh pointer
void tukarPointer(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int *ptr1, *ptr2;
    int x = 10, y = 20;
    ptr1 = &x;
    ptr2 = &y;

    cout << "Array A sebelum ditukar:\n";
    tampilkanArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilkanArray(B);

    cout << "\nMenukar elemen baris 1 kolom 2 antara A dan B...\n\n";
    tukarPosisi(A, B, 1, 2); 

    cout << "Array A setelah ditukar:\n";
    tampilkanArray(A);
    cout << "\nArray B setelah ditukar:\n";
    tampilkanArray(B);

    cout << "\nSebelum tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(ptr1, ptr2);

    cout << "Setelah tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}