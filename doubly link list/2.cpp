#include <iostream>
using namespace std;

//node-nya
struct exam
{
    int nilai;

    exam *next, *prev;
};
exam *first, *last, *save, *baru, *sementara, *oke1, *oke2;

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
        oke1 = save->prev;
        oke2 = save->next;
        if ((oke1->nilai == x)&&(oke2->nilai == y)){

            sementara = save;
                 
            oke1->next = save->next;
            oke2->prev = save->prev;
            delete sementara;
        
        }
        save = save->next;
    }
}


void cetak(){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        cout << jumlah<<". ["<<save->nilai<<"]"<<endl;

        save = save->next;
    }
}

void inisialisasi10(){
    insertfirst(23); insertfirst(62); insertfirst(43); insertfirst(74);insertfirst(53);
    insertfirst(62); insertfirst(53); insertfirst(39); insertfirst(26); insertfirst(14);
}

int main (){

    //inisialisasi pointer
    exam *first = NULL, *last = NULL;

    int pilih, nilai, set, set2;
    bool looping = true;
    inisialisasi10();
    while (looping == true)
    {
    cout << "MUHAMAD BAYU FADAYAN - 065121100\nTAKE HOME EXAM\n";
    cout << "========================================"<<endl;
    cout << "Silakan Pilih : \n1. Menambahkan  sebuah nilai integer baru di akhir list.\n2. Menampilkan sebuah nilai integer baru di awal list.\3. Menyisipkan sebuah nilai integer baru setelah nilai integer tertentu (Nilai integer diinput)\n4. Menghapus sebuah niai integer diantara dua nilai integer tertentu (dua nilai integer diinput).\n5. Menampilkan isi list.\n6. Keluar";
    cout << "\n\nPilihan saya <1 s.d 5> : "; cin >> pilih;
    cout << "========================================"<<endl;

    switch (pilih)
    {
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
        break;

    case 5 :
        cout << "Menampilkan Data"<<endl;
        cetak();

    case 6 :
        looping = false;
    
    default:
        cout << "input salah!"<<endl;
        break;
    }
    
    }


    return 0;
}