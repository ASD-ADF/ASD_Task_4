#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>

#define First(L) L.first
#define Last(L) L.last
#define Next(P) P->next
#define Prev(P) P->prev
#define Info(P) P->info


using namespace std;


struct infotype
{
    int ID;
    string name;
    string location;
};


typedef struct elemenList *address;
struct elemenList
{
    infotype info;
    address next,prev;
};


struct List
{
    address first,last;
};
void createList(List &);

address alokasi(infotype );
void dealokasi(address &);

void insertFirst(List &, address );
void insertLast(List &, address );
void insertAfter(List &, address, address );
void deleteFirst(List &, address &);
void deleteLast(List &, address &);
void deleteAfter(List &, address &, address &);

address findElm(List, infotype );
int countElm(List L);

#endif // LIST_H_INCLUDED
