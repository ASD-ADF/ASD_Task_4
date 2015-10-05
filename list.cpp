#include "list.h"

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
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
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
        Prev(next(Prec)) = P;
    }
}

void deleteFirst(List &L, address &P)
{
     if(First(L)==NULL) {
        cout<<"DATA TIDAK DITEMUKAN";
    }
    else if (First(L)!=Last(L)) {
    P = First(L);
    First(L) = Next(P);
    Next(P) = NULL;
    Prev(P) = NULL;
        Prev(First(L))=Last(L);
        Next(Last(L))=First(L);
    }
    else{

            P=First(L);
            Next(P)=NULL;
            Prev(P)=NULL;
            First(L)=NULL;
            Last(L)=NULL; 
    }
}

void deleteLast(List &L, address &P)
{
    if(next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else if(First(L)==NULL)
    {
        cout<<"DATA TIDAK DITEMUKAN"<<endl;
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
        cout<<"Data TIDAK DITEMUKAN"<<endl;
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
        do{
            if (Info(Next(Q)).ID > Info(P).ID) {
                break;
            }
            Q=Next(Q);
        } while(Info(P).ID > Info(Q).ID && Next(Q)!= First(L2));
        insertAfter(L2,P,Q);
    }
}

void insertName(List &L2, address P) {
    address Q;
    Q=First(L2);
    if(Q==NULL) {
        insertFirst(L2,P);
    }
     else if(Info(P).name < Info(Q).name) {
        insertFirst(L2,P);
    }
    else {
        while (Info(P).name > Info(Q).name && Next(Q)!= First(L2)) {
            if (Info(Next(Q)).name > Info(P).name) {
                break;
            }
            Q=Next(Q);
        }
        insertAfter(L2,P,Q);
    }

}


address findElm(List L, infotype x){
    address Q = First(L);
    while(next(Q) != First(L)){
        if(Info(Q).ID == x.ID){
            break;
        } Q=next(Q);
    }
        if(Info(Q).ID == x.ID){
            return Q;
        }
        else {
            return NULL;
    }
}
