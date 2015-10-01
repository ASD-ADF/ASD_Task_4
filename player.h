#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "list.h"

void input_song(music &m);
// input new song into the list
// procedure receive input from user

void current_song(element *m);
// output the current song played

void view_music_list(List L);
// output the songs in the list

void play_song(element *m);
// play song from element p

void play_next(element *&m);
// play the next song from element P

void play_prev(element *&m);
// play the previous song from element P

void shuffle_list(List &L);
// shuffle the song list

void sort_list(List &L, int condition);
//sort list by ID or Name

void repeat_all_song(List L,element *m);

#endif // PLAYER_H_INCLUDED
