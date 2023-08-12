#include <iostream>
#include <conio.h>
using namespace std;

int angka = 4;

void tambah10 (int &angka){
    angka = angka + 10;
}

int main (){
    tambah10(angka);
    cout << "4 + 10 adalah "<< angka <<endl;
}