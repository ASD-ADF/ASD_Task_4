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
    if(First(L) != NULL && Last(L) != NULL) {
        do {
            cout << "Name: " << Info(Q).name << " (" << Info(Q).ID << ") - " << Q << endl;
            if(First(L) == Q)
                cout << "FIRST IN THE LIST!" << endl;
            if(Last(L) == Q) {
                cout << "Last IN THE LIST!" << endl;
            }
            cout << "Previous: " << Info(Prev(Q)).name << endl
                << "Next: " << Info(Next(Q)).name << endl
                << "PrevA: " << Prev(Q) << endl
                << "NextA: " << Next(Q) << endl << endl;
            Q = Next(Q);
        } while(First(L) != Q);
    }
    else cout << "List empty!" << endl;
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

<<<<<<< HEAD
void playPrev(address &P)
{
    P = Prev(P);
    playSong(P);
}



=======
void playPrev(address &P){
//Di tambahin #define Prev(P) P->prev di list.h sama tambahin address prev di struct elemenlist fir!, mohon dicoba
    P = Prev(P);
    playSong(P);
}
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
