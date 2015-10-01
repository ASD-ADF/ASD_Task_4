#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
// -----------------
#include <string>
//#include "player.h"
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) L.first
#define last(L) ((L).last)
// ------- Merged ------------
#define First(L) L.first
#define Last(L) L.last
#define Next(P) P->next
#define Prev(P) P->prev
#define Info(P) P->info

using namespace std;

struct data
{
    int ID;
    string name;
    string location;
};

typedef data infotype;
typedef struct elemenList *address;
struct elemenList
{
    infotype info;
    address next;
    address prev;
};

struct List
{
    address first;
    address last;
};

void createList(List &);

address alokasi(infotype);
void dealokasi(address &);

void insertFirst(List &, address);
void insertLast(List &, address);
void insertAfter(List &, address, address);

void deleteFirst(List &, address &);
void deleteLast(List &, address &);
void deleteAfter(List &, address &, address &);

void clearList(List &);

address findElm(List, infotype);
address findElm(List, string);

int countNodes(List);
void sortByID(List &);
void sortByName(List &);

#endif // LIST_H_INCLUDED
