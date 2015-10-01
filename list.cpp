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
    
}

void insertLast(List &L, address P)
{
  
}
void insertAfter(List &L, address P, address Prec)
{
    
}

void deleteFirst(List &L, address &P)
{
    
}


void deleteLast(List &L, address &P)
{
    
}

void deleteAfter(List &L, address &P, address &Prec)
{
   
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
