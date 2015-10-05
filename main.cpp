#include <iostream>
#include "list.h"
#include "player.h"
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
    } while (pil!=10);
}

void displayMenu() {
    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next "<<endl
        <<"5. play previous song"<<endl
        <<"6. search song by name"<<endl
        <<"7. play again song (Last played song)"<<endl
        <<"8. sort song by...."<<endl
        <<"9. repeat playlist"<<endl
        <<"10. exit"<<endl;
    cout<<"choose menu : ";
}
void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"input new song : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        getch();
        break;
    case 2:
        printInfo(L);
        getch();
        break;
    case 3 :
        P = First(L);
        playSong(P);
        Q=P;
        getch();
        break;
    case 4:
        playNext(P);
        Q=P;
        break;
    case 5:
        playPrev(P);
        Q=P;
        getch();
        break;
    case 6:
        cout<<"Masukkan lagu yang akan dicari: "; cin>> x.name;
        P=findElm(L,x);
        if (P!= NULL) {
            playSong(P);
            Q=P;
        }
        else {
            cout<<"Lagi Tidak Ditemukan"<<endl;
        }
        getch();
        break;
    case 7:
        if (Q==NULL) {
            cout<<"Belum ada lagu yang dimainkan"<<endl;

        }
        else {
            playSong(Q);
        }
        getch();
        break;
    case 8:
        cout<<"1. By ID"<<endl
            <<"2. By Name"<<endl
            <<"Masukkan Pilihan: "; cin>>pil;
        if(pil<1 && pil>2) {
            cout<<"Anda Salah Menginputkan";
        }
        else {
            sortList(L,pil);
        }
        break;
    case 9:
        int n;
        cout<<"Ingin Berapa Kali Repeat?"; cin>>n;
        playRepeat(L,n);
        break;

    case 10:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}

