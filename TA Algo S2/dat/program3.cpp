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
//fungsi tambahan dan loading
void loading(int y, int z){
    cout << "\t["; 
    for (int i = 0; i < y; i++)
    {
        Sleep(z);
        cout << "=";
    }
    cout << "]";
    Sleep(1600);
    cout << endl;
}
void berhasil(string x){
    cout << "\n\t(sedang menyimpan)\n";
    loading(16, 300);
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
            berhasil("ditambah");
        }
        save = save->next;
    }
    if (datakeyword == 1)
    {
        first->stok = first->stok + stok;
        searchbykeyword(keyword);
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
        searchbykeyword(keyword);
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
            berhasil("dikurang");
        }
        save = save->next;
    }
    if (datakeyword == 1)
    {
        first->stok = first->stok - stok;
        searchbykeyword(keyword);
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
        searchbykeyword(keyword);
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
    // if (first == NULL)
    // {
    //     cout << "KOSONG"<<endl;
    // }
}
void printonexternal(){
    int jumlah = 0;
    string line;
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
void enter(){
    cout << " << KLIK ENTER UNTUK MELANJUTKAN >> "<< endl;
    getch();
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
    cout << "\nTahun diluncurkan : 2022" <<endl <<endl;
}

//contoh barang yang sudah ada di gudang
void baranggudang(){
    //cemilan (75--)
    addlast("Lays","75-001",90); addlast("chitato", "75-002",80); addlast("Taro net", "75-003",50); addlast("Tic tac", "75-004",80); addlast("pocky", "75-005",100);
    // addlast("oreo", "75-006",50); addlast("Biskuat", "75-007",80); addlast("tango", "75-008",98); addlast("piatos", "75-009", 70); addlast("beng beng", "75-010",100);

    //minuman (95--)
    addlast("Teh Kotak","95-001",78); addlast("Coca cola","95-002", 100); addlast("Sprite", "95-003", 50); addlast("s-tee", "95-004", 78); addlast("Aqua Botol", "95-005", 100); 
    //addlast("pocari sweat", "95-006", 70); addlast("frestea", "95-007",90); addlast("fruit tea","95-008",70); addlast("nutriboost","95-009",40);

    //ATK (41--)
    // addlast("Pensil", "41-001",200); addlast("penghapus","41-002",200); addlast("penggaris", "41-003",200); addlast("pulpen","41-004",90);
    
    //parabot dapur (21--)
    // addlast("sapu", "21-001", 30); addlast("serokan", "21-002", 20); addlast("alat pel","21-003",20); addlast("baskom", "21-004",15); addlast("ember","21-005",15);

    allkapital();
    sortingbybarang();
}


/***********FUNGSI UTAMA***********/
int main (){
    baranggudang(); daftarakun("unpakmart", "unpak123");

//pendeklarasian
    int pilihlog, pilihmenu, submenu, stok, number; 
    string username, password, barang, kode;
    bool looplog = true; bool loopmenu = true;

//main
    system ("color 0B");
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
        system("color 06");
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
            cout << "\n\t(sedang menyimpan)\n";
            loading(16, 300);

            break;
            
/******MASUK KE MENU UTAMA******/
        case 2:
            cout << "Masukan Username : "; cin >> username;
            cout << "Masukan Password : "; cin >> password;

            if (masuk(username, password))
            {
                while (loopmenu)
                {
                    system("cls");
                    system("color 0B");
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
                            printlist();
                            cout << "\nMasukan nama barang : "; 
                            cin.ignore();
                            getline(cin, barang);
                            deletebykeyword(barang);
                            berhasil("di hapus");
                            enter();
                            break;

                        case 2:
                            printlist();
                            cout << "\nMasukan urutan barang : "; cin >> number;
                            deletebynumber(number);
                            berhasil("di hapus");
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
                        loopmenu = false;
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
            looplog = false;
            break;
        
        default:
            salahpilih();
            break;
        }
    }

    return 0;
}
