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
    if (First(L) == NULL)
    {
        First(L) = P;
        Last(L) = P;
        Next(P) = P;
        Prev(P) = P;
    }
    else
    {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Prev(First(L)) = P;
        Next(Last(L))=P;
        First(L) = P;
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
    if(First(L) == NULL)
    {
        cout << "Data Kosong";
    }
    else if(First(L) == Last(L))
    {
        P = First(L);
        Next(P) = NULL;
        Prev(P) = NULL;
        First(L) = NULL;
        Last(L) = NULL;
    }
    else
    {
        P = First(L);
        First(L) = Next(P);
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
        Next(P) = NULL;
        Prev(P) = NULL;
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
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L)) = P;
        Prev(First(L)) = P;
        Last(L) = P;
    }
}

void insertAfter(List &L, address P, address Prec)
{
    if(Prec == Last(L))
    {
        insertLast(L,P);
    }
    else
    {
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Next(Prec) = P;
        Prev(Next(Prec)) = P;
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
