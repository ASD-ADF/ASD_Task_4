#include <iostream>
#include "list.h"


using namespace std;


void createList(List &L)
{
    First(L) = NULL;
    Last(L)=NULL;
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
    if(First(L)==NULL)
    {
        First(L)=P;
        Next(First(L))=NULL;
        Last(L)=P;
        Prev(P)=Last(L);
        Next(P)=First(L);
    }
    else
    {
        Next(P) = First(L);
        Prev(First(L))=P;
        First(L) = P;
        Prev(First(L))=Last(L);
        Next(Last(L))=First(L);
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

        Next(Last(L))=P;
        Prev(P)=Last(L);
        Last(L)=P;
        Next(Last(L))=First(L);
        Prev(First(L))=Last(L);
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
        address Q = L.first;
        for (int i = 1; i <= countElm(L); i++)
        {
            if (Info(Prec).ID == Info(Q).ID)
            {
                break;
            }
            Q = Next(Q);
        }
        Prec = Q;
        Next(P) = Next(Prec);
        Prev(P)=Prec;
        Prev(Next(Prec))=P;
        Next(Prec) = P;
    }
}
void deleteFirst(List &L, address &P)
{
    if(First(L)==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else
    {
        P = First(L);
        First(L) = Next(P);
        Next(P) = NULL;
        Prev(P)=NULL;
        Next(P)=NULL;
    }
}


void deleteLast(List &L, address &P)
{
    if(First(L)==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else if(Next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        P = Last(L);
        Last(L)=Prev(P);
        Next(Last(L))=First(L);
        Prev(First(L))=Last(L);
        Prev(P)=NULL;
        Next(Last(L))=NULL;
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    address Q = First(L);
    for (int i = 1; i <= countElm(L); i++){
        if (Info(Prec).ID == Info(Q).ID) {
            break;
        }
        Q = Q->next;
    }
    Prec = Q;
    P=Next(Prec);
    Next(Prec) = Next(P);
    Prev(P)=NULL;
    Next(P) = NULL;
}


address findElm(List L, infotype x)
{
    address Q = First(L);
    while(Q != NULL)
    {
        if(Info(Q).name == x.name)
        {
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}
int countElm(List L)
{
    int num = 0;
    if (L.first == NULL) return 0;
    address Q = First(L);
    do
    {
        num++;
        Q = Next(Q);
    }
    while(Q != L.first);
    return num;
}
