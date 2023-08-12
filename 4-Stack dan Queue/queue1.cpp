//Muhamad Bayu Fadayan - 065121100;
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

//variabel global
string tugas[100];
const int maksimal = 100;
int jumlah = 0;

//kumpulan fumgsi fungsi
bool isempty(){
    return jumlah == 0;
}
bool isfull(){
    return jumlah >= maksimal;
}
int sisadata(){
    return maksimal - jumlah;
}
int count(){
    return jumlah;
}
void enqueue(){
    if (isfull())
    {
        cout << "\nTugas anda penuh!\nSilakan selesaikan dulu...\n"<<endl;
        return;
    }

    string input_tugas;
    cout << "-------------------------------\nMasukan Tugas : ";
    cin.ignore();
    getline(cin, input_tugas);

    jumlah++;
    tugas[jumlah] = input_tugas;
    cout << "\n==================================="<<endl;
    cout << "---[Tugas berhasil di Tambahkan]---"<<endl;
    cout << "===================================\n"<<endl;
}
void dequeue(){
    if (isempty())
    {
        cout << "\nMasih belum ada tugas!\nSantay aja...\n"<<endl;
        return;
    }

    for (int i = 1; i <= jumlah; i++)
    {
        tugas[i] = tugas[i + 1];
    }
    jumlah--;

    cout << "\n==================================="<<endl;
    cout << "-----[Tugas berhasil di hapus]----"<<endl;
    cout << "===================================\n"<<endl;
}
void clear(){
    jumlah = 0;
    cout << "\n==================================="<<endl;
    cout << "---Semua tugas berhasil di hapus---"<<endl;
    cout << "===================================\n"<<endl;
}
void print(){
    int angka = 0;
    if (isempty())
    {
        cout << "\nMasih belum ada tugas!\nSantay aja...\n"<<endl;
        return;
    }

    cout << endl;
    for (int i = 1; i <= jumlah; i++)
    {
        angka++;
        cout << "Tugas "<<angka<<". "<<tugas[i]<<endl;
    }
    cout << endl;
}
void backmenu(){
    cout << "--<ENTER UNTUK MEMILIH MENU>--"<<endl;
    getch();
}

//Fungsi Utama
int main (){

    //pendeklarasian
    string line; //utk operasi file
    int pilih;
    bool ulangsendiri = true;

    while (ulangsendiri)
    {
        system("cls");
        ifstream baca;
        baca.open("buatatas2.txt");
        while (baca)
        {
            getline(baca, line);
            cout << line << endl;
        }
        cout << "1. Cek Tugas\n2. Tambah Tugas\n3. Hapus Tugas Pertama\n4. Hapus Semua Tugas\n5. Tampilkan Tugas\n6. Keluar"<<endl; 
        cout << "-------------------------------"<<endl;
        cout << "Pilih <1-6> : "; cin >> pilih;

        switch (pilih)
        {
        case 1:
            if (isempty())
            {
                cout << "\nMasih belum ada tugas!\nSantay aja...\n"<<endl;
                backmenu(); break;
            }else if (isfull())
            {
                cout << "\nTugas anda penuh!\nSilakan selesaikan dulu...\n"<<endl;
                backmenu(); break;
            }else
            {
                cout << "\nSudah ada " << count() << " tugas" << endl;
                cout << "dan masih sisa " << sisadata() << " ruang\n" << endl;
                backmenu(); break;
            }
        
        case 2:
            enqueue();
            backmenu(); break;

        case 3:
            dequeue();
            backmenu(); break;

        case 4:
            clear();
            backmenu(); break;

        case 5:
            print();
            backmenu(); break;

        case 6:
            cout << "\nYahh! Malah Keluar\nYaudah deh :)\n"<<endl;
            ulangsendiri = false;
            break;
        
        default:
            cout << "\nTolong inputkan sesuai nomer yang tersedia!"<<endl;
            cout << "Yaitu 1 - 6\n"<<endl;
            backmenu(); break;
        }
    }
    
    return 0;
}