#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

void inputNewSong(infotype &x){
    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-"){x.location="";}
}

void printInfo(List L)
{
    address Q = First(L);
    while(Q != NULL)
    {
        cout<<"name : "<<Info(Q).name<<endl
            <<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
    }
}

void playSong(address P){
    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void playNext(address &P){
    P = Next(P);
    playSong(P);
}

void sortList (List &L, int condition) {
    if(condition==1) {
        address P;
        address Q;
        List L2;
        createList(L2);
        P=First(L);
        while (First(L)!=NULL){
            deleteFirst(L,P);
            insertID(L2,P);
        }
        while (First(L2)!=NULL) {
            deleteFirst(L2,P);
            insertID(L,P);
        }
    }
    else {
        address P,Q;
        List L2;
        createList(L2);
        while (First(L)!=NULL) {
            deleteFirst(L,P);
            insertName(L2,P);
        }
        while (First(L2)!=NULL) {
            deleteFirst(L2,P);
            insertLast(L,P);
        }
    }
}
