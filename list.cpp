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

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P=new elmlist;
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
    if(first(L)==NULL){
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    }else{
        next(prev(first(L)))=P;
        prev(P)=prev(first(L));
        prev(first(L))=P;
        next(P)=first(L);
        first(L)=P;

    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if(first(L)==NULL){
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    }else{
        next(prev(first(L)))=P;
        prev(P)=prev(first(L));
        prev(first(L))=P;
        next(P)=first(L);
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P=first(L);
    do{
        if(info(P).ID==x.ID){
            return NULL;
        }
        P=next(P);
    }while(first(L)!=NULL && P!=first(L));
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
    do{
        if(info(P).name==x.name){
            return P;
        }
        P=next(P);
    }while(first(L)!=NULL && P!=first(L));
    //----------------------------------------
    return NULL;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P=first(L);
    address Q=prev(first(L));
    next(Q)=next(P);
    prev(next(P))=Q;
    P=next(P);
    next(P)=NULL;
    Q=NULL;

    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if(first(L)=NULL){
        deleteFirst(L,P);
    }else{
        P=prev(first(L));
        address Q=prev(P);
        next(Q)=first(L);
        prev(first(L))=Q;
        next(P)=NULL;
        Q=NULL;
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
    if(first(L)==NULL){
        insertFirst(L,P);
    }else{
        next(P)=next(Prec);
        prev(P)=Prec;
        prev(next(Prec))=P;
        next(Prec)=P;
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
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
    //----------------------------------------
}

