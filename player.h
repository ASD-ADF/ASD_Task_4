#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "list.h"

    /** YOU DON'T NEED TO MODIFY THIS */



int randomInt(int);
// helper random for shuffle
    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}

void printInfo(List);
// output the songs in the list

void playMusic(address P);
// play song from element P

void shuffleList(List &);
// shuffle the song list
     address P = first(L);
    int jumlah = 0;
    do {
        P = P -> next;
        jumlah++;
    } while (P != first(L));
    while (jumlah > 0) {
        P = first(L);
        int k = randomInt(jumlah);
        while (k != 0) {
            P = next(P);
            k--;
        }
        address Q = P;
        deleteAfter(L,  prev(P), Q);
        insertFirst(L, Q);
        jumlah--;
    }
void playRepeat(List &, int n);
// play the song list from the first song
// and repeat the list n times
    address P = first(L);
    for (int i = 0; i < n; i++) {
        do {
            playMusic(P);
            P =  next(P);
        } while (P != first(L));
    }
void deleteMusicByID(List &, infotype);
// user input song ID
// remove the song from the list
    address P;
    if (first(L) != NULL) {
        if (findElmByID(L, x) != NULL) {
            deleteAfter(L, findElmByID(L, x) -> prev, P);
            deallocate(P);
        }
    }


#endif // PLAYER_H_INCLUDED
