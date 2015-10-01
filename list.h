#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <string>
#include <windows.h>

#define First(L) L.first
#define Next(P) P->next
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
    address First;
    address Last;
};

void createList(List &);

address alokasi(infotype );
void dealokasi(address &);

void insertFirst(List &, address );
void insertLast(List &, address );
void insertAfter(List &, address , address );

void deleteFirst(List &, address &);
void deleteLast(List &, address &);
void deleteAfter(List &, address &, address &);

address findElm(List, infotype );
int countElm(List L)
{
     int num = 0;
     if (L.first == NULL) return 0;
     address Q = First(L);
     do{
         num++;
         Q = Next(Q);
     }while(Q != L.first);
     return num;
}


#endif // LIST_H_INCLUDED
