#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"

using namespace std;

void inputNewSong(infotype &x){
    cout<<" Input Song (.mp3) : ";
    cin>>x.Name;
    cout<<" Input Location That Song "<<endl<<"(Write - Default Location) :";
    cin>>x.Location;
    if(x.Location=="-"){x.Location="";}
}


void printInfo(List L)
{
    address Q = First(L);
    do
    {
        cout<<" Name : "<<Info(Q).Name<<endl
            <<" ID : "<<Info(Q).ID<<endl
            <<" Location : "<<Info(Q).Location<<endl;
        Q = Next(Q);
    }while(Q != First(L));
}


void playSong(address P){
    string filename = Info(P).location+Info(P).Name;
    cout<<" Playing "<<filename<<endl;
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

void playRepeat(List &L, int n)
{
    int a=1;
    address P=First(L);
    while(a<=n) {
        playSong(P);
        P=Next(P);
        if (P==First(L)){
            a++;
        }
    }
}

void playPrev(address &P)
{
    P=Prev(P);
    playSong(P);
}
