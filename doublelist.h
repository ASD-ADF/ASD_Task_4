#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

#include <iostream>
#include "my_data.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;


/**
* Type infotype : mytype
* Type address  : pointer to ElmList
*
* Type ElmList <
*	info : infotype
*	next : address
*	prev : address
* >
*
* Type List : <
*   first : address
*   last  : address
* >
*
**/



typedef mytype infotype;
typedef struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct List{
    address first;
};



// define a function and a procedure to allocate and deallocate an element list
void createList(List &L);
address allocate(infotype x);
void deallocate(address &P);

// define insert and delete procedure
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void insertAfter(List &L, address Prec, address P);
void deleteAfter(List &L, address Prec, address &P);

// define search-by-ID function and view procedure
address findElm(List L, infotype x);
void printInfo(List L);


#endif // DOUBLELIST_H_INCLUDED
