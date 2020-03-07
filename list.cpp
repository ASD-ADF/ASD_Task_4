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
        next(first(L)) = P;
        prev(first(L)) = P;
    }else{
        next(P) = first(L);
        next(prev(first(L))) = P;
        prev(P) = prev(first(L));
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
    if(first(L) == NULL){
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

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    if(first(L) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        P = first(L);
        do{
            if(info(P).ID == x.ID){
                return P;
            }
            P = next(P);
        }while(P != first(L));
        P = NULL;
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
    if(first(L) == NULL){
        cout<<"List Kosong"<<endl;
    }else{
        P = first(L);
        do{
            if(info(P).name == x.name){
                return P;
            }
            P = next(P);
        }while(P != first(L));
        P = NULL;
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
    P = first(L);
    if(first(L) == NULL){
        cout<<" "<<endl;
    }else if(next(first(L) == first(L))){
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }else{
        first(L) = next(P);
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
    P = first(L);
    if(first(L) == NULL){
        cout<<" "<<endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = prev(P);
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
    next(Prec) = next(P);
    prev(Prec) = P;
    prev(next(P)) = Prec;
    next(P) = Prec;
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if(Prec == first(L) && next(Prec) == first(L)){
        first(L) = NULL;
        next(Prec) = NULL;
        prev(Prec) = NULL;
    }else if(next(Prec) == first(L)){
        P = first(L);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        first(L) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
    //----------------------------------------
}

