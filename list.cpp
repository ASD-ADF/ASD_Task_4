#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L)
{
    First(L) = NULL;
    Last (L) = NULL;
}

address alokasi(infotype x)
{
    address P = new elemenList;
    Info(P)   = x;
    Next(P)   = NULL;
    Prev(P)   = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
{
    if (First(L)==NULL){
        First(L) = P;
        Last(L)  = P;
    } else {
        Next(P)         = First(L);
        Prev(First(L))  = P;
        Next(Last(L))   = P;
        Prev(L)         = Last(L);
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
        if (First(L) == NULL){
            insertFirst(L,P);
        } else {
            Next(Last(L)) = P;
            Prev(P) = Last(L);
            Next(P) = First(L);
            Prev(First(L)) = P;
        }
    }
}
void insertAfter(List &L, address P, address Prec)
{
    if(First(L) == NULL){
        insertFirst(L,P);
    } else if(Prec == Last(L)){
        insertLast(L, P);
    } else {
        address Q = Prec;
        Q = Next(Q);
        Next(P) = Next(Prec);
        Next(Prec) = P;
        Prev(P) = Prec;
        Prev(Q) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    P = First(L);
    First(L) = Next(P);
    Next(P) = NULL;
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
