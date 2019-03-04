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
    P= new elmlist;
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
        if (first(L) == NULL)
    {
        first(L) = P;
        next(first(L)) = P;
        prev(first(L)) = P;
    }
    else if (next(first(L)) == NULL)
    {
        next(P) = first(L);
        next(first(L)) = P;
        prev(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
    else
    {

        P= prev(first(L));
        next(prev(first(L)))=P;
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
    P= prev(first(L));
    next(prev(first(L)))=P;
    prev(first(L))=P;
    next(P)=first(L);

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
    if (first(L)!=NULL)
    {
        P=first(L);
        if (x.ID != info(P).ID)
        {
            P = next(P);
        }
        while (x.ID != info(P).ID && P != first(L))
        {
            P = next(P);
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
    if (first(L)!=NULL)
    {
        P=first(L);
        if (x.name != info(P).name)
        {
            P = next(P);
        }
        while (x.name != info(P).name && P != first(L))
        {
            P = next(P);
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
    P= (first(L));
    next(prev(P))=next(P);
    prev(next(P))=prev(P);
    first(L)=next(P);
    next(P)=NULL;
    prev(P)=NULL;

    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    first(L)=next(first(L));
    P= (first(L));
    next(prev(P))=next(P);
    prev(next(P))=prev(P);
    next(P)=NULL;
    prev(P)=NULL;

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
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
    //----------------------------------------
}

