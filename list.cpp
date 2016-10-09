#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    first(L)= Nil;
    last(L)=Nil;
    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    info(P).ID = x.ID;
    info(P).location = x.location;
    info(P).name = x.name;
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
    next(P) = Nil;
    prev(P) = Nil;
    if (first(L)==Nil) {
        first(L) = P;
        last(L) = P;
        next(P) = first(L);
        prev(P) = last(L);
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;

        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    next(P) = Nil;
    prev(P) = Nil;
    if (first(L)==Nil) {
        first(L) = P;
        last(L) = P;
        next(P) = first(L);
        prev(P) = last(L);
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;

        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }

    //----------------------------------------
}

address findElm(List L, string x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    //-------------your code here-------------
    if (first(L)!=Nil) {
        P = first(L);
        do {
            if (info(P).name!=x) {
                P = next(P);
            }
        }while ((info(P).name!=x) && (P != first(L)));
        if (info(P).name!=x) {
            P = Nil;
        }
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
    if (first(L)!=Nil)  {
        if (first(L)==last(L)) {
            P = first(L);
            first(L) = Nil;
            last(L) = Nil;
        } else{
            P = first(L);
            first(L) = next(P);
            next(P) = Nil;
            prev(P) = Nil;

            next(last(L)) = first(L);
            prev(first(L)) = last(L);
        }
    }


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L)!=Nil){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = Nil;
            last(L) = Nil ;
        } else  {
            P =last(L);
            last(L) =prev(P);
            next(P) = Nil;
            prev(P) = Nil;

            next(last(L)) = first(L);
            prev(first(L)) = last(L);
        }
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
    if (first(L) != Nil){
        if (Prec==last(L)){
            insertLast(L,P);
        } else {
            prev(P) = Prec;
            next(P) = next(Prec);
            next(Prec) = P;
            prev(next(P)) = P;
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
    if(first(L)!=Nil){
        if (Prec == last(L)){
            deleteFirst(L,next(Prec));
        } else {
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = prev(P);

            next(P) = Nil;
            prev(P) = Nil;
        }
    }

    //----------------------------------------
}

