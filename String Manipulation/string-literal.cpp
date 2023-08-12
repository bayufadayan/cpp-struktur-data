#include <iostream>
using namespace std;

int main (){
    //Nama Awal
    char nama[9] = "Abimanyu";
    cout << "Nama Awal : "<<nama<<endl;

    //nama akhir
    char *ptr;
    ptr = nama;
    *(ptr + 3) = 'y';
    cout << "Nama menjadi : "<< nama << endl;
}