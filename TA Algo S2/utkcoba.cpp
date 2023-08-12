#include <iostream>
#include <fstream>
using namespace std;

int main(){

    string line;
    ifstream file;
    file.open("pakuanmart.txt");
    while (file)
    {
        getline(file, line);
        cout << line << endl;
    }

    return 0;
}