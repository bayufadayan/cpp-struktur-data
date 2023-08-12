#include <iostream>
using namespace std;

struct TugasKuliah
{
    string matkul;
    TugasKuliah *next;
};

TugasKuliah *first, *temp, *baru;

void InsertFirst(string matkul)
{
    baru = new TugasKuliah; // Buat node baru
    baru->matkul = matkul;  // Set nilai matkul
    baru->next = first;     // Atur next dari node baru ke first
    first = baru;           // Atur first menjadi node baru
}

void cetaklikedlist()
{
    TugasKuliah *jalan = first;
    while (jalan != NULL)
    {
        cout << jalan->matkul << endl; // Cetak nilai matkul
        jalan = jalan->next;
    }
}

int main()
{
    InsertFirst("Algoritma");
    InsertFirst("Aljabar");
    InsertFirst("Indonesia");
    InsertFirst("Inggris");
    InsertFirst("Agama");
    InsertFirst("Statistika");
    cetaklikedlist();

    return 0;
}
