#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "list.h"


void shuffleList(List &);
// shuffle the song list

void sortList(List &, int condition);
// sort song List by some condition
// example if condition = 1, then sort by ID
//          if condition = 2, then sort by name

void playNext(address &P);
// play the next song from element P


void playPrev(address &P);
// play the previous song from element P

void playRepeat(List &, int n);
// play the song list from the first song
// and repeat the list n times


#endif // PLAYER_H_INCLUDED
