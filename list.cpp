#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    L.first=NULL;
    L.last=NULL;
    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P=new elmlist;
    P->info=x;
    P->next=NULL;
    P->prev=NULL;
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
    if (First(L) == NULL && Last(L) == NULL)
    {
        First(L) = P;
        Last(L) = P;
        Next(P) = P;
        Prev(P) = P;
    }
    else
    {
        P->next = L.first;
        P->prev = L.last;
        L.last->next = L.first;
        L.last->next = P;
        L.first = P;
        if (L.first->next == L.last)
        {
            L.last->prev = P;
        }
        L.first = P;
        L.last->next = L.first;
}

    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (First(L) == NULL && Last(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {

        P->prev = L.last->prev;
        (L.last->prev)->next = P;
        L.last = P;
        P->next = L.first;
        L.first->prev = L.last;

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
    if (L.first != NULL)
    {
        P = L.first;
        while(P->next != L.first && P->info.ID != x.ID)
            P = P->next;

        if (P->info.ID == x.ID)
            return P;
        else
            return NULL;
    }
    else
    {
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
    //-------------your code here-------------
    if (L.first->next != L.last && L.first != NULL)
    {
        P = L.first;
        L.first = P->next;
        L.first->prev = L.last;
        L.last->next = L.first;
        P->next = NULL;
        P->prev = NULL;

    }
    else
    {
        cout << "Hai";
        P = L.first;
        P->next = NULL;
        P->prev = NULL;
        L.first = NULL;
        L.last = NULL;
}


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    address Q;
    if (L.last == L.first)
    {
        deleteFirst(L,P);
    }
    else
    {
        P = L.last;
        Q = P->prev;
        Q->next = L.first;
        Last(L) = Q;
        L.first->prev = Q;
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
    if (Prec == L.last)
        insertLast(L,P);
    else if (Prec == L.first)
        insertFirst(L,P);
    else
    {
        if (Prec->next == L.last)
            insertLast(L,P);
        else
        {

            Prec->next->prev = P;
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next = P;
            P->next = NULL;
            P->prev = NULL;
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
    if (Prec != NULL)
    {
        P = Prec->next;
        if (P == L.last)
        {
            deleteLast(L,P);
            cout << "Haloo";
        }
        else if (P == L.first)
            deleteFirst(L,P);

    }
    else
    {
        cout << "Halooow";
        Prec->next = P->next;
        (P->next)->prev= Prec;
}

    //----------------------------------------
}

int countElm(List L) {
    int num = 0;
    if (L.first == NULL) return 0;
    address Q = First(L);
    do{
        num++;
        Q = Next(Q);
    }while(Q != L.first);
    return num;
}
