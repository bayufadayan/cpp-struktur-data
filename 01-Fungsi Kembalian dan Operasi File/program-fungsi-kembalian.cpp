#include <iostream>
#include <conio.h>
using namespace std;

void border(){
    cout << "====================================="<<endl;
}
float Tambah (float x, float y){
    float z;
    cout << x<<" + "<<y<<" = ";
    z = x+y;
    cout <<z<<endl;
    return z;
}
float Kurang (float x, float y){
    float z;
    cout << x<<" - "<<y<<" = ";
    z = x-y;
    cout <<z<<endl;
    return z;
}
float Kali (float x, float y){
    float z;
    cout << x<<" x "<<y<<" = ";
    z = x*y;
    cout <<z<<endl;
    return z;
}
float Bagi (float x, float y){
    float z;
    cout << x<<" : "<<y<<" = ";
    z = x/y;
    cout <<z<<endl;
    return z;
}

int main (){

    float a, b, tambah, kurang, bagi, kali;

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