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
typedef struct elmlist *adr;

/**
* IMPLEMENT CIRCULAR DOUBLE LINKED LIST
*/

struct elmlist{
    //------------- your code here -----------
    infotype info;
    adr next;
    adr prev;
    //----------------------------------------
};

struct List{
    //------------- your code here -----------
    adr first;
	adr last;
    //----------------------------------------
};

void createList(List &L);

adr alokasi(infotype x);
void dealokasi(adr &P);

void insertFirst(List &L, adr P);
void insertLast(List &L, adr P);
void insertAfter(List &L, adr Prec, adr P);

void deleteFirst(List &L, adr &P);
void deleteLast(List &L, adr &P);
void deleteAfter(List &L, adr Prec, adr &P);

adr findElm(List, infotype );
int countElm(List L);


#endif // LIST_H_INCLUDED
