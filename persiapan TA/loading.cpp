#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

void loading(string a){
    int x = 1;
    cout << "\t" << a;
    while (x <= 6){
        Sleep(900);
        cout << ".";
        x++;
    }
}

void logo(){
    string line;
    ifstream file;
    file.open("logo2.txt");
    while(file){
        getline(file, line);
        cout << line << endl;
    }
}

int main (){
    cout << "KLIK ENTER UNTUK MELIHAT!"<<endl;
    getch();
    system("cls");
    loading("sedang memuat\n\t");

    system("cls");
    cout << "SAYA BAYU!"<<endl;
    getch();

    return 0;
}