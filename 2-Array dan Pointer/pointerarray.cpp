#include <iostream>
using namespace std;

int main (){
    int angka[5];
    int *p;

    p = angka;
    *p = 10;
    p++;
    *p = 20;
    p = &angka[2];
    *p = 30;
    p = angka + 3;
    *p = 40;
    
}