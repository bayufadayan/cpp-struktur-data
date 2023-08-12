#include <iostream>
#include <conio.h>
using namespace std;

int main (){
    int a[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "a["<<i<<"] = ";
        cin >> a[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Nilai elemen ke-"<<i+1<<" = "<<a[i]<<endl;
    }
    
    getch();
    return 0;
}