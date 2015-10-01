#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L)
{
    First(L) = NULL;
}

address alokasi(infotype x)
{
    address P = new elemenList;
    Info(P) = x;
    Next(P) = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
{
    if ((L.first != NULL) && (L.last != NULL)) {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
        L.first->prev= L.last;
    }
    else {
        L.first = P;
        L.last  = P;
        Prev(P) = L.last;
        Next(P) = L.first;
    }
}

void insertLast(List &L, address P)
{
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        L.last->next = L.first;
        L.first->prev = L.last;
    }
}
void insertAfter(List &L, address P, address Prec)
{

    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        infotype x;
        P = findElm(L,x);
        Next(P) = Next(Prec);
        Prec->prev= P;
        prev(next(P))=Prec;
        Next(P) = Prec;
    }
}

void deleteFirst(List &L, address &P)
{
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            P = L.first;
            P->next = NULL;
            P->prev = NULL;
            L.first = NULL;
            L.last  = NULL;
            dealokasi(P);
        }
        else {
            P = First(L);
            First(L) = Next(P);
            Next(P) = NULL;
            L.first->prev=L.last;
            dealokasi(P);
        }
    }
    else {
        cout<<"List Kosong"<<endl;
    }
}

void deleteLast(List &L, address &P)
{
    if (L.first == NULL) {
        cout<<"list kosong"<<endl;
    }
    else if(Next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        P = L.last;
        L.last = P->prev;
        P->next= NULL;
        P->prev= NULL;
        L.last->next= L.first;
        L.first->prev= L.last;
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    infotype x;
    P = findElm(L,x);
    Prec = Next(P);
    Next(P) = Next(Prec);
    Next(Prec) = NULL;
    Prev(next(Prec)) = P;
}

address findElm(List L, infotype x){
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}

int countList(List &L, address P) {
    int i=0;
    if (L.first == NULL)
    {
        return 0;
    }
    else {
        P = L.first;
        do {
            i++;
            P = P->next;
        } while (P!=L.first);
    return i;
    }
}
