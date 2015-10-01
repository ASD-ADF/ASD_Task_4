#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>

using namespace std;

List L;
address P;
address Prec;
infotype x;
int pilihan;
int number;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    createList(L);
    menu();
    return 0;
}

void menu() {
    int pil;
    do {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    } while (pil<10);
}

void displayMenu() {
    cout << endl << "======= MENU ========= " << endl;
    cout<< "1. Input New Song" <<endl;
    cout<< "2. View List" <<endl;
    cout<< "3. Play Songs" <<endl;
    cout<< "4. Delete song" <<endl;
    cout<< "5. Shuffle Songs" <<endl;
    cout<< "6. Sort Songs" << endl;
    cout<<"Choose menu: ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"[INPUT] NEW SONG "<<endl;
        cout<<"Berikut adalah pilihan untuk posisi input data yang baru:"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"Masukkan nomor menu yang anda inginkan: ";
        cin>>pilihan;
        if (pilihan==1)
        {
            inputNewSong(x);
            P = alokasi(x);
            insertFirst(L,P);
            break;
        }
        else if (pilihan==2)
        {
            inputNewSong(x);
            P = alokasi(x);
            insertLast(L, P);
            break;
        }
        else if (pilihan==3)
        {
            infotype x, y;
            cout<<"Masukkan ID lagu yang ingin Anda inputkan dengan data baru setelahnya: ";
            cin>>x.ID;
            if(findElm(L, x) != NULL) {
                inputNewSong(y);
                P = alokasi(y);
                insertAfter(L, P, findElm(L, x));
            }
            else {
                cout << "Data yang anda cari tidak ada!" << endl;
            }
            break;
        }
        break;
    case 2:
        printInfo(L);
        break;
    case 3:
        cout<<"[PLAY] A SONG "<<endl;
        cout<<"Berikut adalah pilihan untuk memutar lagu:"<<endl;
        cout<<"1. Play First Song"<<endl;
        cout<<"2. Play Next "<<endl;
        cout<<"3. Play Previous"<<endl;
        cout<<"4. Play Last Song"<<endl;
        cout<<"5. Repeat Songs (repeat list)"<<endl;
        cout<<"6. Search by name and play"<<endl;
        cout<<"Masukkan nomor menu yang anda inginkan: ";
        cin>>pilihan;
        if(pilihan == 1) {
            P = First(L);
            playSong(P);
            break;
        }
        else if(pilihan == 2) {
            playNext(P);
            break;
        }
        else if(pilihan == 3) {
            playPrev(P);
            break;
        }
        else if(pilihan == 4) {
            playSong(P);
            break;
        }
        else if(pilihan == 5) {
            int in;
            cout << "Play Repeat: Akan memutar seluruh lagu dalam list dan diulang sebanyak N kali." << endl
                << "Berapa kali Anda ingin mengulang list? ";
            cin >> in;
            playRepeat(L, in);
            break;
        }
        else if(pilihan == 6) {
            string song;
            cout << "Masukkan nama lagu yang ingin diputar: ";
            cin >> song;
            if(findElm(L, song) != NULL) {
                playSong(findElm(L, song));
            }
        }
        break;
    case 4:
        {
        cout<<"[DELETE] SONGS"<<endl;
        cout<<"Berikut adalah pilihan untuk delete song: "<<endl;
        cout<<"1. Delete First"<<endl;
        cout<<"2. Delete Last"<<endl;
        cout<<"3. Delete After"<<endl;
        cout<<"Masukkan nomor menu yang anda inginkan: ";
        cin>>number;
        if (number==1)
        {
            deleteFirst(L,P);
            dealokasi(P);
            break;
        }
        else if (number==2)
        {
            deleteLast(L,P);
            dealokasi(P);
            break;
        }
        else if (number==3)
        {
            infotype x;
            cout<<"Masukkan ID lagu sebelum lagu yang ingin Anda hapus: ";
            cin>>x.ID;
            if(findElm(L, x) != NULL) {
                address addr_hps = findElm(L, x);
                deleteAfter(L, P, addr_hps);
                dealokasi(P);
            }
            else {
                cout << "Data yang anda cari tidak ada!" << endl;
            }
            break;
        }
        break;
    }
    case 5: {
        shuffleList(L);
        cout << "List tershuffle." << endl << endl;
        break;
    }
    case 6: {
        int num;
        do {
            cout << "Masukkan tipe sort yang ingin Anda lakukan:" << endl
                << "1. Sort By ID" << endl
                << "2. Sort By Name" << endl
                << "Pilihan: ";
            cin >> num;
            cout << endl;
        } while (num < 1 && num > 2);
        sortList(L, num);
        break;
    }
    default :
        cout<<"Nomor menu tidak ditemukan. Silahkan masukkan kembali"<<endl;
    }
}
