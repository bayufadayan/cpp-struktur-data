#include <iostream>
#include <stdlib.h>
using namespace std;

struct TugasKuliah
{
    string matkul, deadline, tugasnya;
    
    TugasKuliah *next;
};

TugasKuliah *first, *last, *save, *newData;

void insertfirst(string matkul, string deadline, string tugasnya){
    newData = new TugasKuliah;
    newData->matkul = matkul;
    newData->deadline = deadline;
    newData->tugasnya = tugasnya;
    if (first == NULL)
    {
        first = newData;
        last = newData;

        first->next=NULL;
    }else
    {
        newData->next=first;
        first = newData;
    }
}

void insertlast(string matkul, string deadline, string tugasnya){
    newData = new TugasKuliah;
    newData->matkul = matkul;
    newData->deadline = deadline;
    newData->tugasnya = tugasnya;

    if (first == NULL)
    {
        first = newData;
        last = newData;
    }else
    {
        last->next = newData;
        last = newData;
    }
    last->next=NULL;
    
}

void deletefirst(){
    save = first;
    first=first->next;
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

void node_calculate(){
    int length = 0;
    save = first;
    while (save != NULL)
    {
        length++;
        save = save->next;
    }
    cout << length << endl;
}
// void deletekeyword(string keyword){
//     save = first;
//     while (save != NULL)
//     {
//         if (save->matkul == keyword)
//         {
//             hapustengah = save->next;
//             save->next = hapustengah->next;
//             free(hapustengah);
//         }
//         save = save->next;
//     } 
// }
// void searching_node(){
//   string keyword;
//   cin.ignore();
//   cout << "Masukkan Matkul: "; getline(cin, keyword);
//   cout << "Hasil pencarian: " << endl;
//   save = first;
//   while (save != NULL) {
//     if (save->matkul == keyword) {
//       cout << "Judul: " << save->matkul << endl;
//       cout << "Pengarang: " << save->deadline << endl;
//       cout << "Tahun Terbit: " << save->tugasnya << endl;
//       cout << endl;
//     }
//     save = save->next;
//     if (save == NULL)
//     {
//         cout << "Data Tidak Ditemukan"<<endl;
//     }
//   }
// }

void printlinkedlist(){
    save = first;
    while(save != NULL)
    {
        cout <<"\nMata Kuliah : "<<save->matkul<<endl;
        cout <<"Batas Waktu : "<<save->deadline<<endl;
        cout <<"Tugas       : "<<save->tugasnya<<endl;

        save = save->next;
    }
}

int main(){
    insertfirst("Algoritma Strukdat", "23 Maret", "Buat Linked List");
    insertfirst("Aljabar Linear", "27 Maret", "Invers Matriks");
    insertfirst("Matematika Diskrit", "28 Maret", "Tugas Fungsi");
    insertlast("Bahasa Indonesia", "Ujian Akhir", "Resensi Buku");
    printlinkedlist();
    node_calculate();
    // searching_node();

    cout << endl << endl;
    cout << "================"<<endl;
    deletefirst();
    printlinkedlist();
    node_calculate();

    cout << endl << endl;
    cout << "================"<<endl;
    deletelast();
    printlinkedlist();
    node_calculate();
    // searching_node();
    printlinkedlist();
}