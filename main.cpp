#include <iostream>
#include "list.h"
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

    createList(L);
    x.ID = 1;
    x.location = ;
    x.name = "";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = 2;
    x.location = "";
    x.name = "";
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
    cout<<"1. Input Newew "<<endl
        <<"2. View List Song "<<endl
        <<"3. Play Song"<<endl
        <<"4. Play Next "<<endl
        <<"5. Play Previous "<<endl
        <<"6. Search by Title "<<endl
        <<"7. Play Again (Last played song) "<<endl
        <<"8. Sort Song "<<endl
        <<"9. Repeat Playlist "<<endl
        <<"10. Exit "<<endl;
    cout<<"Choose Menu : ";
}
void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"Input New : "<<endl;
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
        cout<<" Masukkan Lagu : "; cin>> x.name;
        P=findElm(L,x);
        if (P!= NULL) {
            playSong(P);
            Q=P;
        }
        else {
            cout<<" Tidak Ditemukan "<<endl;
        }
        getch();
        break;
    case 7:
        if (Q==NULL) {
            cout<<" Belum Ada Lagu "<<endl;

        }
        else {
            playSong(Q);
        }
        getch();
        break;
    case 8:
        cout<<"1. By ID" <<endl
            <<"2. By Name "<<endl
            <<" Masukkan Pilihan : "; cin>>pil;
        if(pil<1 && pil>2) {
            cout<<" Salah Input ";
        }
        else {
            sortList(L,pil);
        }
        break;
    case 9:
        int n;
        cout<<" Repeat? "; cin>>n;
        playRepeat(L,n);
        break;

    case 10:
        cout<<"Thank You"<<endl;
        break;
    default :
        cout<<" Not Found "<<endl;
    }
}
