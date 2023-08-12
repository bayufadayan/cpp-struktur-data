#include <iostream>
using namespace std;

int main (){
    int angka [5]= {2,4,1,3,4};
    int *p;

    p = angka;
    *p = 10;

    cout << "-----------" << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "-----------" << endl;

    p++;
    *p = 20;

    cout << "-----------" << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "-----------" << endl;

    p = &angka[2];
    *p = 30;

    cout << "-----------" << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "-----------" << endl;

    p = angka + 3;
    *p = 40;

    cout << "-----------" << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << "-----------" << endl;
    
    cin.get();
    return 0;
}