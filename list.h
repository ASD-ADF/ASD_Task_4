#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>
#include <iostream>

#define Nil NULL
#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

struct music {
    int ID;
    string name;
    string location;
};


typedef music infotype;
typedef struct elmlist *address;


/**
* IMPLEMENT CIRCULAR DOUBLE LINKED LIST
* USE ONLY ONE HEAD (FIRST)
*/

struct elmlist {
    //-------------  YOUR CODE HERE  -----------
    infotype info;
    address next;
    address prev;

    //----------------------------------------
};

struct List {
    //-------------  YOUR CODE HERE  -----------
    address first;
    //----------------------------------------
};



/** YOU DON'T NEED TO MODIFY THIS */

void createList(List &L);

address allocate(infotype x );
void deallocate(address &P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address &Prec, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &Prec, address &P);

address findElmByID(List L, infotype x );
address findElmByName(List L, infotype x );


#endif // LIST_H_INCLUDED
