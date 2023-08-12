#include <iostream>
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

        first->next = NULL;
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
        if (datatengah == 1)
        {
            deletefirst();
        }
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
            // hapustengah = save->next;
            // save->next = hapustengah->next;
            // free(hapustengah);
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
int calculate_tugas(){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        save = save->next;
    }
    return jumlah;
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
        }
        save = save->next;
        if (save == NULL)
        {
            cout << "data tidak ada, tulis namanya yg bener!"<<endl;
        }
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

int main(){
insertfirst("satu","satu","satu");
insertfirst("dua","dua","dua");
insertfirst("tiga","tiga","tiga");
insertfirst("empat","empat","empat");
cout << "==========(1)============" << endl;
cetak_linkedlist();
cout << endl <<endl<<endl;
deletekeyword("satu");
cout << "==========(2)============" << endl;
cetak_linkedlist();
cout << endl <<endl<<endl;
cout << "==========(3)============" << endl;
cetak_linkedlist();
cout << endl <<endl<<endl;
edittugas("dua");
cout << "==========(4)============" << endl;
cetak_linkedlist();
cout << endl <<endl<<endl;
inserttertentu("saki","saki","saki",4);
cout << "==========(5)============" << endl;
cetak_linkedlist();


}