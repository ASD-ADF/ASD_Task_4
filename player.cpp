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
void sortList(List &L, int condition) {
    switch(condition) {
        case 1: {
            bool blmselesai = true;
            address tmp;
            while(blmselesai) {
                blmselesai=false;
                address P=Next(First(L));
                while(Next(P)!=Next(First(L))) {
                    if(Info(P).ID<Info(Prev(P)).ID) {
                        address tmp=new elemenList;
                        Info(tmp)=Info(Prev(P));
                        Info(Prev(P))=Info(P);
                        Info(P)=Info(tmp);
                        blmselesai=true;
                    }
                    P=Next(P);
                }
            }
        }
        case 2: {
            bool blmselesai = true;
            address tmp;
            while(blmselesai) {
                blmselesai=false;
                address P=Next(First(L));
                while(Next(P)!=Next(First(L))) {
                    if(Info(P).name<Info(Prev(P)).name) {
                        address tmp=new elemenList;
                        Info(tmp)=Info(Prev(P));
                        Info(Prev(P))=Info(P);
                        Info(P)=Info(tmp);
                        blmselesai=true;
                    }
                    P=Next(P);
                }
            }
        }
    }
}

