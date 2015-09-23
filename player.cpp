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
        cout<<"name : "<<Info(Q).name<<endl
            <<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
    }while(Q!= First(L));
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

void playPrev(address &P)
{
    P = Prev(P);
    playSong(P);
}

void playRepeat(List &L, int n)
{
    int x = 0,v = n;
    address P = First(L);

    do
    {
        system("cls");
        cout<<"Repeat "<<v<<" times"<<endl;
        playSong(P);
        P=Next(P);
        if (P == First(L))
        {
            x++;
            v--;
        }
    }while (x<n);

}
