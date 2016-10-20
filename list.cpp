#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
        first(L) = Nil;
        last(L) = Nil;

    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    info(P) = x;
    next(P) = Nil;
    prev(P) = Nil;

    //----------------------------------------
    return P;
}

void dealokasi(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
	if (first(L) == Nil && last(L) == Nil)
    {
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = first(L);
        next(last(L)) = P;
        first(L) = P;
        if (next(first(L)) == last(L))
        {
            prev(last(L)) = P;
        }
        first(L) = P;
        next(last(L)) = first(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L) == Nil && last(L) == Nil)
    {
        insertFirst(L,P);
    }
    else
    {
        prev(P) = prev(last(L));
        next(prev(last(L))) = P;
        last(L) = P;
        next(P) = first(L);
        prev(first(L)) = last(L);

    }

    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    //-------------your code here-------------
    if (first(L) != Nil)
    {
        P = first(L);
        while(next(P) != first(L) && info(P).ID != x.ID)
            P = next(P);

        if(info(P).ID == x.ID)
            return P;
        else
            return Nil;
    }
    else
    {
        return Nil;
    }

    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(next(first(L)) != last(L) && first(L) != Nil)
    {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
        next(P) = Nil;
        prev(P) = Nil;
    }
    else
    {
        cout << "KOSONG";
        P = first(L);
        next(P) = Nil;
        prev(P) = Nil;
        first(L) = Nil;
        last(L) = Nil;
    }


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    address Q;
    if (last(L) == first(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        P = last(L);
        Q = prev(P);
        next(Q) = first(L);
        last(L) = Q;
        prev(first(L)) = Q;
    }


    //----------------------------------------
}

void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec == last(L)){
            insertLast(L,P);
       }
    else if (Prec == first(L)){
            insertFirst(L,P);
        }
    else{
        if (next(Prec) == last(L))
            insertLast(L,P);
        else
        {

            prev(next(Prec)) = P;
            next(P) = next(Prec);
            prev(P) = Prec;
            next(Prec) = P;
            next(P) = Nil;
            prev(P) = Nil;
        }
    }

    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
 if (Prec != Nil)
    {
        P = next(Prec);
        if (P == last(L))
        {
            deleteLast(L,P);
            cout << "KOSONG";
        }
        else if (P == first(L))
            deleteFirst(L,P);

    }
    else
    {
        cout << "KOSONG";
        next(Prec) = next(P);
        prev(next(P)) = Prec;
    }

    //----------------------------------------
}
