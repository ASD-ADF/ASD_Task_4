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
