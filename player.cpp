#include <iostream>
#include <string>
#include <windows.h>
#include "DoubleCircularH.h"
#include "Player.h"

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
        cout<<"Nama : "<<Info(Q).name<<endl
            <<"Lokasi: "<<Info(Q).location<<endl
            <<"ID : "<<Info(Q).ID<<endl;
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

void playPrev(address &P)
{
    P = Prev(P);
    playSong(P);
}
void sortList(List &l, int condition)
{
    if (condition==1)
    {
        address p;
        address q;
        List l2;
        createList(l2);
        while (First(l)!=NULL)
        {
            deleteFirst(l,p);
            insertID(l2,p);
        }
        while (First(l2)!= NULL)
        {
            deleteFirst(l2,p);
            insertLast(l,p);
        }
    }
    else
    {
        address p;
        address q;
        List l2;
        createList(l2);
        while (First(l)!=NULL)
        {
            deleteFirst(l,p);
            insertNM(l2,p);
        }
        while (First(l2)!= NULL)
        {
            deleteFirst(l2,p);
            insertLast(l,p);
        }
    }
};
