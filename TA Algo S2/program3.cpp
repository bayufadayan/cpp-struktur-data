#include <iostream> 
#include <fstream> 
#include <windows.h> 
#include <conio.h>
using namespace std;

/************FITUR LOGIN*************/
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
    bool x;
    savelog = firstlog;
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

/************FITUR UTAMA*************/
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

//fungsi tambahan dan load666ing
void loading(int y, int z){
    cout << "\t["; 
    for (int i = 0; i < y; i++)
    {
        Sleep(z);
        cout << "=";
    }
    cout << "]";
    Sleep(1000);
    cout << endl;
}
void berhasil(string x){
    cout << "\n\t(sedang menyimpan)\n";
    loading(16, 200);
    cout << "\n\t(berhasil "<<x<<")\n";
    Sleep(500);
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

//fungsi utama
void addlast(string barang, string kode, int stok){
    barang = kapital(barang);
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

    berhasil("dihapus");
}
void deletebynumber(int number){
    int jumlah = 0;
    save = first;
    while (save != NULL)
    {      
        jumlah++;
        if (jumlah == (number-1))
        {   
            temp = save->next;
            save->next = temp->next;
            delete temp;
            berhasil("dihapus");
        }
        save = save->next;
    }
}
void deletebykeyword(string keyword){
    int jumlah = 0; 
    int datakeyword;
    keyword = kapital(keyword);
    save = first;
    //mencari keyword nya ada diurutan keberapa
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
        deletefirst();

        save = save->next;
    }
    first = NULL;
    last = NULL;
}
void searchbykeyword(string keyword){
    bool data = false;
    keyword = kapital(keyword);
    save = first;
    while (save != NULL)
    {
        if (save->barang == keyword)
        {
            data = true;
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

    if (!data)
    {
       cout << "      BARANG TIDAK DITEMUKAN" << endl;
    }
}
void searchbystock(int stok){
    bool data = false;
    save = first;
    while (save != NULL)
    {
        if (save->stok == stok)
        {
            data = true;
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

    if (!data)
    {
       cout << "      BARANG TIDAK DITEMUKAN" << endl;
    }
}
void addstock(string keyword, int stok){
    keyword = kapital(keyword);
    save = first;
    while (save != NULL)
    {
        if (save->barang == keyword)
        {
            save->stok = save->stok + stok;
            berhasil("ditambah");
        }
        save = save->next;
    }
    searchbykeyword(keyword);  
}
void kurangistok(string keyword, int stok){
    keyword = kapital(keyword);
    save = first;
    while (save != NULL)
    {
        if (save->barang == keyword)
        {
            save->stok = save->stok - stok;
            berhasil("dikurangi");
        }
        save = save->next;
    }
    searchbykeyword(keyword);
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
    int jumlah = 0;
    allkapital();
    save = first;
    while (save != NULL)
    {
        jumlah++;
        cout << "================================="<< endl;
        cout << "\t    [" << jumlah << "]" << endl;
        cout << "Nama Barang\t: " << save->barang << endl;
        cout << "Kode Barang\t: " << save->kode << endl;
        cout << "Sisa Stok\t: " << save->stok << endl;

        save = save->next;
        if (save == NULL)
        {
            cout << "================================="<< endl;
        }
    }
}
void printonexternal(){
    int jumlah = 0;
    ofstream report;
    report.open("laporan.txt");
    report << "\nLAPORAN BARANG DI GUDANG MINIMARKET UNPAK MART\n"<<endl;
    save = first;
    while (save != NULL)
    {
        jumlah++;
        report << "================================="<< endl;
        report << "\t    [" << jumlah << "]" << endl;
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
void salahpilih(){
    cout << "Pilihan tidak sesuai!"<<endl;
    Sleep(500);
}
void submenu_cek(){
    string line;
    ifstream file;
    file.open("submenu1.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    } 
}
void submenu_print(){
    string line;
    ifstream file;
    file.open("submenu2.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }
}
void submenu_hapus(){
    string line;
    ifstream file;
    file.open("submenu3.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }
}
void profil(){
    cout << "Aplikasi ini dibuat oleh : "<< endl;
    cout << "+----------------------------------------------+"<<endl;
    cout << "|             NAMA ANGGOTA KELOMPOK            |"<<endl;
    cout << "+--+-------------------------------+-----------+"<<endl;
    cout << "|01| Akhmal Rivaldi                | 065121101 |"<<endl;
    cout << "|02| Fathur Pakapradana Shodikin   | 065121103 |"<<endl;
    cout << "|03| Feri Febriansyah              | 065121091 |"<<endl;
    cout << "|04| Muhamad Bayu Fadayan          | 065121100 |"<<endl;
    cout << "|05| Rafly Rahmat Amtiar           | 065121107 |"<<endl;
    cout << "+--+-------------------------------+-----------+"<<endl;
    cout << "\nTahun diluncurkan : 2022" <<endl;
}
void enter(){
    cout << " << KLIK ENTER UNTUK MELANJUTKAN >> "<< endl;
    getch();
}

//isi barang yang ada digudang
void baranggudang(){
    addlast("Lays","75-001",90); addlast("chitato", "75-002",80); addlast("Taro net", "75-003",50); addlast("Tic tac", "75-004",80); addlast("pocky", "75-005",100);
    addlast("Teh Kotak","95-001",78); addlast("Coca cola","95-002", 100); addlast("Sprite", "95-003", 50); addlast("s-tee", "95-004", 78); addlast("Aqua Botol", "95-005", 100); 
    
    allkapital();
    sortingbybarang();
}

/****************PROGRAM UTAMA******************/
int main(){
    baranggudang(); daftarakun("unpakmart", "unpak123");

//pendeklarasian
    int pilihlog, pilihmenu, submenu, stok, number; 
    string username, password, barang, kode, keluar;
    bool looplog = true; bool loopmenu = true;

//beranda
    system ("color 57");
    pakuanmart();
    cout << "=====================================================" << endl;
    cout << "   >>>   APLIKASI PENGOLAHAN DATABASE GUDANG   <<<   " << endl;
    cout << "=====================================================" << endl;
    cout << "\n\t";
    enter();

//halaman login
    while (looplog)
    {
        system("cls");
        system("color D");
        menulogin();
        cout << "Pilihan saya : ";
        cin >> pilihlog;

//switch case untuk login
        switch (pilihlog)
        {
/******DAFTAR AKUN******/
        case 1:
            cout << "Masukan Username : "; cin >> username;
            cout << "Masukan Password : "; cin >> password;

            daftarakun(username, password);
            berhasil("disimpan");
            break;
            
/******LOGIN******/
        case 2:
            cout << "Masukan Username : "; cin >> username;
            cout << "Masukan Password : "; cin >> password;

            if (masuk(username, password))
            {
    /*=======MASUK KE MENU UTAMA=======*/
                while (loopmenu)
                {
                    system("cls");
                    system("color 57");
                    pakuanmart();
                    menu();
                    cout << "Pilihan saya : ";
                    cin >> pilihmenu;

                    //pilihmenu utama
                    switch (pilihmenu)
                    {
            /*********TAMBAH BARANG BARU*********/
                    case 1:
                        cout << "\nSilakan isi" << endl; 
                        cout << "================================="<< endl;
                        cout << "Nama Barang\t: "; cin.ignore(); getline(cin, barang);
                        cout << "Kode Barang\t: "; cin >> kode;
                        cout << "Sisa Stok\t: "; cin >> stok;
                        cout << "================================="<< endl;
                        addlast(barang, kode, stok);
                        berhasil("ditambah");
                        break;

            /*********TAMBAH STOK BARANG*********/
                    case 2:
                        cout << "Masukan nama barang : "; 
                        cin.ignore();
                        getline(cin, barang);
                        cout << "Stok akan ditambah : "; cin >> stok;
                        addstock(barang, stok);
                        enter();
                        break;

            /*********KURANGI STOK BARANG*********/
                    case 3:
                        cout << "Masukan nama barang : "; 
                        cin.ignore();
                        getline(cin, barang);
                        cout << "Stok akan dikurang : "; cin >> stok;
                        kurangistok(barang, stok);
                        enter();
                        break;

            /*********CEK BARANG DAN STOK*********/
                    case 4:
                        system("cls");
                        submenu_cek();
                        cout << "Pilihan saya : "; cin >> submenu;
                        if (first == NULL)
                        {
                            cout << "MAAF GUDANG KOSONG!" <<endl;
                            enter();
                            break;

                        }else
                        {
                            //PEMILIHAN MENU PADA CEK BARANG
                            switch (submenu)
                            {
                            case 1 :
                                cout << "Masukan nama barang : "; 
                                cin.ignore();
                                getline(cin, barang);
                                searchbykeyword(barang);
                                cout << endl;
                                enter();
                                break;
                            
                            case 2 :
                                cout << "Masukan jumlah stok : "; cin >> stok;
                                searchbystock(stok);
                                cout << endl;
                                enter();
                                break;
                            
                            case 3 :
                                cout << "Dalam gudang tersedia " <<jumlahbarang()<< " barang\n\n";
                                enter();
                                break;

                            default:
                                break;
                            }
                        }
                        
                        break;

            /*********TAMPILKAN DAFTAR BARANG*********/
                    case 5:
                        system("cls");
                        submenu_print();
                        cout << "Pilihan saya : "; cin >> submenu;
                        if (first == NULL)
                        {
                            cout << "MAAF GUDANG KOSONG!" <<endl;
                            enter();
                            break;

                        }else
                        {
                            switch (submenu)
                            {
                            case 1:
                                sortingbybarang();
                                printlist();
                                enter();
                                break;
                            case 2:
                                sortingbystock();
                                printlist();
                                enter();
                                break;
                            
                            case 3:
                                printonexternal();
                                break;

                            default:
                                break;
                            }
                            break;
                        }
                    
            /*********HAPUS BARANG*********/
                    case 6:
                        system("cls");
                        submenu_hapus();
                        cout << "Pilihan saya : "; cin >> submenu;

                        switch (submenu)
                        {
                        case 1:
                            sortingbybarang();
                            printlist();
                            cout << "\nMasukan nama barang : "; 
                            cin.ignore();
                            getline(cin, barang);
                            searchbykeyword(barang);
                            deletebykeyword(barang);
                            enter();
                            break;

                        case 2:
                            sortingbybarang();
                            printlist();
                            cout << "\nMasukan urutan barang : "; cin >> number;
                            if (number == 1)
                            {
                                deletefirst();
                            }else
                            {
                                deletebynumber(number);
                            }
                            enter();
                            break;
                        case 3:
                            deleteall();
                            berhasil("di hapus");
                            enter();
                            break;

                        default:
                            break;
                        }

                        break;

            /*********INFO APLIKASI*********/
                    case 7 :
                        system("cls");
                        profil();
                        enter();
                        break;
                    
            /*********KELUAR AKUN*********/
                    case 8 :
                        system("cls");
                        cout << "\nYakin ingin keluar (Y/N) : "; cin >> keluar;
                        keluar = kapital(keluar);
                        if (keluar == "Y")
                        {
                            return 0;
                        }
                        break;

                    default:
                        salahpilih();
                        break;
                    }
                }

                break;

            }else
            {
                cout << "\nusername atau password tidak terdaftar!" << endl;
                enter();
                break;
            }

/******KELUAR APLIKASI******/
        case 3 :
            system("cls");
            cout << "\nYakin ingin keluar (Y/N) : "; cin >> keluar;
            keluar = kapital(keluar);
            if (keluar == "Y")
            {
                looplog = false;
            }else if (keluar == "N")
            {
                looplog == true;
            }
            break;
        
        default:
            salahpilih();
            break;
        }
    }
}