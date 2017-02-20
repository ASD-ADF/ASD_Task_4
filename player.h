#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "list.h"

int randomInt(int);
// helper random for shuffle

void printInfo(List);
// output the songs in the list

void playMusic(address P);
// play song from element P

void shuffleList(List &);
// shuffle the song list

void sortListByID(List &);
// sort song List by ID

void playRepeat(List &, int n);
// play the song list from the first song
// and repeat the list n times

void deleteMusicByID(List &, infotype);
// user input song ID
// remove the song from the list



#endif // PLAYER_H_INCLUDED
