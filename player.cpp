#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "list.h"
#include "player.h"
using namespace std;

void play_prev (address &P)
{
    P=prev(P);
    play_music(P);
}

void play_last_played (address &P)
{
    play_music(P);
}

void play_repeat (list &L, address P)
{
    int n;

    cout<<"Repeat untuk : ";
    cin>>n;
    while (n>0)
    {
        P=first(L);
        play_music(P);
        play_next(P);
        while (P!=last(L))
        {
            play_next(P);
        }
        n--;
    }
}

void play_shuffle (list &L, int temp, address &P)
{
    cout<<"=====SHUFFLE MUSIC====="<<endl;
    P=first(L);
    if (P!=NULL)
    {
        int shuff=rand() % temp+1;
        for(int i=1; i<=shuff; i++)
        {
            P=next(P);
        }
        play_music(P);
    }
    else
    {
        cout<<"No music, press any key"<<endl;
        getch();
    }
}
