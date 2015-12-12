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
    if(First(L)==NULL) {
        First(L)=P;
        Next(P)=First(L);
        Prev(P)=First(L);
        Last(L)=P;
    }
    else {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L))=P;
        Prev(Last(L)) = P;
        First(L) = P;
    }
}

void insertLast(List &L, address P)
{
    if(First(L)==NULL){
        insertFirst(L,P);
    }
    else {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L))=P;
        Prev(Last(L)) = P;
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

void deleteFirst(List &L, address &P){
    if(First(L)==NULL) {
        cout<<"Data Kosong";
    }
    else if (First(L)==Last(L)) {
            P=First(L);
            Next(P)=NULL;
            Prev(P)=NULL;
            First(L)=NULL;
            Last(L)=NULL;
    }
    else{
        P = First(L);
        First(L) = Next(P);
        Next(P) = NULL;
        Prev(P) = NULL;
        Prev(First(L))=Last(L);
        Next(Last(L))=First(L);
    }

}

void deleteLast(List &L, address &P){
    if(First(L)==NULL)
    {
        cout<<" Empty Data "<<endl;
    }
    else if(First(L)==Last(L)) {
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
   if(Prec==NULL) {
        cout<<" Empty Data "<<endl;
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

void insertID (List &L2, address P) {
    address Q=First(L2);
    if (Q==NULL) {
        insertFirst(L2,P);
    }
    else if(Info(P).ID < Info(Q).ID) {
        insertFirst(L2,P);
    }
    else {
        while (Info(P).ID > Info(Q).ID && Next(Q)!= First(L2)) {
            if (Info(Next(Q)).ID > Info(P).ID) {
                break;
            }
            Q=Next(Q);
        }
        insertAfter(L2,P,Q);
    }
}

void insertName (List &L2, address P)
{
    address Q;
    Q=First(L2);
    if(Q==NULL) {
        insertFirst(L2,P);
    }
     else if(Info(P).Name < Info(Q).Name) {
        insertFirst(L2,P);
    }
    else {
        while (Info(P).Name > Info(Q).Name && Next(Q)!= First(L2)) {
            if (Info(Next(Q)).Name > Info(P).Name) {
                break;
}

address findElm(List L, infotype x) {
    address P = First(L);
    while(Next(P) != First(L)){
        if(Info(P).Name == x.Name){
            break;
        }
        P = Next(P);
    }
    if(Info(P).Name==x.Name) {
        return P;
    }
    else {
        return NULL;
    }

}
