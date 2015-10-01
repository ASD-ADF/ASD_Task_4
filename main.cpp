#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

List L;
address P;
address Prec;
infotype x;
int condition;
int number;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    cout << "WAV Music Player Kelompok 2" << endl;

    createList(L);
    // example of data initialization
    x.ID = 4;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = 2;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertLast(L,P);

    x.ID = 3;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertLast(L,P);

    x.ID = 1;
    x.location = "";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertLast(L,P);

    x.ID = 0;
    x.location = "";
    x.name = "asdasdclapping.wav";
    P = alokasi(x);
    insertLast(L,P);

    menu();
    return 0;
}

void menu() {
    int pil;
    do {
        cout<<endl;
        displayMenu();
        cin>>pil; cin.ignore();
        runMenu(pil);
    } while (pil != 10);
}

void displayMenu() {
    system("CLS");
    cout<<"1. Input New "<<endl
        <<"2. Delete Element"<<endl
        <<"3. Sort List"<<endl
        <<"4. View List"<<endl
        <<"5. Play First Song"<<endl
        <<"6. Play Next "<<endl
        <<"7. Play Prev"<<endl
        <<"8. Shuffle"<<endl
        <<"9. Play Repeat"<<endl
        <<"10. Exit"<<endl;
    cout<<"Choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"input new song : "<<endl;
        inputNewSong(L,x);
        P = alokasi(x);
        cout <<"Pilih Posisi    : 1. First"<<endl
             <<"                  2. After"<<endl
             <<"                  3. Last"<<endl
             <<"Masukkan Posisi : ";cin>>number;
        if (number == 1) {
            insertFirst(L,P);
            cout << "Lagu Berhasil Diinput";
        }
        else if (number == 2) {
            address R = new elemenList;
            cout << "Masukkan ID Element Sebelum Element Baru Yang Akan Diinput : ";
            cin >> R->info.ID;
            insertAfter(L,P,R);
            cout << "Lagu Berhasil Diinput";
        }
        else if (number == 3) {
            insertLast(L,P);
            cout << "Lagu Berhasil Diinput";
        }
        else {
            cout << "Menu Salah"<<endl;
        }
        getch();
        break;
    case 2 :
        cout <<"Pilih Posisi    : 1. First"<<endl
             <<"                  2. After"<<endl
             <<"                  3. Last"<<endl
             <<"Masukkan Posisi : ";cin>>number;
        if (number == 1) {
            deleteFirst(L,P);
            cout << "Lagu Berhasil Dihapus";
            getch();
        }
        else if (number == 2) {
            address R = new elemenList;
            cout << "Masukkan ID Element Sebelum Element Yang Akan Dihapus : ";
            cin >> R->info.ID;
            deleteAfter(L,P,R);
            cout << "Lagu Berhasil Dihapus";
            getch();
        }
        else if (number == 3) {
            deleteLast(L,P);
            cout << "Lagu Berhasil Dihapus";
            getch();
        }
        else {
            cout <<"Menu Salah"<<endl;
            getch();
        }
        break;
    case 3 :
        cout << "Pilihan Sort : 1. Sort By ID"<<endl
             << "               2. Sort By Name"<<endl
             << "Pilihan      : ";cin >> condition;
        sortList(L,condition);
        getch();
        break;
    case 4 :
        printInfo(L);
        getch();
        break;
    case 5 :
        P = First(L);
        playSong(P);
        break;
    case 6 :
        playNext(P);
        break;
    case 7 :
        playPrev(P);
        break;
    case 8 :
        shuffleList(L);
        break;
    case 9 :
        int n;
        cout << "Masukkan Nilai Repeat-an : ";cin>>n;
        playRepeat(L,n);
        break;
    case 10 :
        cout<<"Thank You"<<endl;
        break;
    default :
        cout<<"Wrong Input"<<endl;
    }
}
