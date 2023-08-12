#include <iostream>
using namespace std;

int isiQueue[100];
const int maksimal = 100;
int jumlah = 0;

bool IsEmpty()
{
    return jumlah == 0;
}

bool IsFull()
{
    return jumlah >= maksimal;
}

int ItemsRemaining()
{
    return maksimal - jumlah;
}

int Count()
{
    return jumlah;
}

int MaximumSize()
{
    return maksimal;
}

void Enqueue()
{
    if (IsFull())
    {
        cout << "Queue sudah penuh!" << endl;
        return;
    }

    int input_nilai = 0;
    cout << "Masukan data: ";
    cin >> input_nilai;

    jumlah += 1;
    isiQueue[jumlah] = input_nilai;
    cout << "Data sudah diinputkan " << input_nilai << endl;
}

void Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue masih kosong!" << endl;
        return;
    }

    cout << "Membuang data " << isiQueue[1] << endl;
    for (int i = 1; i <= jumlah; i++)
    {
        isiQueue[i] = isiQueue[i + 1];
    }

    jumlah -= 1;
}

void Clear()
{
    jumlah = 0;
    cout << "Queue sudah bersih" << endl;
}

void Print()
{
    if (IsEmpty())
    {
        cout << "Queue masih kosong!" << endl;
        return;
    }

    cout << "\t";
    for (size_t i = 1; i <= jumlah; i++)
    {
        cout << "[" << isiQueue[i] << "]";
    }
}

int main(){

    return 0;
}