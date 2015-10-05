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

//Procedure PlayRepeat by M. Ricky J
void playRepeat(List &, int n){
    int loop,n;
    address P=First(L);
    do{
        playSong(P);
        P=Next(P);
        if (P==First(L)){
            loop++;
        }
    }while(loop<n)
};

//Procedure PlayPrev by S. Christian Adi P.
void playPrev(address &P) 
{
    P=Prev(P);
    playSong(P);
}
