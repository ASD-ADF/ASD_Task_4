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

//procedure insert first by M. Ricky J
void insertFirst(List &L, address P){
    if (First(L) == NULL){
        First(L) = P;
        Next(P) = First(L);
        Prev(P) = First(L);
        Last(L) = First(L);
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

//procedure Insert last by M. Ricky J
void insertLast(List &L, address P){
    if (First(L) == NULL){
        First(L) = P;
        Next(P) = First(L);
        Prev(P) = First(L);
        Last(L) = First(L);
    }
    else{
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L)) = P;
        Prev(First(L)) = P;
        Last(L) = P;
    }
}

//Procedure Insert after by M. Ricky J
void insertAfter(List &L, address P, address Prec){
    if (First(L) == NULL){
        insertFirst(L,P);
    }
    else if (Last(L) == Prec){
        Next(P) = First(L);
        Next(Prec) = P;
        Prev(P) = Prec;
        Prev(First(L)) = P;
        Last(L) = P;
    }
    else{
        Next(P) = Next(Prec);
        Next(Prec) = P;
        Prev(Next(P)) = P;
        Prev(P) = Prec;
    }
}

//Procedure DeleteFirst by Rizky Fadhillah
void deleteFirst(List &L, address &P)
{
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

//Procedure DeleteLast by Rizky Fadhillah
void deleteLast(List &L, address &P)
{
    if(First(L)==NULL)
    {
        cout<<"Data Kosong"<<endl;
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

//Procedure DeleteAfter by Rizky Fadhillah
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

address findElm(List L, infotype x){
    address Q = First(L);
    while(next(Q) != first(L)){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}
