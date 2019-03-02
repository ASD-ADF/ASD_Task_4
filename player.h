#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "list.h"

/** YOU DON'T NEED TO MODIFY THESE **/

int randomInt(int);
// helper random for shuffle

void printInfo(List);
// output the songs in the list

void playMusic(address P);
// play song from element P

void shuffleList(List &, int index_ID);
// shuffle the song list

void playRepeat(List &, int n,int index_ID);
// play the song list from the first song
// and repeat the list n times

void deleteMusicByID(List &, infotype);
// user input song ID
// remove the song from the list



#endif // PLAYER_H_INCLUDED
