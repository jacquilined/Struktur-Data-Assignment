#include <iostream>
using namespace std;

void tukar3(int *x,int *y, int *z){
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main(){
    int a = 10, b=20, c=30;

    cout << "Sebelum ditukar :\n";
    cout << "a = " << a << "b = " << b << "c = " << c << endl;

    tukar3(&a, &b,&c);

    cout << "Setelah Ditukar :\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}