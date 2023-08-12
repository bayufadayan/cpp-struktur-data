#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct DaftarTugas
{
    string matkul, deadline, tugasnya;

    DaftarTugas *next;
};
DaftarTugas *first, *last, *save, *baru, *hapustengah;

void insertfirst(string matkul, string deadline, string tugasnya){
    baru = new DaftarTugas;
    baru->matkul = matkul;
    baru->deadline = deadline;
    baru->tugasnya = tugasnya;

    if (first == NULL)
    {
        first = baru;
        last = baru;
        first->next = NULL;
    }else
    {
        baru->next = first;
        first = baru;
    }
}
void insertlast(string matkul, string deadline, string tugasnya){
    baru = new DaftarTugas;
    baru->matkul = matkul;
    baru->deadline = deadline;
    baru->tugasnya = tugasnya;

    if (first == NULL)
    {
        first = baru;
        last = baru;

        last->next = NULL;
    }else
    {
        last->next = baru;
        last = baru;
    }
    last->next = NULL;
}
void inserttertentu(string matkul, string deadline, string tugasnya, int datatengah){
    int jumlah = 0;
    baru = new DaftarTugas;
    baru->matkul = matkul;
    baru->deadline = deadline;
    baru->tugasnya = tugasnya;

    if (first == NULL)
    {
        first = baru;
        last = baru;

        first->next = NULL;
    }else
    {
        save = first;
        while (save != NULL)
        {
            jumlah++;
            if (jumlah == (datatengah-1))
            {
                baru->next = save->next;
                save->next = baru;
            }
            save = save->next;
        }
    }
}
void deletefirst(){
    save = first;
    first = first->next;
    free(save);
}
void deletelast(){
    save = first;
    while (save->next != last)
    {
        save = save->next;
    }
    last = save;
    free(save->next);
    last->next = NULL;
}
void deletetertentu(int datatengah){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        if (jumlah == (datatengah-1))
        {
            hapustengah = save->next;
            save->next = hapustengah->next;
            free(hapustengah);
        }
        save = save->next;
    }
}
void deletekeyword(string keyword){
    int jumlah = 0; int datakeyword;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        if (save->matkul == keyword)
        {
            datakeyword = jumlah;
        }
        save = save->next;
    }
    if (datakeyword == 1)
    {
        deletefirst();
    }else
    {
        deletetertentu(datakeyword);
    }
}
void caritugas(string keyword){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        if (save->matkul == keyword)
        {
            jumlah++;
            cout << "======================================="<<endl;
            cout << "Mata Kuliah    : "<<save->matkul<<endl;
            cout << "Batas Waktu    : "<<save->deadline<<endl;
            cout << "Tugas          : "<<save->tugasnya<<endl;
        }
        save = save->next;
    }
    if (save == NULL)
        {
           if (jumlah == 0)
           {
               cout << "\nTugas tidak ditemukan!\n"<<endl;
           }else
           {
                cout << "======================================="<<endl;
                cout << "Ditemukan "<<jumlah<<" tugas!"<<endl;
           } 
        }
}
void edittugas(string keyword){
    save = first;
    while (save != NULL)
    {
        if (save->matkul == keyword)
        {
            cout << "Berikut data yang ingin kamu edit!"<<endl;
            cout << "======================================="<<endl;
            cout << "Mata Kuliah    : "<<save->matkul<<endl;
            cout << "Batas Waktu    : "<<save->deadline<<endl;
            cout << "Tugas          : "<<save->tugasnya<<endl;
            cout << "======================================="<<endl;
            cout << "Silakan edit : "<<endl;
            cout << "Mata Kuliah    : ";getline(cin,save->matkul);
            cout << "Batas Waktu    : ";getline(cin,save->deadline);
            cout << "Tugas          : ";getline(cin,save->tugasnya);
            cout << "---------------------------"<<endl;
            cout << "Tugas berhasil diedit!"<<endl;
            cout << "---------------------------"<<endl;
        }
        save = save->next;
    }
}

void cetak_linkedlist(){
    save = first;
    while (save != NULL)
    {
        cout << "======================================="<<endl;
        cout << "Mata Kuliah    : "<<save->matkul<<endl;
        cout << "Batas Waktu    : "<<save->deadline<<endl;
        cout << "Tugas          : "<<save->tugasnya<<endl;

        save = save->next;
    }
    if (save == NULL)
    {
        cout << "======================================="<<endl;
    }
}
void calculate_tugas(){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        save = save->next;
    }
    cout << jumlah;
}
void pesansukses_tambah(){
    cout << "---------------------------"<<endl;
    cout << "Tugas berhasil ditambahkan!"<<endl;
    cout << "---------------------------"<<endl;
}
void pesansukses_hapus(){
    cout << "---------------------------"<<endl;
    cout << "Tugas berhasil dihapus!"<<endl;
    cout << "---------------------------"<<endl;
}
void inputsalah(){
    cout << "Input salah! Silakan Ulangi"<<endl;
}

int main(){
//pendeklarasian dan inisialisasi
    first = NULL; last = NULL;
    string matkul, deadline, tugasnya, keyword, backmenu;
    int datatengah, pilih1, pilih2;
//Daftar menu
    do
    {
        system("cls");
        cout << "   <DAFTAR TUGAS KULIAH BAYU>   "<<endl;
        cout << "================================"<<endl;
        cout << "-----------DAFTAR MENU----------"<<endl;
        cout << "================================"<<endl;
        cout << "1. Tambah Tugas\n2. Hapus Tugas\n3. Hitung Tugas\n4. Tampilkan Tugas\n5. Cari Tugas\n6. Edit Tugas\n7. Keluar"<<endl;
        cout << "================================"<<endl;
        cout << "Pilih <1 s.d 7> : "; cin >> pilih1;

    //masuk ke fungsi sesuai nomor
        if (pilih1 == 1)
        {
            system("cls");
            cout << "================================"<<endl;
            cout << "--------MENU TAMBAH TUGAS-------"<<endl;
            cout << "================================"<<endl;
            cout << "1. Tambah diawal\n2. Tambah diakhir\n3. Tambah pada urutan tertentu"<<endl;
            cout << "\nPilih <1/2/3> : "; cin >> pilih2;

            if ((pilih2 >= 1)&&(pilih2 <= 3))
            {
                cin.ignore();
                cout << "Mata Kuliah    : "; getline (cin,matkul);
                cout << "Batas waktu    : "; getline (cin, deadline);
                cout << "Tugas          : "; getline (cin, tugasnya);
            }
            
            if (pilih2 == 1)
            {
                insertfirst(matkul, deadline, tugasnya);
                pesansukses_tambah();
            }else if (pilih2 == 2)
            {
                insertlast (matkul, deadline, tugasnya);
                pesansukses_tambah();
            }else if (pilih2 == 3)
            {
                if (first == NULL)
                {
                    cout << "\nTugas masih kosong! Inputan anda akan menjadi tugas pertama!"<<endl;
                    insertfirst(matkul, deadline, tugasnya);
                }else
                {
                    cout << "\nAnda mempunyai ";calculate_tugas();cout << " tugas!"<<endl;
                    cout << "Ingin memasukan tugas ini pada urutan (pakai angka): "; cin >> datatengah;
                    if (datatengah == 1)
                    {
                        insertfirst(matkul, deadline, tugasnya);
                    }else
                    {
                        inserttertentu(matkul, deadline, tugasnya, datatengah);
                    }
                }
                pesansukses_tambah();
            }else
            {
                inputsalah();
            }
            
        }else if (pilih1 == 2)
        {
            system("cls");
            cout << "================================"<<endl;
            cout << "--------MENU HAPUS TUGAS--------"<<endl;
            cout << "================================"<<endl;
            cout << "1. Hapus tugas paling awal\n2. Hapus tugas paling akhir\n3. Hapus tugas urutan tertentu\n4. Hapus tugas dengan kata kunci"<<endl;
            cout << "\nPilih <1/2/3> : "; cin >> pilih2;

            if (pilih2 == 1)
            {
                deletefirst();
                pesansukses_hapus();
            }else if (pilih2 == 2)
            {
                deletelast();
                pesansukses_hapus();
            }else if (pilih2 == 3)
            {
                cout << "\nAnda mempunyai ";calculate_tugas();cout << " tugas!"<<endl;
                cout << "Ingin menghapus tugas pada urutan (pakai angka): "; cin >> datatengah;
                deletetertentu(datatengah);
                pesansukses_hapus();
            }else if ((pilih2 == 4))
            {
                cin.ignore();
                cout << "*huruf kapital mempengaruhi"<<endl;
                cout << "Masukan Mata Kuliah yang ingin dihapus : "; getline(cin, keyword);
                deletekeyword(keyword);
                pesansukses_hapus();
            }else
            {
                inputsalah();
            }
            
        }else if (pilih1 == 3)
        {
            cout << "-------------------------"<<endl;
            cout << "Anda mempunyai ";calculate_tugas();cout << " tugas!\nSilakan diperiksa.."<<endl;
            cout << "-------------------------"<<endl;

        }else if (pilih1 == 4)
        {
            system("cls");
            cout << "================================"<<endl;
            cout << "----MENAMPILAKAN TUGAS-TUGAS----"<<endl;
        
            if (first == NULL)
            {
                cout << "================================"<<endl;
                cout << "\nTidak ada tugas tersedia!\n"<<endl;
            }else
            {
                cetak_linkedlist();
            }

        }else if (pilih1 == 5)
        {
            system("cls");
            cout << "================================"<<endl;
            cout << "---------PENCARIAN TUGAS--------"<<endl;
            cout << "================================"<<endl;
            cout << "Masukan nama mata kuliah : ";
            cin.ignore();
            getline(cin, keyword);
            caritugas(keyword);

        }else if (pilih1 == 6)
        {
            system("cls");
            cout << "================================"<<endl;
            cout << "-----------EDIT TUGAS-----------"<<endl;
            cout << "================================"<<endl;
            cout << "Masukan nama mata kuliah : ";
            cin.ignore();
            getline(cin, keyword);
            edittugas(keyword);

        }else if (pilih1 == 7)
        {
            getch();
            return 0;
        }
        // else if (pilih1 == 8)
        // {
        //     sorting();
        // }
        else
        {
            inputsalah();
        }

        cout <<"\nKembali ke menu <y/n> : ";cin >> backmenu;

    } while (backmenu == "y");
    
    getch();
    return 0;
}