#include "list.h"
/* nim : 1301140057 */

void createList(List &L)
{
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    First(L) = NULL;
    Last(L) = NULL;
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
    Prev(P) = NULL;
    //----------------------------------------
    return P;
}

void dealokasi(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete(P);
    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (First(L) == NULL)
    {
        First(L) = P;
        Last(L) = P;
        Next(P) = P;
        Prev(P) = P;
    }
    else
    {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Prev(First(L)) = P;
        Next(Last(L)) = P;
        First(L) = P;
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

    if (First(L) == NULL)
    {
        First(L) = P;
        Last(L) = P;
        Next(P) = P;
        Prev(P) = P;
    }
    else
    {
        Prev(P) = Last(L);
        Next(P) = First(L);
        Next(Last(L)) = P;
        Prev(First(L)) = P;
        Last(L) = P;
    }
    //----------------------------------------
}

address findElm(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */
    address P;
    P = First(L);
    do
    {
        if (Info(P).name == x.name)
        {
            return P;
        }
        if (Info(P).ID == x.ID)
        {
            return P;
        }
        P = Next(P);
    }
    while (P != First(L));
    return NULL;
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (First(L) != NULL)
    {
        P = First(L);
        if (Next(P) == NULL)
        {
            First(L) = NULL;
            Last(L) = NULL;
        }
        else
        {
            First(L) = Next(P);
            Last(L) = First(L);
            Prev(First(L)) = Last(L);
            Next(P) = NULL;
            Prev(P) = NULL;
        }
    }
    else
    {
        cout << "LIST KOSONG";
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
    address Q;
    if (First(L) != NULL)
    {
        Q = First(L);
        if (Next(Q) == First(L))
        {
            First(L) = NULL;
            Last(L) = NULL;
        }
        else
        {
            while (Next(Next(Q)) != First(L))
            {
                Q = Next(Q);
            }
            P = Next(Q);
            Next(Q) = First(L);
            Prev(First(L)) = Q;
            Last(L) = Q;
            Next(P) = NULL;
            Prev(P) = NULL;
        }
    }
    //----------------------------------------
}

void insertAfter(List &L,address Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    Prev(P) = Prec;
    Next(P) = Next(Prec);
    Prev(Next(Prec)) = P;
    Next(Prec) = P;
    if ((Prec)==Last(L))
    {
        Last(L)=P;
    }
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
    if ((Prec) == Last(L))
    {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        First(L) = Next(P);
        Prev(P) = NULL;
        Next(P) = NULL;
    }
    else if (Next(Prec) == Last(L))
    {
        P = Next(Prec);
        Last(L) = Prec;
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        Prev(P) = NULL;
        Next(P) = NULL;
    }
    else
    {
        P = Next(Prec);
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        Prev(P) = NULL;
        Next(P) = NULL;
    }
    //----------------------------------------
}
