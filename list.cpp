#include <iostream>
#include "list.h"
#include "player.h"

//single link list ubah ke double circular link list

using namespace std;

void createList(List &L)
{
<<<<<<< HEAD
    (*L).first=NULL;
    (*L).last=NULL;
=======
    First(L) = NULL;
    Last(L) = NULL;
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
}

address alokasi(infotype x)
{
<<<<<<< HEAD
    address P=new elmlist;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
=======
    address P = new elemenList;
    Info(P) = x;
    Next(P) = NULL;
    Prev(P) = NULL;
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

<<<<<<< HEAD
void insertFirst(list &L, address P)
=======
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
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
{
    infotype x;
    if ((L).first==NULL)
    {
        L.first=P;
        next(P)=L.first;
        prev(P)=L.first;
        L.last=P;
    }
    else
    {
<<<<<<< HEAD
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        prev(first(L))=P
        first(L)=P;
    }
}

void insertLast(list &L, address P)
=======
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
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
{
    infotype x;
    if((L).first == NULL)
    {
        insertFirst(L,P)
    }
    else
    {
        next(P)=L.first;
        prev(P)=L.last;
        next(last(L))=P;
        prev(first(L))=P;
        last(L)=P;
    }
}

void insertAfter(List &L, address P, address Prec)
{

}

void deleteFirst(List &L, address &P)
{
<<<<<<< HEAD
     void deleteFirst(List &L, address &P)
 {
     P = First(L);
    First(L) = Next(P);
    Next(P) = NULL;
=======
    P = First(L);
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
    if (P == NULL)
    {
        cout<<"Data NULL\n";
    }
    else
    {
        if (First(L) == Last(L))
        {
            First(L) = NULL;
            Last(L) = NULL;
        }
        else
        {
            First(L) = Next(P);
            Next(P) = NULL;
            Prev(First(L)) = NULL;
        }
        dealokasi(P);
    }
<<<<<<< HEAD
 }
=======
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
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

<<<<<<< HEAD
=======
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

>>>>>>> fcc968103c85a503525044154016c90cd42284ea
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
<<<<<<< HEAD
=======
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
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
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
