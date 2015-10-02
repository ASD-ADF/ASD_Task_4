#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>

using namespace std;

List L;
address P,Prec;
infotype x;
int a;


void menu();
void displayMenu();
void runMenu(int menu);

int main()
{
    cout << "Hello world!" << endl;

    createList(L);
    // example of data initialization
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
    while (pil!=12);
}

void displayMenu()
{
    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next "<<endl
        <<"5. play prev "<<endl
        <<"6. search & play"<<endl
        <<"7. repeat song"<<endl
        <<"8. shuffle song"<<endl
        <<"9. sort the song list"<<endl
        <<"10. repeat all song"<<endl
        <<"11. Delete Song"<<endl
        <<"11. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu)
{
    switch(menu)
    {
    case 1 :
        cout<<"<<<input new song>>>"<<endl;
        inputNewSong(x);
        P = alokasi(x);
        cout<<"Insert into (1.First 2.After 3.Last) : ";
        cin>>a;
        switch(a)
        {
        case 1 :
            insertFirst(L,P);
            break;
        case 2:
            cout<<"Masukkan nama : ";
            cin>>x.name;
            Prec=findElm(L,x);
            if(Prec!=NULL) {
            insertAfter(L,P,Prec);}
            else {cout<<"Tidak ditemukan"<<endl;}
            break;
        case 3:
            insertLast(L,P);
            break;
        }
        break;
    case 2:
        printInfo(L);
        break;
    case 3 :
        P = First(L);
        playSong(P);
        break;
    case 4:
        playNext(P);
        break;
    case 5:
        playPrev(P);
        break;
    case 6:
        cout<<"search name song :";
        cin>>x.name;
        P=findElm(L,x);
        if(P!=NULL)
        {
            playSong(P);
        }
        else
        {
            cout<<"song not found"<<endl;
        }
        break;
    case 7:
        playSong(P);
        break;
    case 9:
        cout<<"input n : ";
        cin>>a;
        sortList(L,a);
        break;
    case 10:
        cout<<"Masukkan banyaknya pengulangan : ";
        cin>>a;
        playRepeat(L,a);
        printInfo(L);
        break;
    case 11:
        cout<<"Delete (1.First 2.After 3.Last) : "; cin>>a;
        switch(a)
        {
        case 1 :
            deleteFirst(L,P);
            break;
        case 2:
            cout<<"Masukkan nama : ";
            cin>>x.name;
            Prec=findElm(L,x);
            if(Prec!=NULL) {
            deleteAfter(L,P,Prec);}
            else {cout<<"Tidak ditemukan"<<endl;}
            break;
        case 3:
            deleteLast(L,P);
            break;
        }
        break;
    case 12:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
