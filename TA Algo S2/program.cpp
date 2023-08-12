// #include <iostream>
// #include <fstream>
// #include <conio.h>
// #include <windows.h>
// using namespace std;

// struct market
// {
//     string barang;
//     int kodebarang;
//     int stok;

//     market *next;
// };
// market *last, *first, *save, *baru, *temp;

// void addlast(string barang, int kodebarang, int stok){
//     baru = new market;
//     baru->barang = barang;
//     baru->kodebarang = kodebarang;
//     baru->stok = stok;

//     if (first == NULL)
//     {
//         first = baru;
//         last = baru;

//         first->next = NULL;
//     }else
//     {
//         last->next = baru;
//         last = baru;
//     }
//     last->next = NULL;
// }

// void deletebysequence(int datahapus){
//     int jumlah = 0;
//     save = first;
//     while (save != NULL)
//     {
//         jumlah++;
//         if (jumlah == (datahapus-1))
//         {
//             temp = save->next;
//             save->next = temp->next;
//             delete temp;
//         }
//         save = save->next;
//     }
// }

// void displaymenu(){
//     string line;
//     ifstream file;
//     file.open("menu.txt");
//     while (file)
//     {
//         getline(file, line);
//         cout << line << endl;
//     }
    
// }

// void loading(){
//     cout << "TEKAN ENTER!"<<endl;
//     getch();
//     system("cls");
//     cout << "MEMUAT"<<endl;
//     int count = 0;
//     while (count != 5)
//     {
//         count++;
//         Sleep(900);
//         cout << ".";
//     }
    
// }

// int main(){
//     loading();

//     getch();
// }

