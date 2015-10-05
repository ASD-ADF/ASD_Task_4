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
    } while (pil!=11);
}

void displayMenu() {
    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play Next Song"<<endl
        <<"5. play Previous Song"<<endl
        <<"6. play Again This Song (the last played song)"<<endl
        <<"7. play Repeat All Song"<<endl
        <<"8. search Song"<<endl
        <<"9. shuffle The Song List"<<endl
        <<"10. sort The Song List"<<endl
        <<"11. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"input new song : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        insertLast(L,P);
        P=NULL;
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
        {
            system("cls");
            playPrev(P);
        }
        break;
    case 6:
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
    case 7:
        cout<<"How Much : ";
        cin>>much;
        playRepeat(L,much);
        break;
    case 8:
        cout<<"Input The Song name : ";
        cin>>x.name;
        P = findElm(L,x);
        if (P != NULL)
        {
            playSong(P);
        }
        else
        {
            cout<<"The song is not availabe in the list";
        }
        break;
    case 9:
        shuffleList(L);
        cout<<"Shuffle Success";
        break;
    case 10:
        cout<<"Sort not completed yet";
        break;
    case 11:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
