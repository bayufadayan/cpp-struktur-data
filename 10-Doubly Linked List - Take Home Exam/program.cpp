#include <iostream>
#include <stdlib.h>
using namespace std;

struct exam
{
    int nilai;
    exam *next, *prev;
};
exam *first = NULL, *last = NULL, *save, *baru, *sementara, *sementara2, *oke1, *oke2;

void insertfirst(int x){
    baru = new exam;
    baru->nilai = x;
    if (first == NULL)
    {
        first = baru;
        last = baru;
        first->next = NULL;
        first->prev = NULL;
    }else
    {
        first->prev = baru;
        baru->next = first;
        baru->prev = NULL;       
        first = baru;
    }
}

void insertlast(int x){
    baru = new exam;
    baru->nilai = x;
    if (first == NULL)
    {
        first = baru;
        last = baru;
        first->next = NULL;
        first->prev = NULL;
    }else
    {
        last->next = baru;
        baru->prev = last;
        baru->next = NULL;
        last = baru;
    }
}

void insertspecial(int x, int nilaike){
    int jumlah = 0;
    baru = new exam;
    baru->nilai = x;
    if (first == NULL)
    {
        first = baru;
        last = baru;
        first->next = NULL;
        first->prev = NULL;
    }else
    {
        save = first;
        while (save != NULL)
        {
            jumlah++;
            if (jumlah == (nilaike-1))
            {
                baru->next = save->next;
                baru->prev = save;
                if (save->next != NULL) {
                    save->next->prev = baru;
                }
                save->next = baru;
            }
            save = save->next;
        }
    }
}

void insertspecial2(int x, int y){
    baru = new exam;
    baru->nilai = y;
    if (first == NULL)
    {
        first = baru;
        last = baru;
        first->next = NULL;
        first->prev = NULL;
    }else
    {
        save = first;
        while (save != NULL)
        {
            if (save->nilai == x)
            {
                baru->next = save->next;
                baru->prev = save;
                if (save->next != NULL) {
                    save->next->prev = baru;
                }
                save->next = baru;
            }
            save = save->next;
        }
    }
}

void deletespecial(int x, int y){
    save = first;
    while (save != NULL)
    {
        if (save->nilai == x)
        {
            oke1 = save;
            save = save->next;
            sementara = save;
            save = save->next;
            oke2 = save;
            if (save->nilai == y)
            {
                oke1->next = oke2;
                if (oke2 != NULL) {
                    oke2->prev = oke1;
                }
                free (sementara);
                return; // Keluar dari fungsi setelah menghapus dan memperbarui linked list
            }
        } 
    }
}

void cetak(){
    int jumlah = 0;
    save = first;
    while (save != NULL){
        jumlah++;
        cout << jumlah<<". ["<<save->nilai<<"]"<<endl;
        save = save->next;
    }
}

void inisialisasi10(){
    insertfirst(23); insertfirst(62); insertfirst(43); insertfirst(74);insertfirst(53);
    insertfirst(92); insertfirst(41); insertfirst(39); insertfirst(76); insertfirst(14);
}

int main (){
    int pilih, nilai, set, set2;
    bool looping = true;
    inisialisasi10();
    while (looping == true){
        cout << "------------------------------------------------"<<endl;
        cout << "MUHAMAD BAYU FADAYAN - 065121100\nTAKE HOME EXAM\n";
        cout << "========================================"<<endl;
        cout << "Silakan Pilih : \n1. Menambahkan  sebuah nilai integer baru di akhir list.\n2. Menampilkan sebuah nilai integer baru di awal list.\n3. Menyisipkan sebuah nilai integer baru setelah nilai integer tertentu (Nilai integer diinput)\n4. Menghapus sebuah niai integer diantara dua nilai integer tertentu (dua nilai integer diinput).\n5. Menampilkan isi list.\n6. Keluar";
        cout << "\n\nPilihan saya <1 s.d 5> : "; cin >> pilih;
        cout << "========================================"<<endl;

        switch (pilih){
            case 1:
                cout << "Masukan nilai : "; cin >> nilai;
                insertlast(nilai);
                break;
            case 2 :
                cout << "Masukan nilai : "; cin >> nilai;
                insertfirst(nilai);
                break;
            case 3 :
                cout << "Masukan nilai : "; cin >> nilai;
                cout << "Anda akan memasukannya setelah data yang bernilai : "; cin >> set;
                insertspecial2(set, nilai);
                break;
            case 4 :
                cout << "Anda akan menghapus suatu nilai diantara data yang bernilai : "; cin >> set; 
                cout << "Dan data yang bernilai : "; cin >> set2;
                deletespecial(set, set2);
                cetak();
                break;
            case 5 :
                cout << "Menampilkan Data"<<endl;
                cetak(); 
                break;
            case 6 :
                looping = false;
            default:
                break;
        }
    }
    return 0;
}
