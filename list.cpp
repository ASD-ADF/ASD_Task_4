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
    Prev(P) = NULL;
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
        Next(First(L)) = P;
        Prev(First(L)) = P;
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

void deleteLast(List &L, address &P)
{
    if(Last(L) == NULL)
    {
        cout << "Data Kosong" <<endl;
    }
    else if (Last(L) == First(L))
    {
        P = Last(L);
        Next(P) = NULL;
        Prev(P) = NULL;
        First(L) = NULL;
        Last(L) = NULL;
    }
    else
    {
        P = Last(L);
        Last(L) = Prev(P);
        Prev(First(L)) = Last(L);
        Next(Last(L)) = First(L);
        Next(P) = NULL;
        Prev(P) = NULL;
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    if (Prec == NULL)
    {
        cout << "Data Kosong" << endl;
    }
    else if (Prec == First(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        P = Next(Prec);
        Next(Prec) = Next(P);

    }
}

address findElm(List L, infotype x)
{
    address Q = First(L);
    while(Q != NULL)
    {
        if(Info(Q).ID == x.ID)
        {
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}
