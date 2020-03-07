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
    info(P).ID = x.ID;
    info(P).location = x.location;
    info(P).name = x.name;
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
    delete(P);
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //------------- YOUR CODE HERE -------------
     if (L.first == NULL) {
        next(P) = P;
        prev(P) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(P) = prev(first(L));
        first(L) -> prev -> next = P;
        first(L) -> prev = P;
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
    if (first(L) == NULL) {
        insertFirst(L, P);
    } else {
        next(P) = first(L);
        prev(P) = L.first -> prev;
        first(L) -> prev -> next = P;
        first(L) -> prev = P;
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
    P = first(L);
    do {
        P = next(P);
    } while (P != first(L) && P -> info.ID != x.ID);
    if (P == first(L) && P -> info.ID != x.ID) {
        return NULL;
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
        P = first(L);
    do {
        P = next(P);
    } while (P != first(L) && P -> info.name != x.name);
    if (P == first(L) && P -> info.name != x.name) {
        return NULL;
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
    if (L.first == NULL) {
        P = first(L));
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        first(L) -> prev = P -> prev;
        prev(P) -> next = first(L);
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
    if (L.first == NULL) {
        deleteFirst(L, P);
    } else {
        P = L.first -> prev;
        P -> prev -> next = L.first;
        L.first -> prev = P -> prev;
        P -> next = NULL;
        P -> prev = NULL;
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
    if (L.first == NULL) {
        insertFirst(L, P);
    } else {
        P -> next = Prec -> next;
        P -> prev = Prec;
        Prec -> next -> prev = P;
        Prec -> next = P;
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
    if (Prec -> next == L.first) {
        deleteFirst(L, P);
    } else {
        P = Prec -> next;
        P -> next -> prev = Prec;
        Prec -> next = P -> next;
        P -> next = NULL;
        P -> prev = NULL;
    }
    //----------------------------------------
}

