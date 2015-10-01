#include <iostream>
#include "list.h"
using namespace std;

address allocate (infotype x)
{
    address P;

    P=new element_list;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void deallocate (address &P)
{
    delete P;
}

void create_list (list &L)
{
    first(L)=NULL;
    last(L)=NULL;
}

void insert_after (list &L, address P, address Prec)
{
    prev(P)=Prec;
    next(P)=next(Prec);
    prev(next(Prec))=P;
    next(Prec)=P;
}

void sorting (list &L, int temp1)
{
    address P;
    infotype temp;

    P=first(L);
    for (int i=1; i<=temp1-1; i++)
    {
        P=first(L);
        for (int j=1 ; j<=(temp1-i); j++)
        {
            if (info(P).name > info(next(P)).name)
            {
                temp=info(next(P));
                info(next(P))=info(P);
                info(P)=temp;
                P=next(P);
            }
            else
            {
                P=next(P);
            }

        }
    }
}
