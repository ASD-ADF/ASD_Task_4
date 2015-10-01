#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>

using namespace std;

List L;
address P,Prec;
infotype x;
int condition,n;

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

    x.ID =3;
    x.location ="";
    x.name = "camera1.wav";
    P = alokasi(x);
    insertLast(L,P);

    x.ID = 0;
    x.location ="";
    x.name ="cash_register.wav";
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
        <<"4. play next "<<endl
        <<"5. play prev "<<endl
        <<"6. Play again "<<endl
        <<"7. play shuffle "<<endl
        <<"8. sort song "<<endl
        <<"9. repeat all song"<<endl
        <<"10.delete song"<<endl
        <<"11. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        int pil;
        cout<<"input new song : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        cout<<"Pilih insert : "<<endl
        <<"1. Insert Fisrt "<<endl
        <<"2. Insert Last "<<endl
        <<"3. Insert After "<<endl
        <<"Pilihan anda : ";cin>>pil;
        if (pil == 1) {
            insertFirst(L,P);
        }
        else if (pil==2) {
            insertLast(L,P);
        }
        else if (pil==3) {
            cout<<"Masukkan ID element manakah yang ingin anda masukkan setelahnya : ";
            cin>>Prec->info.ID;
            insertAfter(L,P,Prec);
        }
        else { cout<<"Pilihan yang anda masukkan salah"<<endl;}
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
        playPrev(P);
        break;
    case 6:
        playSong(P);
        break;
    case 7:
        shuffleList(L);
        break;
    case 8:
        cout<<"Choose : "<<endl
        <<"1. Sort By ID "<<endl
        <<"2. Sort By name "<<endl
        <<"Your choice : ";
        cin>>condition;
        sortList(L,condition);
        break;
    case 9:
        cout<<"Berapa kali ingin anda ulang : ";
        cin>>n;
        playRepeat(L,n);
        break;
    case 10:
        cout<<"Pilih delete : "<<endl
        <<"1. delete first"<<endl
        <<"2. delete last"<<endl
        <<"3. delete after"<<endl;
        cout<<"Pilihan anda : ";cin>>pil;
        if (pil == 1) {
            deleteFirst(L,P);
        }
        else if (pil==2) {
            deleteLast(L,P);
        }
        else if (pil==3) {
            cout<<"Pilih ID yang ingin anda delete setelahnya : ";
            cin>>Prec->info.ID;
            deleteAfter(L,P,P);
        }
        else {cout<<"Pilihan anda salah"<<endl;}
        break;
    case 11:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
