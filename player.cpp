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

void playPrev(address &P){
    P = Prev(P);
    playSong(P);
}

void playRepeat(List &L, int n)
 {
     address P = L.first;
     int repeat = countElm(L);
     playSong(P);
     for(int i=1; i = totData*n; i=1+1)
     {
         playNext(P);
     }
 }

void shuffleList(List &L)
{
    address P = L.first;
    int shuffle = rand() % 10 + 1;
    for(int i=1; i <= numRand; i=1+1)
    {
        P = Next(P);
    }
    playSong(P);
}

void sortList(List &L, int condition)
{
    infotype temp;
    int i,j,k;
    if (condition == 1)
    {
        address P;
        P = L.first;
        for (i = 1; i <= countElm(L)-1; i=1+1)
        {
            P = L.first;
            for (j = 1 ; j <= (countElm(L) - i) ; j=j+1)
            {
                if (Next(P)infotype.ID > Next(P)infotype.ID)
                {
                    temp = Next(P)infotype;
                    Next(P)infotype = Next(P)infotype;
                    Next(P)infotype = temp;
                    P = Next(P);
                }
                else
                {
                    P = Next(P);
                }

            }
        }
    }
    else if (condition == 2)
    {
        address P;
        P = L.first;
        for (i = 1; i <= countElm(L)-1; i=i+1)
        {
            P = L.first;
            for (j = 1 ; j <= (countElm(L) - i) ; j=j+1)
            {
                if (Next(P)infotype.name > Next(P)infotype.name)
                {
                    temp = Next(P)infotype;
                    Next(P)infotype = Next(P)infotype;
                    Next(P)infotype = temp;
                    P = Next(P);
                }
                else
                {
                    P = Next(P);
                }

            }
        }
    }
}
