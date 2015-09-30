#include <iostream>
#include "list.h"
#include "player.h"

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
        cout << "Kesini" << endl;
        First(L) = P;
        Last(L) = P;
        Next(P) = First(L);
        Prev(P) = Last(L);
        cout << "Kelar" << endl;
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
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        address Q = First(L);
        while(Next(Q) != First(L))
        {
            Q = Next(Q);
        }
        Next(P) = First(L);
        Prev(P) = Q;
        Next(Q) = P;
        Last(L) = P;
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
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    P = First(L);
    First(L) = Next(P);
    Next(P) = NULL;
}

void deleteLast(List &L, address &P)
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
        delete P;
    }
    else cout << "Cuma 1" << endl;
}

void sortList(List &L, int condition) {
    switch(condition) {
        case 1: { // Sort BY ID
            sortByID(L);
        }
        case 2: { // Sort BY NAME
            sortByName(L);
        }
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
        if(Info(Q).name == x.name)
            return Q;

        Q = Next(Q);
    } while(Q != First(L));
    return NULL;
}
