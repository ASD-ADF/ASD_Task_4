#include "list.h"
#include "player.h"

using namespace std;

List L;
address P;
infotype x;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {

    createList(L);
    // example of data initialization
    x.ID = 1;
    x.location = "-";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = 2;
    x.location = "-";
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
    cout<<"\n choose menu : ";
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
        printInfo(L);
        break;
    case 3 :
        P = First(L);
        playSong(P);
        break;
    case 4:
        P= Last (L);
        playNext(P);
        break;
    case 5:
        playPrev(P);
        break;
    case 6:
        playNext(P);
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
