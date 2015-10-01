//Nama:
//Fachri UL Albab (1301140151)
//Alfian Pamungkas S (1301144411)
//Ezekiel Manurung (1301140261)
#include <iostream>
#include "list.h"
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
    cout<<"1. input new "<<endl;
        <<"2. view list"<<endl;
        <<"3. play first song"<<endl;
        <<"4. play next "<<endl;
        <<"5. play previous"<<endl;
        <<"6. play repeat"<<endl;
        <<"7. shuffle song"<<endl;
        <<"8. sort list"<<endl;
        <<"9. exit"<<endl;
    cout<<"choose menu : ";
    system("CLS");
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
        playNext(P);
        break;
    case 5:
        PlayPrev(P);
    case 6:
        PlayRepeat(P);
        break;
    case 7:
        ShuffleList(P);
        break;
    case 8:
        sortList(P);
    case 9:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
