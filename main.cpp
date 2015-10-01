#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>
#include <stdlib.h>
using namespace std;

List L;
int j;
address P,s;
infotype x;
void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    cout << "Hello world!" << endl;

    createList(L);
    // example of data initialization
    x.ID = 1;
    x.location = "";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = 2;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertFirst(L,P);

    menu();
    return 0;
}

void menu()
{
    int pil;
    do
    {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    }
    while (pil!=11);
}

void displayMenu()
{
    system("cls");
    cout<<"~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~"<<endl
        <<"1. Input New "<<endl
        <<"2. View List"<<endl
        <<"3. Search Song by Name"<<endl
        <<"4. Play First Song"<<endl
        <<"5. Play Next "<<endl
        <<"6. Play Prev"<<endl
        <<"7. Play Again the Last Played"<<endl
        <<"8. Shuffle Song List"<<endl
        <<"9. Sort the Song List"<<endl
        <<"10. Repeat All SOngs"<<endl
        <<"11. Exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu)
{
    switch(menu)
    {
    case 1 :
        system("cls");
       
        break;
    case 2:
        system("cls");
       
        break;
    case 3 :
        system("cls");
        
        break;
    case 4 :
        system("cls");
       
        break;
    case 5:
        system("cls");
        
        break;
    case 6:
        system("cls");
       
        break;
    case 7:
        system("cls");
      
        break;
    case 8 :
        system("cls");
        shuffleList(L);
        getch();
        break;
    case 9:
        system("cls");
        cout<<"Shorting berdasarkan : "<<endl
            <<"1. Berdasarkan ID "<<endl
            <<"2. Berdasarkan Nama "<<endl
            <<"Masukkan Nomor Kondisi yang dipilih : ";
        cin>>j;
        sortList(L,j);
        getch();
        break;
    case 10:
        system("cls");
        cout<<"Masukkan jumlah perulangan : "; cin>>j;
        playRepeat(L,j);
        getch();
        break;
    case 11:
        system("cls");
        cout<<"Thank You"<<endl;
        break;
    default :
        system("cls");
        cout<<"Wrong Input"<<endl;
    }
}
