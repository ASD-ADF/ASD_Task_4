#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define First(L) L.first
#define Last(L) L.last
#define Next(P) P->next
#define Prev(P) P->prev
#define Info(P) P->info

using namespace std;

struct music
{
    int ID;
    string name;
    string location;
};


typedef music infotype;
typedef struct elmlist *address;

/**
* IMPLEMENT CIRCULAR DOUBLE LINKED LIST
*/

struct elmlist
{
    //------------- your code here -----------
    infotype info;
    address next;
    address prev;

    //----------------------------------------
};

struct List
{
    //------------- your code here -----------
    address first;
    address last;

    //----------------------------------------
};

void createList(List &L);

address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

address findElm(List L, infotype x);
address findElm2(List L, infotype x); //new function



#endif // LIST_H_INCLUDED
