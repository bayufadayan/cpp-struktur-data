#include <iostream>
#include <conio.h>
using namespace std;

struct warehouse
{
    string item;
    int stock;

    warehouse *next;
};
warehouse *first, *last, *save, *temp, *fresh;

void insertfirst (string item, int stock);
void insertlast (string item, int stock);
void deletefirst();
void deletelast();
void deletebykeyword();
void deletebysequence();
void updatestock();
void addstock();
void lessstock();
void clearstock();
void display();
int count_all();
int count_oneitem();
void search_item();
void check_stock();
void sorting();

int main(){
    
}


