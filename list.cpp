#include <iostream>
#include "list.h"
#include "player.h"

//single link list ubah ke double circular link list

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
    if(First(L) == NULL) {
        First(L) = P;
        Last(L) = P;
        Next(P) = First(L);
        Prev(P) = Last(L);
    }
    else {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Prev(Next(P)) = P;
        First(L) = P;
        Next(Last(L)) = First(L);
    }
}

void insertLast(List &L, address P)
{
    if ((L).first==NULL)
    {
        insertFirst(L, P);
    }
    else
    {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P;
        last(L)=P;
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
        Prev(P) = Prec;
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    P = First(L);
    if (P == NULL)
    {
        cout<<"Data NULL" << endl;
    }
    else
    {
        if (First(L) == Last(L))
        {
            First(L) = NULL;
            Prev(P) = NULL;
            Next(P) = NULL;
            Last(L) = NULL;
        }
        else
        {
            Prev(Next(P)) = Prev(P);
            Next(Prev(P)) = Next(P);
            First(L) = Next(P);
        }
    }
}

void deleteLast(List &L, address &P)
{
    if(First(L) == Last(L) && First(L) != NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        address Q;
        P = Last(L);
        Q = Prev(P);
        Next(Q) = First(L);
        Prev(First(L)) = Q;
        Last(L) = Q;
    }
}

void clearList(List &L) {
    if(First(L) != NULL && Last(L) != NULL) {
        address cur = First(L);
        address tmp;
        Next(Last(L)) = NULL;
        while(Next(cur) != NULL) {
            tmp = Next(cur);
            delete cur;
            cur = tmp;
        }
        First(L) = NULL;
        Last(L) = NULL;
        delete cur;
    }
}

void deleteAfter(List &L, address &P, address &Prec)
{
    if(First(L) != Last(L)) {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Prev(Next(Prec)) = Prec;
        if(P == First(L)) First(L) = Next(First(L));
        if(P == Last(L)) Last(L) = Prev(Last(L));
        Next(P) = NULL;
        Prev(P) = NULL;
    }
    else {
        First(L) = NULL;
        Last(L) = NULL;
        Next(P) = NULL;
        Prev(P) = NULL;
    }
}

void sortByName(List &L) {
    if(First(L) != Last(L)) {
        bool swapped = true;
        address tmp;
        while(swapped) {
            swapped = false;
            address cur = Next(First(L));
            while(Next(cur) != Next(First(L))) {
                if(Info(Prev(cur)).name > Info(cur).name) {
                    swap(Info(Prev(cur)), Info(cur));
                    swapped = true;
                }
                cur = Next(cur);
            }
        }
    }
}

void sortByID(List &L) {
    if(First(L) != Last(L)) {
        bool swapped = true;
        address tmp;
        while(swapped) {
            swapped = false;
            address cur = Next(First(L));
            while(Next(cur) != Next(First(L))) {
                if(Info(Prev(cur)).ID > Info(cur).ID) {
                    swap(Info(Prev(cur)), Info(cur));
                    swapped = true;
                }
                cur = Next(cur);
            }
        }
    }
}

int countNodes(List L) {
    if(First(L) == Last(L) && First(L) != NULL)
        return 1;
    else {
        int total = 0;
        address cur = First(L);
        do {
            if(!Info(cur).name.empty()) total++;
            cur = Next(cur);
        } while(cur != First(L));
        return total;
    }
    return 0;
}

address findElm(List L, infotype x){
    address Q = First(L);
    do {
        if(Info(Q).ID == x.ID)
            return Q;

        Q = Next(Q);
    } while(Q != First(L));
    return NULL;
}

address findElm(List L, string x){
    address Q = First(L);
    do {
        if(Info(Q).name == x)
            return Q;

        Q = Next(Q);
    } while(Q != First(L));
    return NULL;
}

