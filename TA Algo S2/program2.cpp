#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
/*******FITUR LOGIN*******/
struct Login{
    string username;
    string password;

    Login *nextlog;
};
Login *firstlog, *lastlog, *barulog, *savelog;

void daftarakun(string username, string password){
    barulog = new Login;
    barulog->username = username;
    barulog->password = password;

    if (firstlog == NULL)
    {
        firstlog = barulog;
        lastlog = barulog;
        firstlog->nextlog = NULL;
    }else
    {
        lastlog->nextlog = barulog;
        lastlog = barulog;
    }
    lastlog->nextlog = NULL;
}
bool masuk(string username, string password){
    savelog = firstlog;
    bool x;
    while (savelog != NULL)
    {
        if (savelog->username == username)
        {
            if (savelog->password == password)
            {
                x = true;
            }else
            {
                x = false;
            }
        }else
        {
            x = false;
        }
        savelog = savelog->nextlog;
    }
    return x;   
}

/*******FUNGSI UTAMA*******/
struct Market
{
    string barang, kode;
    int stok;

    Market *next;
};
Market *first, *last, *save, *baru, *temp;

//Membuat string menjadi kapital
string kapital(string a){
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = toupper(a[i]);
    }
    
    return a;
}
void allkapital(){
    save = first;
    while (save != NULL){
        save->barang = kapital(save->barang);

        save = save->next;
    }
}

//fitur utama
void addlast(string barang, string kode, int stok){
    baru = new Market;
    baru->barang = barang;
    baru->kode = kode;
    baru->stok = stok;

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
void deletefirst(){
    temp = first;
    first = first->next;
    delete temp;
}
void deletebynumber(int number){
    int jumlah = 0;
    save = first;
    temp = NULL;
    while (save != NULL)
    {      
        jumlah++;
        if (jumlah == (number-1))
        {
            temp = save->next;
            save->next = temp->next;
            delete temp;

        }
        save = save->next;
    }
}
void deletebykeyword(string keyword){
    int jumlah = 0; 
    int datakeyword;
    keyword = kapital(keyword);
    save = first;
    while (save != NULL)
    {
        jumlah++;
        if (save->barang == keyword)
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
        deletebynumber(datakeyword);
    }

}
void deleteall(){
    save = first;
    while (save != NULL)
    {
        temp = save;
        first = save->next;
        delete temp;

        save = save->next;
    }
    first = NULL;
    last = NULL;
}
void addstock(string keyword, int stok){
    keyword = kapital(keyword);
    int jumlah = 0; 
    int datakeyword;

    save = first;
    while (save != NULL)
    {
        jumlah++;
        if (save->barang == keyword)
        {
            datakeyword = jumlah;
        }
        save = save->next;
    }
    if (datakeyword == 1)
    {
        first->stok = first->stok + stok;
    }else
    {
        int jumlah = 0;
        save = first;
        temp = NULL;
        while (save != NULL)
        {      
            jumlah++;
            if (jumlah == (datakeyword))
            {
                save->stok = save->stok + stok;
            }
            save = save->next;
        }
    }
}
void kurangistok(string keyword, int stok){
    keyword = kapital(keyword);
    int jumlah = 0; 
    int datakeyword;

    save = first;
    while (save != NULL)
    {
        jumlah++;
        if (save->barang == keyword)
        {
            datakeyword = jumlah;
        }
        save = save->next;
    }
    if (datakeyword == 1)
    {
        first->stok = first->stok - stok;
    }else
    {
        int jumlah = 0;
        save = first;
        temp = NULL;
        while (save != NULL)
        {      
            jumlah++;
            if (jumlah == (datakeyword))
            {
                save->stok = save->stok - stok;
            }
            save = save->next;
        }
    }
}
void searchbykeyword(string keyword){
    keyword = kapital(keyword);
    save = first;
    while (save != NULL)
    {
        if (save->barang == keyword)
        {
            cout << "================================="<< endl;
            cout << "Nama Barang\t: " << save->barang << endl;
            cout << "Kode Barang\t: " << save->kode << endl;
            cout << "Sisa Stok\t: " << save->stok << endl;
        }
        save = save->next;
        if (save == NULL)
        {
            cout << "================================="<< endl;
        }
    }
}
void searchbystock(int stok){
    save = first;
    while (save != NULL)
    {
        if (save->stok == stok)
        {
            cout << "================================="<< endl;
            cout << "Nama Barang\t: " << save->barang << endl;
            cout << "Kode Barang\t: " << save->kode << endl;
            cout << "Sisa Stok\t: " << save->stok << endl;
        }
        save = save->next;
        if (save == NULL)
        {
            cout << "================================="<< endl;
        }
    }
}
void sortingbybarang(){
    save = first;
    temp = NULL;
    string nitip1, nitip2;
    int nitip3;

    while(save != NULL){
        
        temp = save->next;

        while (temp != NULL)
        {
            if (save->barang > temp->barang)
            {
                nitip1 = save->barang;
                nitip2 = save->kode;
                nitip3 = save->stok;

                save->barang = temp->barang;
                save->kode = temp->kode;
                save->stok = temp->stok;

                temp->barang = nitip1;
                temp->kode = nitip2;
                temp->stok = nitip3;
            }
            temp = temp->next;
        }
        save = save->next;
    }
}
void sortingbystock(){
    save = first;
    temp = NULL;
    string nitip1, nitip2;
    int nitip3;

    while(save != NULL){
        
        temp = save->next;

        while (temp != NULL)
        {
            if (save->stok > temp->stok)
            {
                nitip1 = save->barang;
                nitip2 = save->kode;
                nitip3 = save->stok;

                save->barang = temp->barang;
                save->kode = temp->kode;
                save->stok = temp->stok;

                temp->barang = nitip1;
                temp->kode = nitip2;
                temp->stok = nitip3;
            }
            temp = temp->next;
        }
        save = save->next;
    }
}
void printlist(){
    allkapital();
    save = first;
    while (save != NULL)
    {
        cout << "================================="<< endl;
        cout << "Nama Barang\t: " << save->barang << endl;
        cout << "Kode Barang\t: " << save->kode << endl;
        cout << "Sisa Stok\t: " << save->stok << endl;

        save = save->next;
        if (save == NULL)
        {
            cout << "================================="<< endl;
        }
    }
    // if (first == NULL)
    // {
    //     cout << "KOSONG"<<endl;
    // }
}
void printonexternal(){
    string line;
    ofstream report;
    report.open("laporan.txt");
    save = first;
    while (save != NULL)
    {
        report << "================================="<< endl;
        report << "Nama Barang\t: " << save->barang << endl;
        report << "Kode Barang\t: " << save->kode << endl;
        report << "Sisa Stok\t: " << save->stok << endl;

        save = save->next;
        if (save == NULL)
        {
            report << "================================="<< endl;
        }
    }
    report.close();
    system("START /MIN NOTEPAD laporan.txt");
}
int jumlahbarang(){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        save = save->next;
    }
    return jumlah;
}

//fitur loading
void loading(){
    cout << "\t["; 
    for (int i = 0; i < 10; i++)
    {
        Sleep(500);
        cout << "=";
    }
    cout << "]";
    Sleep(2000);
    cout << endl;
}

//interface
void pakuanmart(){
    string line;
    ifstream file;
    file.open("pakuanmart.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }
}
void menu(){
    string line;
    ifstream file;
    file.open("menu.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }
}
void menulogin(){
    string line;
    ifstream file;
    file.open("menulogin.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }
}
void enter(){
    cout << " >> KLIK ENTER UNTUK MELANJUTKAN << "<< endl;
    getch();
}

//contoh barang yang sudah ada di gudang
void baranggudang(){
    //cemilan (75--)
    addlast("Lays","75-001",90); addlast("chitato", "75-002",80); addlast("Taro net", "75-003",50); addlast("Tic tac", "75-004",80); addlast("pocky", "75-005",100); addlast("oreo", "75-006",50); addlast("Biskuat", "75-007",80); addlast("tango", "75-008",98); addlast("piatos", "75-009", 70); addlast("beng beng", "75-010",100);

    //minuman (95--)
    addlast("Teh Kotak","95-001",78); addlast("Coca cola","95-002", 100); addlast("Sprite", "95-003", 50); addlast("s-tee", "95-004", 78); addlast("Aqua Botol", "95-005", 100); addlast("pocari sweat", "95-006", 70); addlast("frestea", "95-007",90); addlast("fruit tea","95-008",70); addlast("nutriboost","95-009",40);

    //ATK (41--)
    // addlast("Pensil", "41-001",200); addlast("penghapus","41-002",200); addlast("penggaris", "41-003",200); addlast("pulpen","41-004",90);
    
    //parabot dapur (21--)
    // addlast("sapu", "21-001", 30); addlast("serokan", "21-002", 20); addlast("alat pel","21-003",20); addlast("baskom", "21-004",15); addlast("ember","21-005",15);

    allkapital();
    sortingbybarang();
}

int main(){
    baranggudang();
    printlist();
    printonexternal();
    

    return 0;
}