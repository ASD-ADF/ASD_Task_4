#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>
#include <iostream>

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
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
};



/** YOU DON'T NEED TO MODIFY THIS */

void createList(List &);

address allocate(infotype );
void deallocate(address &);

void insertFirst(List &, address );
void insertLast(List &, address );
void insertAfter(List &, address &, address);

void deleteFirst(List &, address &);
void deleteLast(List &, address &);
void deleteAfter(List &, address &, address &);

address findElmByID(List, infotype );
address findElmByName(List, infotype );


#endif // LIST_H_INCLUDED
