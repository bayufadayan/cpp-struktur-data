#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
using namespace std;

struct gudang
{
    string barang;

    gudang *next;
};
gudang *first, *last, *save, *baru, *temp;

void insertfirst(string barang){
    baru = new gudang;
    baru->barang = barang;

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

void deletefirst(){
    save = first;
    first = first->next;
    free(save);
}

void deletetertentu(int datatengah){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        if (jumlah == (datatengah-1))
        {
            temp = save->next;
            save->next = temp->next;
            free(temp);
        }
        save = save->next;
    }
}

void cetak_all(){
    save = first;
    int count = 0;
    if (first == NULL) {
        cout << "Barang Kosong!"<<endl;
    }
    else
    {
        while (save != NULL)
        {
            count++;
            cout << count <<". Nama Barang Tersedia    : "<<save->barang<<endl;

            save = save->next;
        }
        if (save == NULL)
        {
            cout << "======================================="<<endl;
        }
    }
}

void hapus_all(){
    save = first;
    while (save != NULL)
    {
        free(save);
        save = save->next;
    }
    
}

void calculate_all(){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        save = save->next;
    }
    cout << jumlah;
}

int calculate_keyword(string keyword){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        if (save->barang == keyword)
        {
            jumlah++;
        }
        save = save->next;
    }
    return jumlah;
}
void pesansukses_tambah(){
    cout << "---------------------------"<<endl;
    cout << "Barang berhasil ditambahkan!"<<endl;
    cout << "---------------------------"<<endl;
}
void pesansukses_hapus(){
    cout << "---------------------------"<<endl;
    cout << "Barang berhasil dihapus!"<<endl;
    cout << "---------------------------"<<endl;
}
void inputsalah(){
    cout << "Input salah! Silakan Ulangi"<<endl;
}
void backmenu(){
    cout << "--<ENTER UNTUK MEMILIH MENU>--"<<endl;
    getch();
    system("cls");
}

void contoh_barang(){
    insertfirst("Baju");insertfirst("Celana");insertfirst("Rok");insertfirst("Helm");
}

int main(){

    //pendeklarasian
    string barang, keyword;
    bool looping = true;
    int pilih, pilih2, data_tengah;
    char pilih3; string keyword2;

    contoh_barang();
    do
    {
        string line;
        ifstream file;
        file.open("pemanis.txt");
        while (file)
        {
            getline(file, line);
            cout << line << endl;
        }   
        cout << "Pilihan Saya <1/2/3/4/5>: "; cin >>pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukan Nama Barang : ";
            cin.ignore();
            getline(cin, barang);

            insertfirst(barang);
            pesansukses_tambah();
            backmenu();
            break;
        
        case 2:
            cout <<"1. Hapus Barang Terdahulu"<<endl;
            cout <<"2. Hapus Barang Urutan Tertentu"<<endl;
            cout << "Pilihan Saya <1/2> : "; cin >> pilih2;

            switch (pilih2)
            {
            case 1:
                deletefirst();
                pesansukses_hapus();
                backmenu();
                break;

            case 2:
                cout << "Ingin Menghapus barang ke : "; cin >> data_tengah;
                deletetertentu(data_tengah);
                pesansukses_hapus();
                backmenu();
                break;
            default:
                break;
            }

        case 3:
            cout << "==========================================="<<endl;
            cout << "Daftar Nama Semua Barang Yang Ada di gudang"<<endl;
            cout << "==========================================="<<endl;
            cetak_all();
            backmenu();
            break;

        case 4: 
            cout << "Jumlah Barang Digudang saat ini : ";calculate_all();
            cout << endl;
            cout << "Ingin Mengecek Spesifik Barang ? "<<endl;
            cout << "Pilihan saya <y/n> : "; cin >> pilih3; cout << endl;
            if (pilih3 == 'y')
            {
                cout << "Masukan Kata Kunci : "; cin.ignore();
                getline(cin, keyword2);
                cout << "Jumlah Barang "<<keyword2<<" : "<<calculate_keyword(keyword2);
                cout << endl;
            }
            backmenu();
            break;
                
        case 5:
            looping = false;
            break;

        default:
            break;
        }

    } while (looping);
    
}