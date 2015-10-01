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
    P->prev = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
{
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
        P->prev = L.last;
        P->next = L.first;
    }
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
        L.first->prev = L.last;
        L.last->next = L.first;
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
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        L.last->next = L.first;
        L.first->prev = L.last;
    }
}

void insertAfter(List &L, address P, address Prec)
{
    // P tuh Element Baru yang akan diinsert,
    // Sesudah Elemen Prec
    address S = L.first;
    for (int i = 1; i <= countElm(L); i++){
        if (Prec->info.ID == S->info.ID) {
            break;
        }
        S = S->next;
    }
    Prec = S;

    P->next = Prec->next;
    P->prev = Prec;

    P->next->prev = P;
    Prec->next = P;
}

void deleteFirst(List &L, address &P)
{
    if (L.first == NULL) {
        cout << "List Kosong" <<endl;
    }
    else if (L.first->next == NULL) {
        P = L.first;
        P->prev = NULL;
        P->next = NULL;
        L.first = NULL;
        L.last = NULL;
        dealokasi(P);
    }
    else {
        P = L.first;
        L.first = P->next;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->next = NULL;
        P->prev = NULL;
        dealokasi(P);
    }
}

void deleteLast(List &L, address &P)
{
    if(L.first == NULL)
    {
        cout << "List Kosong"<<endl;
    }
    else if (L.first->next == NULL)
    {
        deleteFirst(L,P);
    }
    else {
        P = L.last;
        L.last = P->prev;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->prev = NULL;
        P->next = NULL;
        dealokasi(P);
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    address S = L.first;
    for (int i = 1; i <= countElm(L); i++){
        if (Prec->info.ID == S->info.ID) {
            break;
        }
        S = S->next;
    }
    Prec = S;

    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
    P->prev = NULL;
    dealokasi(P);
}

address findElm(List L, infotype x){
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}

int countElm(List L) {
    int num = 0;
    if (L.first == NULL) return 0;
    address Q = First(L);
    do{
        num++;
        Q = Next(Q);
    }while(Q != L.first);
    return num;
}
