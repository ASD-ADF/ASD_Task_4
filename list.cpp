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
        Next(P) = First(L);
        Prev(P) = First(L);
        Last(L) = P;
    }
    else
    {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L)) = P;
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
    cout<<"Input Setelah Data ke : ";
    int j,i;
    cin>>j;
    //p = (*l).first;
    Prec = First(L);
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        for (i=1;i<j;i++)
        {
            Prec=Next(Prec);
            break;
        }
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    P = First(L);
    if (P == NULL)
    {
        cout << "Masih Kosong" << endl;
    }
    else if (Next(P) == NULL)
    {
        Next(P) = NULL;
        Prev(P) = NULL;
        dealokasi(P);
    }
    else
    {
        First(L) = Next(P);
        Next(P) = NULL;
        Prev(P) = NULL;
        Prev(First(L)) = Last(L);
        Next(Last(L)) = First(L);
        dealokasi(P);
    }
}


void deleteLast(List &L, address &P)
{
    if((Next(First(L)) == NULL))
    {
        deleteFirst(L,P);
    }
    else
    {
        P = Last(L);
        Last(L) = Prev(Last(L));
        Prev(P) = NULL;
        Next(P) = NULL;
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
        dealokasi(P);
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    cout<<"Hapus Setelah Data ke : ";
    int j,i;
    cin>>j;
    Prec = First(L);
    for (i=1;i<j;i++)
    {
        Prec=Next(Prec);
        break;
    }
    P = Next(Prec);
    Next(Prec) = Next(P);
    Prev(Next(P)) = Prec;
    Next(P) = NULL;
    Prev(P) = NULL;
    dealokasi(P);
}


address findElm(List L, infotype x){
    address Q = First(L);
    if (Q == NULL)
    {
        cout << "Data Kosong!" << endl;
    }
    while (Q != NULL)
    {
        if(Info(Q).name == x.name)
        {
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}
