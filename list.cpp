#include <iostream>
#include "DoubleCircularH.h"

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
        Prev(Next(P))=Prec;
        Next(P)=NULL;
        Prev(P)=NULL;
    }
}

address findElm(List L, infotype x)
{
    address P = First(L);
    while (Next(P)!=First(L))
    {
        if(Info(P).ID==x.ID)
        {
            break;
        }
        P=Next(P);
    }
    if (Info(P).ID==x.ID)
    {
        return P;
    }
    else
    {
        return NULL;
    }

}

address findElm2(List L, infotype x)
{
    address P = First(L);
    while (Next(P)!=First(L))
    {
        if(Info(P).name==x.name)
        {
            break;
        }
        P=Next(P);
    }
    if (Info(P).name==x.name)
    {
        return P;
    }
    else
    {
        return NULL;
    }
};

void insertID (List &l2, address p )
{
    address q=First(l2);
    if (q==NULL)
    {
        insertFirst(l2,p);
    }
    else if(Info(p).ID < Info(q).ID)
    {
        insertFirst(l2,p);
    }
    else
    {
        while (Info(p).ID > Info(q).ID && Next(q)!=First(l2))
        {
            if (Info(Next(q)).ID > Info(p).ID)
            {
                break;
            }
            q=Next(q);
        }
        insertAfter(l2,p,q);
    }
};

void insertNAMA (List &l2, address p )
{
     address q=First(l2);
    if (q==NULL)
    {
        insertFirst(l2,p);
    }
    else if(Info(p).name < Info(q).name)
    {
        insertFirst(l2,p);
    }
    else
    {
        while (Info(p).name > Info(q).name && Next(q)!=First(l2))
        {
            if (Info(Next(q)).name > Info(p).name)
            {
                break;
            }
            q=Next(q);
        }
        insertAfter(l2,p,q);
    }
};
