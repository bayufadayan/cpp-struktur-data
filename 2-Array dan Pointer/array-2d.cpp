#include <iostream>
using namespace std;

int main (){

    int baris, kolom;
    cout << "Baris : "; cin >> baris;
    cout << "Kolom : "; cin >> kolom; cout << endl;
    int a[baris][kolom];



    //memasukan inputan
    for (auto i = 0; i < baris; i++)
    {
        for (auto j = 0; j < kolom; j++)
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
    
    cin.get();
    return 0;
}