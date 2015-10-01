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
    do
    {
        cout<<"name : "<<Info(Q).name<<endl;
        cout<<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
    }while(Q != First(L));
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

void playPrev(address &P){
    P = Prev(P);
    playSong(P);
}

void shuffleList(List &L){
    address Q = First(L);
    if(Next(Q) == NULL){
        playSong(Q);
    }else{
        int id;
        do{
            Q = Next(Q);
            id = Info(Q).ID;
        }while(Next(Q) != First(L));

        int random = rand() % id + 1;

        Q = First(L);
        while(Info(Q).ID != random){
            Q = Next(Q);
        }
        playSong(Q);
    }
}


void sortList(List &, int condition);
// sort song List by some condition
// example if condition = 1, then sort by ID
//          if condition = 2, then sort by name

void playRepeat(List &L, int n){
// play the song list from the first song
// and repeat the list n times
    address P;
    int times;
    cout<<"How many times? "; cin>>times;

    for(int i=0; i<times; i++){
        P = First(L);
        playSong(P);
        P = Next(P);
        while(Last(L) != First(L) and P != First(L)){
            playSong(P);
            P = Next(P);
        }
    }
}
