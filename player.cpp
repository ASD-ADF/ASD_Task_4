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
    cout<<"input song ID : ";
    cin>>x.ID;
    if(x.location=="-"){x.location="";}
}

void printInfo(List L)
{
    address Q = First(L);
    while(Q != NULL)
    {
        cout<<"ID   : "<<Info(Q).ID<<endl
            <<"name : "<<Info(Q).name<<endl
            <<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
        if (Q == Next(Last(L)))
        {
            break;
        }
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

int countElm(List L)
{
    int num = 0;
    if (L.first == NULL) return 0;
    address Q = First(L);
    do
    {
        num++;
        Q = Next(Q);
    }
    while(Q != L.first);
    return num;
}

void sortList(List &L, int condition)
{
    infotype temp;
    int i,j,k;
    if (condition == 1)
    {
        address P;
        P = First(L);
        for (i = 1; i <= countElm(L)-1; i++)
        {
            P = First(L);
            for (j = 1 ; j <= (countElm(L) - i) ; j++)
            {
                if (Info(P).ID > Info(Next(P)).ID)
                {
                    temp = Info(Next(P));
                    Info(Next(P)) = Info(P);
                    Info(P) = temp;
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
        P = First(L);
        for (i = 1; i <= countElm(L)-1; i++)
        {
            P = First(L);
            for (j = 1 ; j <= (countElm(L) - i) ; j++)
            {
                if (Info(P).name > Info(Next(P)).name)
                {
                    temp = Info(Next(P));
                    Info(Next(P)) = Info(P);
                    Info(P) = temp;
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

void playRepeat(List &L, int n)
{
    address P;
    cout<<"Masukan jumlah repeat :";
    cin>>n;
    while(n>0)
    {
        P = First(L);
        playSong(P);
        while (P != Last(L))
        {
            playNext(P);
        }
        n--;
    }
}

void shuffleList(List &L)
{
    int jum;
    address P = First(L);
    cout<<"Suffle berapa lagu :";
    cin>>jum;
    while(jum>0)
    {
        int numRand = rand() % 10 + 1;
        for(int i=1; i <= numRand; i++)
        {
            P = Next(P);
        }
        playSong(P);
        jum--;
    }
}
