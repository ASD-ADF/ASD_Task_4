#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    L.first=NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P->info.ID=x.ID;
    P->info.name=x.name;
    P->info.location=x.location;
    P->next=NULL;
    P->prev=NULL;

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
    if (L.first==NULL){
        L.first=P;
        P->next=P;
        P->prev=P;
    }else {
        P->next=L.first;
        P->prev=L.first->prev;
        L.first->prev->next=P;
        L.first->prev=P;
        L.first=P;
    }

    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (L.first==NULL){
        L.first=P;
        P->next=P;
        P->prev=P;
    }else {
        P->next=L.first;
        P->prev=L.first->prev;
        L.first->prev->next=P;
        L.first->prev=P;
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
    if(L.first!=NULL){
        P=L.first;
        while(P!=NULL && P->info.ID!=x.ID){
            P=P->next;
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

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    if(L.first!=NULL){
        P=L.first;
        while(P!=NULL && P->info.name!=x.name){
            P=P->next;
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
    if (L.first==L.first->next){
        P=L.first;
        L.first=NULL;
    }else if (L.first!=NULL){
        P=L.first;
        L.first=L.first->next;
        P->prev->next=L.first;
        L.first->prev=P->prev;
        P->next=NULL;
        P->prev=NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
     if (L.first==L.first->next){
        P=L.first;
        L.first=NULL;
    }else if (L.first!=NULL){
        P=L.first->prev;
        P->prev->next=L.first;
        L.first->prev=P->prev;
        P->next=NULL;
        P->prev=NULL;
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
    P->next=Prec->next;
    P->prev=Prec;
    Prec->next->prev=P;
    Prec->next=P;

    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P=Prec->next;
    Prec->next=P->next;
    P->next->prev=Prec;
    P->next=NULL;
    P->prev=NULL;

    //----------------------------------------
}

