#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "list.h"

void inputNewSong(List &L, infotype &);
// input new song into the list
// procedure receive input from user

void printInfo(List);
// output the songs in the list

void playSong(address P);
// play song from element P

void playNext(address &P);
// play the next song from element P

void playPrev(address &P);
// play the previous song from element P

void shuffleList(List &L);
// shuffle the song list

void sortList(List &L, int condition);
// sort song List by some condition
// example if condition = 1, then sort by ID
//          if condition = 2, then sort by name

void playRepeat(List &L, int n);
// play the song list from the first song
// and repeat the list n times


#endif // PLAYER_H_INCLUDED
