#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int main (){
    char input[100];

    cout << "Nama Barang Anda = "; cin >> input;

    char naga [10] = "CELANA";
    cout << strupr(input);

    if (input == naga)
    {
        cout << endl;
        cout << "===================================="<<endl;
        cout << "CONVERSTING TO UPPERCASE SUCCESSFULL"<<endl;
        cout << "===================================="<<endl;
    }

    getch();
    return 0;
}