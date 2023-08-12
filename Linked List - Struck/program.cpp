#include <iostream>
#include <conio.h>
using namespace std;

struct TugasKuliah
{
    string matkul, deadline, tugasnya;

    TugasKuliah *next;
}; 

TugasKuliah *awal, *akhir, *baru, *bantu;

void buatdata_awal (string matkul, string deadline, string tugasnya){
    baru = new TugasKuliah;
    baru->matkul = matkul;
    baru->deadline = deadline;
    baru->tugasnya = tugasnya;

    if (awal == NULL)
    {
        awal = baru;
        akhir = baru;
        baru->next = NULL;
    }else
    {
        baru->next=awal;
        awal = baru;
        baru->next = NULL;
    }
}

void contohdata (){
    buatdata_awal("Algoritma Strukdat", "24 Maret 2022", "Buat Program Linked List");
    buatdata_awal("Aljabar Linear", "28 Maret 2022", "Buat Invers Matriks");
    buatdata_awal("Matematika Diskrit", "30 Maret 2022", "Tugas Fungsi");
}

void cetaklinkedlist(){
    bantu = awal;
    while (bantu != NULL)
    {
        cout << "Mata Kuliah    : "<<bantu->matkul << endl;
        cout << "Deadline       : "<<bantu->deadline << endl;
        cout << "Tugasnya       : "<<bantu->tugasnya << endl;

        bantu = bantu->next;
    }
    
}

int main (){
    
    contohdata();
    cetaklinkedlist ();
    return 0;
}