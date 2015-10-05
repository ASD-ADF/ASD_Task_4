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
    if (First(L)==NULL)
    {
        First(L)=P;
        Next(P)=First(L);
        Prev(P)=First(L);
        Last(L)=P;
    }
    else
    {
        Next(P)=First(L);
        Prev(P)=Last(L);
        Next(Last(L))=P;
        Prev(First(L))=P;
        First(L)=P;
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
        Next(P)=First(L);
        Prev(P)=Last(L);
        Next(Last(L))=P;
        Prev(First(L))=P;
        Last(L)=P;
    }
}

void insertAfter(List &L, address P, address Prec)
{
    if(Last(L)==Prec)
    {
        insertFirst(L,P);
    }
    else
    {
        Next(P) = Next(Prec);
        Prev(P)=Prec;
        Prev(Next(Prec)) = P;
        Next(Prec)=P;
    }
}

void deleteFirst(List &L, address &P)
{
    if (First(L)==NULL)
    {
        cout << "Data Tidak ada. . . \n";
    }
    else if (First(L)==(Last(L)))
    {
        P=First(L);
        Next(P)=NULL;
        Prev(P)=NULL;
        First(L)=NULL;
        Last(L)=NULL;
    }
    else
    {
        P = First(L);
        First(L) = Next(P);
        Next(P) = NULL;
        Prev(P) = NULL;
        Prev(First(L))=Last(L);
        Next(Last(L))=First(L);
    }

}

void deleteLast(List &L, address &P)
{
    if (First(L)==NULL)
    {
        cout << "Data Tidak Ada. . . \n";
    }
    else if(First(L) == Last(L))
    {
        P=Last(L);
        Next(P)=NULL;
        Prev(P)=NULL;
        First(L)=NULL;
        Last(L)=NULL;
    }
    else
    {
        P=Last(L);
        Last(L)=Prev(Last(L));
        Prev(P)=NULL;
        Next(P)=NULL;
        Prev(First(L))=Last(L);
        Next(Last(L))=First(L);
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    if (Prec==NULL)
    {
        cout << "Data Tidak Ada. . . \n";
    }
    else if (Prec==First(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        Prev(P)=NULL;
        Next(P)=NULL;
    }
}

address findElm(List L, infotype x){
   address Q = First(L);
    while(Next(Q) != First(L))
    {
        if(Info(Q).name == x.name)
        {
            return Q;
        }
        Q = Next(Q);
    }
    if (Info(Q).name == x.name)
    {
        return Q;
    }
    else
    {
        return NULL;
    }
}
