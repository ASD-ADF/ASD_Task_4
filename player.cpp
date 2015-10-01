#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "list.h"
#include "player.h"
using namespace std;

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "list.h"
#include "player.h"
using namespace std;

void input_music (infotype &x)
{
    cout<<"=====IMPORT MUSIC====="<<endl;
    cout<<"Input music name (.wav) : ";
    cin>>x.name;
    cout<<"Input music location (write - for default location) : ";
    cin>>x.location;
    cout<<"======================"<<endl;
    if(x.location=="-")
        x.location="";
}

void print_info (list L)
{
    address Q;

    Q=first(L);
    if (Q!=NULL)
    {
        cout<<"=====VIEW PLAYLIST====="<<endl;
        cout<<info(Q).id<<" "<<info(Q).name<<endl;
        Q=next(Q);
        while(Q!=first(L))
        {
            cout<<info(Q).id<<" "<<info(Q).name<<endl;
            Q=next(Q);
        }
    }
    else
    {
        cout<<"=====VIEW PLAYLIST====="<<endl;
        cout<<"No music"<<endl;
    }
}

void play_music (address P)
{
    string filename;

    filename=info(P).name;
    cout<<"Playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void play_next (address &P)
{
    P=next(P);
    play_music(P);
}

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
