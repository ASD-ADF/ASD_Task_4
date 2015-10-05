//test
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
    address next;
    address prev;
};

struct List
{
    address first;
    address last;
};

void createList(List &L);

address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address &Prec);
void insertID (List &L2, address P);
void insertName(List &L2, address P);

address findElm(List L, infotype x);



#endif // LIST_H_INCLUDED
