#include <iostream>
#include <conio.h>
using namespace std;

void border(){
    cout << "====================================="<<endl;
}
int Tambah (int x, int y){
    int z;
    cout << x<<" + "<<y<<" = ";
    z = x+y;
    cout <<z<<endl;
    return z;
}
int Kurang (int x, int y){
    int z;
    cout << x<<" - "<<y<<" = ";
    z = x-y;
    cout <<z<<endl;
    return z;
}
int Kali (int x, int y){
    int z;
    cout << x<<" x "<<y<<" = ";
    z = x*y;
    cout <<z<<endl;
    return z;
}
int Bagi (int x, int y){
    int z;
    cout << x<<" : "<<y<<" = ";
    z = x/y;
    cout <<z<<endl;
    return z;
}

int main (){

    int a, b, tambah, kurang, bagi, kali;

    border();
    cout << "Kalkulator Sederhana"<<endl;
    border();

    cout <<"Masukan angka pertama : "; cin >> a;
    cout <<"Masukan angka kedua : "; cin >> b;
    
    tambah = Tambah(a,b);
    kurang = Kurang(a,b);
    kali = Kali(a,b);
    bagi = Bagi(a,b);

    getch ();
    return 0;

}