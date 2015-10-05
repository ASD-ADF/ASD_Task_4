#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L) //KOMANGWIDYAPUTRA
{
    First(L) = NULL;
}

address alokasi(infotype x) //KOMANGWIDYAPUTRA
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

void insertFirst(List &L, address P) //KOMANGWIDYAPUTRA
{
    Next(P) = First(L);
    First(L) = P;
}

void insertLast(List &L, address P) //KOMANGWIDYAPUTRA
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

void deleteFirst(List &L, address &P) //ANDINIULYA
{
    P = First(L);
    First(L) = Next(P);
    Next(P) = NULL;
}

void deleteLast(List &L, address &P) //ANDINIULYA
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
   if(Prec==NULL) {
        cout<<"Data Kosong"<<endl;
    }
    else if (Prec==First(L)) {
        deleteFirst(L,P);
    }
    else {
     P = Next(Prec);
     Next(Prec) = Next(P);
     Prev(Next(P))=Prec;
     Next(P) = NULL;
     Prev(P) = NULL;
    }
}

void insertID (List &L2, address P) //ANDINIULYA
{

}

void insertName (List &L2, address P) //KOMANGWIDYAPUTRA
{
    
}

address findElm(List L, infotype x) //ANDINIULYA
{
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}

