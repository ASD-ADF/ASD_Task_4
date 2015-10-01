#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

void inputNewSong(infotype &x)
{
    cout<<"Input Name Song (.wav) : ";
    cin>>x.name;
    cout<<"Input Song Location "<<endl<<"(Write - For Default Location) :";
    cin>>x.location;
    cout<<"Input Song ID : ";
    cin>>x.ID;
    if(x.location=="-")
    {
        x.location="";
    }
}

void printInfo(List L)
{
    address Q = First(L);
    do
    {
        if (L.first == NULL) break;
        cout<<"Name : "<<Info(Q).name<<endl
            <<"Location : "<<Info(Q).location<<endl;
        Q = Next(Q);
    }
    while(Q != L.first);
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

void shuffleList(List &L)
{
    address P = L.first;
    int numRand = rand() % 10 + 1;
    for(int i=1; i <= numRand; i++)
    {
        P = Next(P);
    }
    playSong(P);
}
void playRepeat(List &L, int n)
{
    address P = L.first;
    int totData = countElm(L);
    playSong(P);
    for(int i=1; i < totData*n; i++)
    {
        playNext(P);
    }
}

//void sortList(List &, int condition);
void sortList(List &L, int condition)
{
    infotype temp;
    int i,j,k;
    if (condition == 1)
    {
        address P;
        P = L.first;
        for (i = 1; i <= countElm(L)-1; i++)
        {
            P = L.first;
            for (j = 1 ; j <= (countElm(L) - i) ; j++)
            {
                if (P->info.ID > P->next->info.ID)
                {
                    temp = P->next->info;
                    P->next->info = P->info;
                    P->info = temp;
                    P = P->next;
                }
                else
                {
                    P = P->next;
                }

            }
        }
    }
    else if (condition == 2)
{
    address P;
    P = L.first;
    for (i = 1; i <= countElm(L)-1; i++)
    {
        P = L.first;
        for (j = 1 ; j <= (countElm(L) - i) ; j++)
        {
            if (P->info.name > P->next->info.name)
            {
                temp = P->next->info;
                P->next->info = P->info;
                P->info = temp;
                P = P->next;
            }
            else
            {
                P = P->next;
            }

        }
    }
}
}
