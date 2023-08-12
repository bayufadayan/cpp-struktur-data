#include <iostream>
#include <conio.h>
using namespace std;

void cetakarray (int arg[], int panjang){
    for (int n = 0; n < panjang; n++)
    {
        cout << arg[n]<<" ";
    }
    
}

int main (){

    int arraypertama [] = {5,10,15};
    int arraykedua[]= {2,4,6,8,10};

    cetakarray(arraypertama, 3);
    cout << endl;
    
    getch();
    return 0;
}