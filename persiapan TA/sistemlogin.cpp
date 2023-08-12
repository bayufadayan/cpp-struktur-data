#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct sistemlogin
{
    string username, password;
    sistemlogin *next;
};
sistemlogin *first, *last, *save, *newacc;

void loginlinkedlist(string username, string password){
    newacc = new sistemlogin;
    newacc->username = username;
    newacc->password = password;
    
    if (first == NULL)
    {
        first = newacc;
        last = newacc;
        last->next = NULL;
    }else
    {
        last->next = newacc;
        newacc->next = NULL;
        last = newacc;
    }
}

void cetaklogin(){
    save = first;
    while (save != NULL)
    {
        cout << "USERNAME: " << save->username << endl;
        cout << "PASSWORD: " << save->password << endl;
        save = save->next;
    }
    
}

int main (){
    first, last = NULL;
    loginlinkedlist("BAYU","bayu123");
    cetaklogin();

}