#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = Nil;
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    P = new ElmList;
    info(P) = x;
    next(P) = Nil;
    return P;
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
    if (first(L) == Nil)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        while (next(Q) != first(L))
        {
            Q = Q->next;
        }
        next(P) = first(L);
        Q->next = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    address Q;
    if (first(L) == Nil)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (Q->next != first(L))
        {
            Q = Q->next;
        }
        next(P) = first(L);
        Q->next = P;
    }
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */
    address Q;
    if (first(L) == Nil)
    {
        first(L) = P;
        next(P) = first(L);
    }
    else
    {
        Q = first(L);
        while (Q->next != first(L))
        {
            Q = Q->next;
        }
        next(P) = first(L);
        Q->next = P;
    }
    return P;
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
        P = first(L);
        next(P) = Nil;
        first(L) = Nil;
    }
    else
    {
        while (next(Q)!=first(L))
        {
            Q = next(Q);
        }
        next(Q)=next(P);
        first(L)=next(P);
        next(P)=Nil;
    }
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    address Q = first(L);
    if (next(first(L)) == Nil)
    {
        P = first(L);
        next(P) = Nil;
        first(L) = Nil;
    }
    else
    {
        while (next(next(Q))!=first(L))
        {
            Q=next(Q);
        }

        next(Q) = first(L);
        next(P) = Nil;

    }
}

void insertAfter(address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    next(P) = next(Prec);
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
        P=first(L);
        first(L)=next(P);
        next(Prec)=first(L);
        P=Nil;
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = Nil;
    }
}

