#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

void inputNewSong(infotype &x, List &L)
{
    address cek;
    x.ID = 0;
    cek = First(L);
    x.ID++;
    while (cek != Last(L))
    {
        cek = Next(cek);
        x.ID++;
    }
    x.ID = x.ID + 1;
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
    address Q = First(L);
    if (Q == NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        do
        {
            cout<<"name : "<<Info(Q).name<<endl
                <<"location: "<<Info(Q).location<<endl
                <<"ID : "<<Info(Q).ID<<endl;
            Q = Next(Q);
        }
        while(Q!= First(L));
    }
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
    }
    while (x<n);

}
void shuffleList(List &L)
{
    List L2;
    address P;
    createList(L2);

    while (First(L) != NULL)
    {
        deleteFirst(L,P);
        insertFirst(L2,P);
    }
    while (First(L2) != NULL)
    {
        deleteFirst(L2,P);
        insertLast(L,P);
    }
}

void sortList(List &L, int condition)
{
    address P,Q,minn;

    List L2;
    createList(L2);

    while (First(L) != NULL)
    {
        deleteFirst(L,P);
        insertFirst(L2,P);
    }
    if (condition == 1)
     {
         while (First(L2) != NULL)
         {
             P = First(L2);
             minn = P;
             Q = Next(P);
             while (Q != First(L2))
             {
                 if (Info(Q).ID < Info(minn).ID)
                 {
                     minn = Q;
                 }
                 Q = Next(Q);
             }
             deletee(L2,minn);
             insertLast(L,minn);
         }
     }
     else if (condition == 2)
     {
          while (First(L2) != NULL)
         {
             P = First(L2);
             minn = P;
             Q = Next(P);
             while (Q != First(L2))
             {
                 if (Info(Q).name < Info(minn).name)
                 {
                     minn = Q;
                 }
                 Q = Next(Q);
             }
             deletee(L2,minn);
             insertLast(L,minn);
         }
     }
}
