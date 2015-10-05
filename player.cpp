#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

void playNext(address &P)
{
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

void shuffle(List &l)
{
    address p=First(l);
    int a;
    a=rand() % 2;
    cout<<a;
    switch(a)
    {

    case 0:

        while(Next(p)!=First(l))
        {
            playPrev(p);
            playNext(p);
            p=Next(p);
            playNext(p);
            break;
        }
    case 1:
        while(Next(p)!=First(l))
        {
            playNext(p);
            p=Next(p);
            playNext(p);
            break;
        }
    case 2:
        while(Next(p)!=First(l))
        {
            p=Next(p);
            playNext(p);
            p=Next(p);
            playNext(p);
            break;
        }
    }
}








