#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>
#include <iostream>

#define First(L) L.First
#define Last(L) L.Last
#define Next(P) P->Next
#define Prev(P) P->Prev
#define Info(P) P->Info

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
    infotype Info;
    address Next, Prev;
    //----------------------------------------
};

struct List{
    //------------- your code here -----------
    address First, Last;
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


#endif // LIST_H_INCLUDED
