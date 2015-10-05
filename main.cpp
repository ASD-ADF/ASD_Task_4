/*
modify the main prorgam, add these menus into the main program

menu to search song by name and play it
( you can create a new function to search or modify the findElm function )
menu play the previous song on the list
menu play again this song (the last played song)
menu shuffle the song list
menu sort the song list
menu play repeat all songs
*/

#include <iostream>
#include "list.h"
#include "player.h"
#include <ctime>
#include <conio.h>

using namespace std;

List L;
address P,Q;
infotype x;
int pil;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    cout << "Hello world!" << endl;

    createList(L);
    Q=NULL;
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
    srand(time(0));
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
        <<"4. play next song "<<endl
        <<"5. play previous song " << endl
        <<"6. search song by name " << endl
        <<"7. Play again song (last played song)" << endl
        <<"8. Sort Song by.. " << endl
        <<"9. repeat playlist" << endl
        <<"10. shuffle playlist" << endl
        <<"11. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        system("CLS");
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        system("CLS");
        break;

    case 2:
        system("CLS");
        printInfo(L);
        cout << endl;
        break;

    case 3 :
        system("CLS");
        P = First(L);
        playSong(P);
        Q=P;
        system("CLS");
        break;

    case 4:
        system("CLS");
        playNext(P);
        Q=P;
        system("CLS");
        break;
    case 5:
        system("CLS");
        playPrev(P);
        Q=P;
        system("CLS");
        break;
    case 6:
        system("CLS");
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
        system("CLS");
        break;
    case 7:
        system("CLS");
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
        system("CLS");
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
        system("CLS");
        break;
    case 9:
        system("CLS");
        int n;
        cout << "mau me-repeat berapa kali: ";
        cin >> n;
        playRepeat(L,n);
        system("CLS");
        break;
    case 10:
        system("CLS");
        cout << "Shuffle On"<<endl;

        shuffle(L);
        system("CLS");
        break;
    case 11:
        system("CLS");
        cout<<"thank you"<<endl;
        system("CLS");
        break;
    default :
        cout<<"wrong input"<<endl;
        system("CLS");
    }
}
