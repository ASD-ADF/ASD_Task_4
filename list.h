#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
<<<<<<< HEAD
#include <string>
#include "player.h"
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
=======

#define First(L) L.first
#define Last(L) L.last
#define Next(P) P->next
#define Prev(P) P->prev
#define Info(P) P->info
>>>>>>> fcc968103c85a503525044154016c90cd42284ea

using namespace std;

struct data
{
    int ID;
    string name;
    string location;
};

typedef data infotype;
typedef struct elemenList *address;
struct elmlist
{
    infotype info;
    address next;
    address prev;
};

struct list
{
    address first;
    address last;
};

<<<<<<< HEAD
address alokasi (infotype x);
address findElm (list L, string x);
void dealokasi(address P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(List &, address P, address Prec);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(List &L, address &P, address &Prec);
void sortByID(List &);
void sortByName(List &);
int countNodes(List);
=======
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

int countNodes(List);
void sortByID(List &);
void sortByName(List &);
>>>>>>> fcc968103c85a503525044154016c90cd42284ea

#endif // LIST_H_INCLUDED
