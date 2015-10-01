#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

void inputNewSong(infotype &x)
{
  
}
void SearchSong(infotype &x)
{
    
}

void printInfo(List L)
{
  
}


void playNext(address &P)
{
    P = Next(P);
    playSong(P);
}
void playPrev(address &P)
// play the previous song from element P
{
    P =Prev(P);
    playSong(P);
}
void playPrev(address &P)
// play the previous song from element P
{
  
}
void shuffleList(List &L)
// shuffle the song list
{
    // random_shuffle;
    address P = First(L);
    int numRand = rand() % 10 + 1;
    for(int i=1; i <= numRand; i++)
    {
        P = Next(P);
    }
    playSong(P);
}
void sortList(List &L, int condition)
// sort song List by some condition
// example if condition = 1, then sort by ID
//          if condition = 2, then sort by name
 {
    infotype temp;
    int i,j;
    if (condition == 1) {
        address P;
        P = L.first;
        for (i = 1; i <= countElm(L)-1; i++) {
            P = L.first;
            for (j = 1 ; j <= (countElm(L) - i) ; j++) {
                if (P->info.ID > P->next->info.ID) {

                    temp = P->next->info;
                    P->next->info = P->info;
                    P->info = temp;
                    P = P->next;

                }
                else {
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
    }printInfo(L);
}
void playRepeat(List &L, int n)
{
    address P = First(L);
    int jumL = countElm(L);
    playSong(P);
    for(int i=1; i < jumL*n; i++)
    {
        playNext(P);
    }
}
