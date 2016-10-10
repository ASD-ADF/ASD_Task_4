#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    First(L) = Nil;
    Last(L) = Nil;
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    P = new ElmList;
    Info(P) = x;
    Next(P) = Nil;
    Prev(P) = Nil;
    return P;
    
}

void dealokasi(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    delete(P);
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    address Q;
    if (First(L) == Nil)
    {
        First(L) = P;
        Next(P) = P;
        Last(L) = P;
        Prev(P) = P;
    }
    else
    {
        Next(P) = First(L);
        Prev(First(L)) = P;
        Next(Last(L)) = P;
        Prev(P) = Last(L);
        First(L) = P;
    }
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    address Q;
    if (First(L) == Nil)
    {
        First(L) = P;
        Next(P) = P;
        Last(L) = P;
        Prev(P) = P;
    }
    else
    {
        Prev(P) = Last(L);
        Next(last(L)) = P;
        (Next(L)) = P;
        Next(P) = First(L);
        Last(L) = P;
    }
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */
    do
    {
        if (Info(P).name == x.name)
        {
            return P;
        }
        if (Info(P).ID == x.ID)
        {
            return P;
        }
        P = Next(P);
    }
    while (P != First(L));

    return NULL;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    address Q = first(L);
    P = first(L);
    if (next(P) == first(L))
    {
        last(L) = Nil;
        first(L) = Nil;
    }
    else
    {
        First(L) = Next(P);
        Last(L) = First(L);
        Prev(First(L)) = Last(L);
        Next(P) = NULL;
        Prev(P) = NULL;
    }
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    address Q = First(L);
    P = First(L);
    if (Next(First(L)) == Nil)
    {
        Last(L) = Nil;
        First(L) = Nil;
    }
    else
    {
        while (next(next(Q))!=first(L))
        {
            Q=next(Q);
        }
    
        next(Q) = first(L);
        prev(first(L)) = Q;
        last(L0 = Q;
        next(P) = Nil;
        prev(P) = Nil;
    }
}

void insertAfter(address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    prev(P) = Prec;
    next(P) = next(Prec);
    prev(next(P)) = Prec;
    next(Prec) = P;

}
void deleteAfter(address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    if (next(Prec)==first(L))
    {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        First(L) = Next(P);
        Prev(P) = NULL;
        Next(P) = NULL;
    }
    else
    {
        P = Next(Prec);
        Last(L) = Prec;
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        Prev(P) = NULL;
        Next(P) = NULL;
    }
}

