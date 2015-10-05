#include <iostream>
#include "DoubleCircularH.h"
#include "player.h"
#include <conio.h>

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
    Q = NULL;
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

void menu() {
    int pil;
    do {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    } while (pil!=5);
}

void displayMenu() {
    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next"<<endl
        <<"5. play previous" << endl
        <<"6. search song by name " << endl
        <<"7. Play again song (last played song)" << endl
        <<"8. Sort Song by.. " << endl
        <<"0. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"Input lagu baru : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        system("cls");
        break;

    case 2:
        system("cls");
        printInfo(L);
        break;

    case 3 :
        P = First(L);
        playSong(P);
        Q=P;
        system("cls");
        break;
    case 4:
        playNext(P);
        Q=P;
        system("cls");
        break;
    case 5:
        playPrev(P);
        Q=P;
        system("cls");
        break;
    case 6:
        cout << "masukkan nama lagu yang ingin dicari: " ;
        cin >> x.name;
        P=findElm1(L,x);
        if (P!=NULL)
        {
            playSong(P);
            Q=P;
        }
        else
        {
            cout << "lagu tidak ada sayang";
        }
        system("cls");
        break;
    case 7:
        if(Q==NULL)
        {
            cout << "tidak ada yang di mainkan sebelumnya" << endl;
        }
        else
        {
            playSong(Q);
        }
        getch();
        break;

    case 8:
        system("cls");
        cout << "1. by ID" << endl
             << "2. by Name" << endl
             << "masukkan pilihan: ";
        cin >> pil;
        if (pil<1 && pil > 2)
        {
            cout << "salah inputnya sayang";
        }
        else
        {
            sortList(L,pil);
        }
        system("cls");
        break;
    case 0:
        system("cls");
        cout<<"Thank You Very Much"<<endl;
        break;
    default :
        cout<<"Wrong Input!"<<endl;
    }
}
