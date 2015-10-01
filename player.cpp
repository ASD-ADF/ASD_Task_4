#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

int id = 1;

void inputNewSong(infotype &x) {
    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    x.ID = id;
    id++;
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
            if(Last(L) == Q)
                cout << "Last IN THE LIST!" << endl;
            cout << "=================================" << endl;
            cout << "Previous: " << Info(Prev(Q)).name << endl
                << "Next: " << Info(Next(Q)).name << endl << endl;
            Q = Next(Q);
        } while(First(L) != Q);
    }
    else cout << "List empty!" << endl;
}

void playSong(address P){
    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_ASYNC||SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void playNext(address &P){
    P = Next(P);
    playSong(P);
}

void playRepeat(List &L, int n) {
    int num = 0;
    cout << "Anda akan memutar list sebanyak " << n << " kali!" << endl;
    while(n != num) {
        address cur = First(L);
        do {
            playSong(cur);
            cur = Next(cur);
        } while(First(L) != cur);
        num++;
    }
}

void shuffleList(List &L) {
    List M;
    createList(M);
    int nodes = countNodes(L);
    int jml = 0;
    while(jml < nodes) {
        jml++;
        address P = First(L);
        int rnum;
        rnum = 1 + rand() % countNodes(L);
        int i = 0;
        while(i < rnum) {
            i++;
            P = Next(P);
        }
    //deleteAfter(L, P, Prev(P));
//        address newElm = new elemenList;
//        Info(newElm) = Info(P);
        deleteAfter(L, P, Prev(P));
        insertLast(M, P);
//        dealokasi(P);
    }
    First(L) = First(M);
    Last(L) = Last(M);
}

void sortList(List &L, int condition) {
    switch(condition) {
        case 1: { // Sort BY ID
            sortByID(L);
            break;
        }
        case 2: { // Sort BY NAME
            sortByName(L);
            break;
        }
    }
}

void playPrev(address &P){
    P = Prev(P);
    playSong(P);
}
