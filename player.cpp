#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;


// infotype x di main.cpp masukkan data x di main.cpp
void inputNewSong(infotype &x){
    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-"){x.location="";}
}

void printInfo(List L){
    cout<<"     Music Play      "<<endl;
    cout<<endl;
    address *P = L->first;

    if(L.first  == NULL){
        cout<<"  Kosong "<<endl;
    }else if(L.first != NULL){
        cout<<"name : "<<Info(P).name<<endl
            <<"location: "<<Info(P).location<<endl;
        if (P ->next !=P){
            P = P->next;
        }while(P!=L.first){
            cout<<"  name     : "<<p->info.name<<endl
                <<"  location : ";
                if(p->info.location == "")
                {
                    cout<<"Default Location"<<endl<<endl;
                }
            P = P->next;
        }

    }
}

void playSong(address P){
    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void playNext(address &P){
    if (P != NULL){
        P = P->next;
        playSong(P);
    }
}

void playPrev(address &P){
    if (P != NULL){
        P = P->prev;
        playSong(P);
}

void shuffleList(List &L) {
    int random;
    address P;
    P= L.first;
    random = rand() % 10 + 1;
    for (int i=0; i<=random; i++) {
        P = Next(P);
    }
    playSong(P);
}

void sortList(List &L, int condition) {
    infotype temp;
    int i,j,k;
    if (condition == 1) {
        address P;
        P = L.first;
        for (i = 1; i <= countList(L,P)-1; i++) {
            P = L.first;
            for (j = 1 ; j <= (countList(L,P) - i) ; j++) {
                if (P->info.ID > P->next->info.ID) {
                    temp = P->next->info;
                    P->next->info = P->info;
                    P->info = temp;
                    P = P->next;
                } else {
                    P = P->next;
                }

            }
        }
    }
    else {
        address P;
        P = L.first;
        for (i = 1; i <= countList(L,P)-1; i++) {
            P = L.first;
            for (j = 1 ; j <= (countList(L,P) - i) ; j++) {
                char* ptr;
                char* next_ptr;
                string S = P->info.name;
                string T = P->next->info.name;
                ptr = &S.at(0);
                next_ptr = &T.at(0);
                int a = *ptr-48;
                int b = *next_ptr-48;
                if (a > b) {
                    temp = P->next->info;
                    P->next->info = P->info;
                    P->info = temp;
                    P = P->next;
                } else {
                    P = P->next;
                }
            }
        }
    }
}


void playRepeat(List L,address *P){
    if (L.first == NULL) {
        cout<<"Tidak dapat mencari lagu yang ingin diulang";
    }else{

    }
        int repeat;
        cout<<"Ulang Lagu Sebanyak : ";
        cin>>repeat;cout<<endl;
        if(repeat >=0 ){
            P = L.first;
            int i = 0;
            do{
                playSong(P);
                P = P->next;
                if(P == L.first){
                    i++;
                }
            }while (i != repeat);
        }
    }
}
