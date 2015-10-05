#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>

using namespace std;

List L;
address P,Q;
int pil,pil1;
infotype x;

void menu();
void displayMenu();
void runMenu(int menu);

int main()
{
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

    x.ID = 3;
    x.location = "";
    x.name = "battle_begin.wav";
    P=alokasi(x);
    insertFirst(L,P);

    x.ID = 4;
    x.location = "";
    x.name = "welcome.wav";
    P=alokasi(x);
    insertFirst(L,P);

    x.ID = 5;
    x.location = "";
    x.name = "ugly.wav";
    P=alokasi(x);
    insertFirst(L,P);

    x.ID = 6;
    x.location = "";
    x.name = "burn.wav";
    P=alokasi(x);
    insertFirst(L,P);

    x.ID = 7;
    x.location = "";
    x.name = "hot.wav";
    P=alokasi(x);
    insertFirst(L,P);

    x.ID = 8;
    x.location = "";
    x.name = "heat.wav";
    P=alokasi(x);
    insertFirst(L,P);

    menu();
    return 0;
}

void menu()
{
    int pil;
    do
    {
        system("cls");
        displayMenu();
        cin>>pil;
        runMenu(pil);
    }
    while (pil!=11);
}

void displayMenu()
{
    cout<<"1.  Input New "<<endl
        <<"2.  View List"<<endl
        <<"3.  Play First Song"<<endl
        <<"4.  Play Next "<<endl
        <<"5.  Play Previous"<<endl
        <<"6.  Search Song by Name"<<endl
        <<"7.  Last Played Song"<<endl
        <<"8.  Sort Song by List"<<endl
        <<"9.  Shuffle List"<<endl
        <<"10. Repeat Playlist" << endl
        <<"11. Exit"<<endl << endl;
    cout<<"Choose Menu : ";
}

void runMenu(int menu)
{
    switch(menu)
    {
    case 1 :
        system("cls");
        cout << "INPUT SONG \n \n";
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        cout << "Input Song Success ! \n"
             << "Press Any Key to Go. . .";
        getch();
        break;

    case 2:
        system("cls");
        cout << "SONG LIST \n";
        cout << "================================ \n \n";
        printInfo(L);
        cout << "Press Any Key to Go. . .";
        getch();
        break;

    case 3 :
        system("cls");
        cout <<"Playing First Song. . . \n \n";
        P = First(L);
        playSong(P);
        Q=P;
        cout << "Press Any Key to Go. . .";
        getch();
        break;

    case 4:
        system("cls");
        cout << "Playing Next Song. . . \n \n";
        playNext(P);
        Q=P;
        cout << "Press Any Key to Go. . .";
        getch();
        break;

    case 5:
        system("cls");
        cout << "Playing Previous Song. . . \n \n";
        playPrev(P);
        Q=P;
        cout << "Press Any Key to Go. . .";
        getch();
        break;

    case 6:
        system("cls");
        cout <<"SEARCH SONG BY NAME \n \n";
        cout<<"Enter the name of song : ";
        cin>> x.name;
        P=findElm(L,x);
        if (P!=NULL)
        {
            playSong(P);
            Q=P;
        }
        else
        {
            cout <<"Not Found. . . \n";
        }
        cout << "Press Any Key to Go. . .";
        getch();
        break;

    case 7:
        system("cls");
        cout << "LAST PLAYED SONG \n \n";
        if (Q==NULL)
        {
            cout << "Play a Song First. . . \n";
        }
        else
        {
            playSong(Q);
        }
        getch();
        break;

    case 8:
        system("cls");
        cout << "SORT LIST BY \n \n";
        cout << "1. ID " << endl
             << "2. Name " << endl <<endl
             << "Choose Menu : ";
        cin >> pil1;
        if (pil1>2 || pil1<1)
        {
            cout << "Wrong Input \n";
        }
        else
        {
            sortList(L,pil1);
            cout << "Sort Success ! \n";
        }
        cout << "Press Any Key to Go. . .";
        getch();
        break;

    case 9:
        system("cls");
        cout <<"SHUFFLE LIST \n \n";
        cout <<"Press Any Key to Shuffle. . . \n \n";
        getch();
        shuffleList(L);
        cout << "Shuffle Success ! \n";
        getch();
        break;

    case 10:
        system("cls");
        cout << "REPEAT PLAYLIST \n \n";
        int i;
        cout <<"Repeat Playlist For (...Times) : ";
        cin >> i;
        cout << "Press Any Key to Play. . . \n \n";
        getch();
        playRepeat(L,i);
        cout << endl;
        cout<< "Press Any Key to Go. . . \n";
        getch();
        break;


    case 11:
        cout<<"Thank You :)"<<endl;
        break;
    default :
        cout<<"Wrong Input, Sir "<<endl;
        getch();
        break;
    }
}
