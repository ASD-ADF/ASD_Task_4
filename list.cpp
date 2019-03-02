#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    first(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P;
    //------------- YOUR CODE HERE -------------
    P = new elmlist;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
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
        first(L)=P;
        next(P)=first(L);
        prev(first(L)) = P;
    }else{
        address Q = prev(first(L));
        next(P)=first(L);
        prev(P)=Q;
        prev(first(L))=P;
        next(Q)=P;
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
        insertFirst(L,P);
    }else{
        address Q = prev(first(L));
        next(Q)=P;
        prev(P)=Q;
        next(P)=first(L);
        prev(first(L))=P;
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
    while (P != NULL){
    if (info(P).ID != x.ID){
        P = next(P);
    }else if (info(P).ID == x.ID){
        return P;
    }else{
        return NULL;
    }
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

    address P = first(L);
    //------------- YOUR CODE HERE -------------
    while (P != NULL){
    if (info(P).name != x.name){
        P = next(P);
    }else if (info(P).name == x.name){
        return P;
    }else{
        return NULL;
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
    //------------- YOUR CODE HERE -------------
    if (first(L) != NULL){
        P = first(L);
        address Q = prev(P);
        first(L)=next(P);
        prev(next(P))= Q;
        next(Q)=first(L);
        prev(first(L)) = Q;
        next(P)=NULL;
        prev(P)=NULL;
        //deallocate(P);
    }else{
        first(L)=NULL;
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
    address Q = prev(P);
    next(Q)=first(L);
    prev(first(L))=Q;
    next(P)=NULL;
    prev(P)=NULL;
    //deallocate(P);
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
            P - x Prec
    */
    //------------- YOUR CODE HERE -------------
    if (first(L) == NULL){
        insertFirst(L,P);
    }else{
    next(P) = Prec;
    prev(Prec) = P;
    next(Prec)=next(P);
    prev(next(P))=Prec;
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (first(L) == NULL){
        deleteFirst(L,P);
    }else{
        Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P) = NULL;
    }
    //----------------------------------------
}

