#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>
#include <stdlib.h>

using namespace std;

List L;
address P;
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
    insertLast(L,P);
    P = NULL;
    menu();
    return 0;
}

void menu() {
    int pil;
    do {
        system("cls");
        displayMenu();
        cin>>pil;
        runMenu(pil);
    } while (pil!=12);
}

void displayMenu() {
    cout<<"1.  Input New Song"<<endl
        <<"2.  View List Song"<<endl
        <<"3.  Play First Song"<<endl
        <<"4.  Play Last Song"<<endl
        <<"5.  Play Previous Song"<<endl
        <<"6.  Play Next Song"<<endl
        <<"7.  Play Again This Song (the last played song)"<<endl
        <<"8.  Play Repeat All Song"<<endl
        <<"9.  Search Song"<<endl
        <<"10. Shuffle The Song List"<<endl
        <<"11. Sort The Song List"<<endl
        <<"12. Exit"<<endl;
    cout<<"\nchoose menu : ";
}

void runMenu(int menu) {
    int much;
    switch(menu) {
    case 1 :
        system("cls");
        cout<<"input new song : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        P = NULL;
        break;
    case 2:
        system("cls");
        printInfo(L);
        getch();
        break;
    case 3 :
        system("cls");
        P = First(L);
        playSong(P);
        break;
    case 4:
        system("cls");
        P = Last(L);
        playSong(P);
        break;
    case 5:
        system("cls");
        if (P == NULL)
        {
            system("cls");
            cout<<"You don't Play First / Last Song Before";
            getch();
        }
        else
        {
            system("cls");
            playPrev(P);
        }
        break;
    case 6:
        system("cls");
        if (P == NULL)
        {
            system("cls");
            cout<<"You don't Play First / Last Song Before";
            getch();
        }
        else
        {
            system("cls");
            playNext(P);
        }
        break;
    case 7:
        system("cls");
        if (P == NULL)
        {
            system("cls");
            cout<<"You don't choose any song before, Please choose menu number 3 / 4 / 5 / 6";
            getch();
        }
        else
        {
            system("cls");
            playSong(P);
        }
        break;
    case 8:
        system("cls");
        cout<<"How Much : ";
        cin>>much;
        playRepeat(L,much);
        break;
    case 9:
        system("cls");
        cout<<"Under Construction";
        getch();
        break;
    case 10:
        system("cls");
        cout<<"Under Construction";
        getch();
        break;
    case 11:
        system("cls");
        cout<<"Under Construction";
        getch();
        break;
    case 12:
        system("cls");
        cout<<"thank you"<<endl;
        getch();
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
