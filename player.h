#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "list.h"

void input_music (infotype &x);
void print_info (list L);
void play_music (address P);
void play_next(address &P);
void play_prev (address &P);
void play_last_played (address &P);
void play_repeat (list &L, address P);
void play_shuffle (list &L, int temp, address &P);

#endif // PLAYER_H_INCLUDED
