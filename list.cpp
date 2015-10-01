#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L)
{
    First(L) = NULL;
    Last(L) = NULL;
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
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
        P->prev = L.last;
        P->next = L.first;
    }
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
        L.first->prev = L.last;
        L.last->next = L.first;
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
        address Q = First(L);
        while(Next(Q) != NULL)
        {
            Q = Next(Q);
        }
        Next(Q) = P;
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
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    if (L.first == NULL) {
        cout << "List Kosong" <<endl;
    }
    else if (L.first->next == NULL) {
        P = L.first;
        P->prev = NULL;
        P->next = NULL;
        L.first = NULL;
        L.last = NULL;
        dealokasi(P);
    }
    else {
        P = L.first;
        L.first = P->next;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->next = NULL;
        P->prev = NULL;
        dealokasi(P);
    }
}


void deleteLast(List &L, address &P)
{
    if(Next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        address Q = First(L);
        while(Next(Next(Q)) != NULL)
        {
            Q = Next(Q);
        }
        P = Next(Q);
        Next(Q) = NULL;
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
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
