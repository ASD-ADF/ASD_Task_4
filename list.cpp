#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    first(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
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
    if (first(L) == NULL){
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }else {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (first(L) == NULL){
        first(L) = P;
        next(first(L)) = P;
        prev(first(L)) = P;
    }else {
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

    address P = first(L);
    //------------- YOUR CODE HERE -------------
    do{
        if(info(P).ID == x.ID){
            return P;
        }
        P = next(P);
    }while(P != first(L) && first(L) != NULL);
    //----------------------------------------
    return NULL;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = first(L);
    //------------- YOUR CODE HERE -------------
    do {
        if(info(P).name == x.name){
            return P;
        }
        P = next(P);
    }while(P != first(L));
    //----------------------------------------
    return NULL;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if(next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else {
        P = first(L);
        first(L) = next(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if(next(P) == first(L)){
        P = first(L);
        first(L) = NULL;
    }else{
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //------------- YOUR CODE HERE -------------
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P = next(Prec);
    if(next(next(Prec)) == Prec){
        next(P) = NULL;
        prev(P) = NULL;
        next(Prec) = Prec;
        prev(Prec) = Prec;
    }else{
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
    //----------------------------------------
}

void insertAndShort(List &L, infotype x){
    address P,Q ;
    P = first(L) ;
    if ((P == NULL) || (info(P).ID > x.ID))
    {
        insertFirst(L,allocate(x)) ;
    }
    else if (findElmByID(L,x) == NULL)
    {
        while ((P != NULL) && (info(P).ID < x.ID))
        {
            Q = P ;
            P = next(P) ;
        }
        insertAfter(L,Q,allocate(x));
    }
}
