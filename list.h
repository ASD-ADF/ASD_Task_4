#ifndef DOUBLECIRCULARH_H_INCLUDED
#define DOUBLECIRCULARH_H_INCLUDED

#include <string>
#include <windows.h>
#include <conio.h>

#define First(L) L.First
#define Next(P) P->Next
#define Info(P) P->Info
#define Last(L) L.Last
#define Prev(P) P->Prev

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
    infotype Info;
    address Next;
    address Prev;
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

address findElm2(List, infotype );

void insertID (List &, address );
void insertNM (List &, address );

#endif // DOUBLECIRCULARH_H_INCLUDED
