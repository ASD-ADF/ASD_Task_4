#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>
#include <iostream>

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

struct elmlist{
    //------------- your code here -----------
    infotype info;
    address next;
    address prev;
    //----------------------------------------
};

struct List{
    //------------- your code here -----------
    address first;
    address last;
    //----------------------------------------
};

void createList(List &);

address alokasi(infotype );
void dealokasi(address &);

void insertFirst(List &, address );
void insertLast(List &, address );
void insertAfter(address , address);

void deleteFirst(List &, address &);
void deleteLast(List &, address &);
void deleteAfter(address, address &);

address findElm(List, infotype );
int countElm(List L);


#endif // LIST_H_INCLUDED
