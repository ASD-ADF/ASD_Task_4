#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

void inputNewSong(infotype &x)
{
    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-")
    {
        x.location="";
    }
}


void printInfo(List L)
{
    address P = First(L);
    do
    {
        cout << "nama: "<< Info(P).name << endl
             << "Location: " << Info(P).location << endl
             << "ID: " << Info(P).ID << endl;
        P=Next(P);
    }
    while(P!=First(L));

}

void playSong(address P)
{
    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void playNext(address &P){
    P = Next(P);
    playSong(P);
}

void playRepeat(List &l, int n)
{
    int a=1;
    address p=First(l);
    while (a<=n)
    {
        playSong(p);
        p=Next(p);
        if (p==First(l))
        {
            a++;
        }
    }
};

