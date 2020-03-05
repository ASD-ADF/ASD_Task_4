#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    first(L) = NIL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NIL;
    //------------- YOUR CODE HERE -------------
    P = new elmlist;
    info(P) = x;
    next(P) = NIL;
    prev(P) = NIL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //------------- YOUR CODE HERE -------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //------------- YOUR CODE HERE -------------
    if(first(L) == NIL){
       first(L) = P;
       next(P) = P ;
       prev(P) = P ;
    }
    else{
        next(P) = first(L) ;
        prev(P) = prev(first(L)) ;
        next(prev(first(L))) = P ;
        prev(first(L)) = P ;
        first(L) = P ;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if(first(L) == NIL){
        insertFirst(L,P);
    }
    else{
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NIL;
    //------------- YOUR CODE HERE -------------
    P = first(L);
    do{
        P = next(P);
    } while(P!= first(L) && info(P).ID != x.ID);
    if(P == first(L) && info(P).ID != x.ID){
        P = NIL;
    }
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NIL;
    //------------- YOUR CODE HERE -------------
    P = first(L);
    do{
        P = next(P);
    } while(P!= first(L) && info(P).name != x.name);
    if(P == first(L) && info(P).name != x.name){
        P = NIL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P = first(L) ;
    if (next(P) == first(L))
    {
        first(L) = NIL ;
        next(P) = NIL;
        prev(P) = NIL;
    }
    else
    {
        first(L) = next(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NIL;
        prev(P) = NIL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P = prev(first(L));
    next(prev(P)) = first(L);
    prev(first(L)) = prev(P);
    next(P) = NIL;
    prev(P) = NIL;
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NIL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //------------- YOUR CODE HERE -------------
    prev(next(Prec)) = P ;
    next(P) = next(Prec) ;
    next(Prec) = P ;
    prev(P) = Prec ;
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NIL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P = next(Prec) ;
    if (next(Prec) == Prec)
    {
        next(P) = NIL ;
        prev(P) = NIL ;
        next(Prec) = Prec ;
        prev(Prec) = Prec ;
    }
    else
    {
        next(Prec) = next(P) ;
        prev(next(P)) = Prec ;
        next(P) = NIL ;
        prev(P) = NIL ;
    }
    //----------------------------------------
}
