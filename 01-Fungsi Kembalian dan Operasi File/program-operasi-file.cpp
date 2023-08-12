#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int main (){
    cout << "Sekarang saya akan membuat filenya"<<endl;

    ofstream intro;
    intro.open("perkenalan.txt");
    //sekarang sedang merekam teks yang akan di tulis

    intro << "Halo nama saya Bayu"<<endl;
    intro << "Saya seorang remaja berusia 18 tahun"<<endl;
    intro << "Saya ingin menambahkan 1 dan 2"<<endl;
    intro << "1 + 2 adalah "<<1+2<<endl;
    intro.close();

    cout << "Nih dah jadi file nya"<<endl;
    string line1, line2;
    ifstream baca;
    ifstream bacayglaen;
    baca.open("perkenalan.txt");
    bacayglaen.open ("Corat Coret.txt");

    while (baca)
    {
        getline(baca, line1);
        cout << line1 <<endl;
    }

    cout << "Sekarang kita baca dari dokumen yang laen"<<endl;

    while (bacayglaen)
    {
        getline(bacayglaen, line2);
        cout << line2 <<endl;
    }



    getch();
    return 0;
}