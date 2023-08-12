#include <iostream>
using namespace std;

struct TugasKuliah
{
    string matkul;

    TugasKuliah *next;
};

TugasKuliah *first, *temp, *baru;

// TugasKuliah alokasikan (string matkul){
//     temp = new TugasKuliah;
//     temp->matkul = matkul;
//     return *temp;
// }

void InsertFirst (string matkul){
    temp = new TugasKuliah;
    temp->matkul = matkul;
    temp = baru;
    baru->next=first;
    first = baru;
}

void cetaklikedlist(){
    TugasKuliah *jalan = first;
    while (jalan != NULL)
    {
        cout << jalan <<endl;
        jalan = jalan->next;
    }   
}

int main (){
    InsertFirst("Algoritma");
    cetaklikedlist();
}
