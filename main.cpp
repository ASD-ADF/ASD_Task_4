#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

List L;
address P,Prec;
infotype x;
int n;

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

void menu() {
    int pil;
    do {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    } while (pil!=0);
}

void displayMenu() {
    cout<<"1. input new "<<endl
        <<"2. delete song"<<endl
        <<"3. view list"<<endl
        <<"4. play shuffle"<<endl
        <<"5. play first song"<<endl
        <<"6. play next "<<endl
        <<"7. play previous"<<endl
        <<"8. play repeat"<<endl
        <<"9. sort song list"<<endl
        <<"0. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"input new song : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        break;
    case 2:
        break;
    case 3 :
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        playPrev(P);
        break;
    case 8:
        break;
    case 9:
        break;
    case 0:
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
