#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    L.First = NULL;
    L.Last = NULL;
    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P = new elmlist;
    //-------------your code here-------------
    P->Info.ID = x.ID;
    P->Info.location = x.location;
    P->Info.name = x.name;
    P->Next = NULL;
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
	if (L.First == NULL){
        L.First = P;
        L.Last = P;
	}
	else{
        address Q;
        Q = L.First;
        Q->Prev= P;
        P->Next = Q;
        L.First = P;
	}
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (L.First == NULL){
        L.First = P;
        L.Last = P;
    }
    else{
        address Q;
        Q = L.Last;
        Q->Next = P;
        P->Prev = Q;
        L.Last = P;
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
    if (L.First != NULL){
        P = L.First;
        while(P->Next != L.First && P->Info.ID != x.ID)
            P = P->Next;

        if (P->Info.ID == x.ID){
            return P;
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
    //----------------------------------------
}

void deleteFirst(List &L, address &P){
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P = L.First;
    L.First = P->Next;
    P->Next = NULL;
    P->Prev = NULL;
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P = L.Last;
    L.Last = P->Prev;
    P->Prev = NULL;
    P->Next = NULL;
    //----------------------------------------
}

void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec == L.First){
        insertFirst(L,P);
    }
    else if(Prec = L.Last){
        insertLast(L,P);
    }
    else{
        Prev(Next(Prec)) = P;
        P->Prev = Prec;
        P->Next = Prec->Next;
        Prec->Next = P;
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
    P = Prec->Next;
    if (P = L.Last){
        deleteLast(L,P);
    }else if ( P = L.First){
        deleteFirst(L,P);
    }
    else{
        Prec->Next = P->Next;
        Prev(Next(P)) = Prec;
    }
    //----------------------------------------
}

