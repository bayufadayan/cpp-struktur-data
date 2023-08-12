#include <iostream>
#include <limits> //#1
using namespace std;
struct data_mahasiswa //#2
{
    string nama, npm, kelas;
};
data_mahasiswa arr[100]; //#3

int main()
{
    int jumlah_mahasiswa = 0;
    cout << "Masukan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //*memerlukan header baru pada #1
    arr[jumlah_mahasiswa]; //#3
    for (size_t i = 0; i < jumlah_mahasiswa; i++)//#4
    {
        cout << "Mahasiswa ke-" << (i + 1) << endl;
        cout << "\tMasukan NPM: ";
        getline(cin, arr[i].npm);
        cout << "\tMasukan nama: ";
        getline(cin, arr[i].nama); //#5
        cout << "\tMasukan kelas: ";
        getline(cin, arr[i].kelas); //#6
    }cout << endl;
    cout << endl
    << " >> DATA NILAI MAHASISWA <<" << endl;
    
    for (size_t i = 0; i < jumlah_mahasiswa; i++)
    {
        cout << "Mahasiswa ke-" << (i + 1)
        << "\n\tNPM : " << arr[i].npm/*#7*/
        << "\n\tNama : " << arr[i].nama
        << "\n\tKelas : " << arr[i].kelas
        << "\n\tAlamat Memori : " << &arr[i] << endl; /*#8*/ 
    }
    return 0;
}
