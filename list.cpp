#include "list.h"

void createList(List &L)
{
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    L.first = NULL;
    //----------------------------------------
}

address alokasi(infotype x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    Info(P) = x;
    Next(P) = NULL;
    //----------------------------------------
    return P;
}

void dealokasi(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (L.first==NULL)
    {
        L.first = P;
        Next(P) = L.first;
    }
    else
    {
        Next(P) = L.first;
        address Q = L.first;
        while (Next(Q) != L.first)
        {
            Q = Next(Q);
        }
        Next(Q) = P;
        L.first = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (L.first==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        address Q = L.first;
        while (Next(Q) != L.first)
        {
            Q = Next(Q);
        }
        Next(P) = L.first;
        Next(Q) = P;
    }
    //----------------------------------------
}

address findElm(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    //-------------your code here-------------
    P = L.first;
    do
    {
        if (Info(P).ID == x.ID)
        {
            return P;
        }
        else
        {
            P = Next(P);
        }
    }
    while (P != L.first);
    return NULL;
    //----------------------------------------
    //return P;
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (L.first != NULL)
    {
        if (Next(L.first) == L.first)
        {
            P = L.first;
            L.first = NULL;
        }
        else
        {
            P = L.first;
            address Q = L.first;
            while (Next(Q) != L.first)
            {
                Q = Next(Q);
            }
            Next(Q) = Next(L.first);
            L.first = Next(L.first);
        }
        dealokasi(P);
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (L.first == NULL)
    {
        if (Next(L.first)==L.first)
        {
            P = L.first;
            L.first = NULL;
        }
        else
        {
            address Q = L.first;
            while (Next(Next(Q)) != L.first)
            {
                Q = Next(Q);
            }
            P = Next(Q);
            Next(Q) = L.first;
        }
    }
    //----------------------------------------
}

void insertAfter(address Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    Next(P) = Next(Prec);
    Next(Prec) = P;
    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P)
{
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (L.first != NULL) {
        if (Next(L.first)==L.first) {
            P = L.first;
            L.first = NULL;
        } else {
            P = Next(Prec);
            if (Next(Prec) == L.first) {
                L.first = Next(L.first);
            }
            Next(Prec) = Next(P);
            dealokasi(P);
        }
    }
    //----------------------------------------
}

