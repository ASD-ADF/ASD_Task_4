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
    if(First(L) == NULL){
        First(L) = P;
        Last(L) = P;
    }else{
        Next(P) = First(L);
        Prev(First(L)) = P;
        Next(Last(L)) = P;
        Prev(P) = Last(L);
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
        Next(Last(L)) = P;
        Prev(P) = Last(L);
        Next(P) = First(L);
        Prev(First(L)) = P;
    }
}
void insertAfter(List &L, address P, address Prec)
{
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }else if(Prec == Last(L)){
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
    Next(Last(L)) = First(L);
    Prev(First(L)) = Last(L);
    Next(P) = NULL;
    Prev(P) = NULL;

    dealokasi(P);
}

void deleteLast(List &L, address &P)
{
    if(Next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        address Q = Last(L);
        Last(L) = Prev(Q);
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
        Next(Q) = NULL;
        Prev(Q) = NULL;
        dealokasi(P);
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    if(Prec == Last(L)){
        deleteFirst(L, P);
    }else{
        P = Next(Prec);
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        Next(P) = NULL;
        Prev(P) = NULL;
        dealokasi(P);
    }
}

address findElm(List L, infotype x){
    address Q = First(L);

    if(Info(Q).ID == Info(First(L)).ID){

    }else{
        Q = Next(Q);
        while(Q != First(L) and Info(Q).ID != x.ID){
            Q = Next(Q);
        }
    }

    if(Info(Q).ID == x.ID){
        return Q;
    }else{
        return NULL;
    }

}
