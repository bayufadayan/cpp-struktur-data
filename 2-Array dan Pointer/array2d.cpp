#include <iostream>
#include <conio.h>
using namespace std;

int main (){

    int a[baris][kolom];

    //memasukan inputan
    for (auto i = 0; i < baris; i++)
    {
        for (auto j = 0; i < kolom; j++)
        {
            cout << "a["<<i<<"]["<<j<<"] = ";
            cin >> a[i][j];
        }
        cout << "\n";
        
    }
    
    //mengeluarkan hasil inputan
    for (auto i = 0; i < baris; i++)
    {
        for (auto j = 0; j < kolom; j++)
        {
            cout << "Nilai elemen ke-"<<i+1<<" & "<<j+1<<" = "<< a[i][j] << endl;
        }
        
    }
    
    getch();
    return 0;
}