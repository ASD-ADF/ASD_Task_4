#include "list.h"

void createList(List &L)
{
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address allocate(infotype x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    delete P;
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
        prev(P) = first(L);
    }
    else if (next(first(L)) == first(L)){
        next(P) = first(L);
        prev(P) = first(L);
        next(first(L)) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
    else{
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(first(L)) = P;
        prev(first(L)) = P;
        first(L) = P;
    }

}


void insertLast(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    if ((first(L)) == NULL)
    {
        insertFirst(L, P);
    }
    else if (next(first(L)) == first(L)){
        prev(P) = first(L);
        next(first(L)) = P;
        next(P) = first(L);
        prev(first(L)) = P;
    }
    else{
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        next(P) = first(L);
        prev(first(L)) = P;
    }
}


address findElmByID(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = first(L);
    if (first(L) != NULL)
    {
        while ((next(P) != first(L)) && (info(P).ID != x.ID))
        {
            P = next(P);
        }
        if (info(P).ID == x.ID)
        {
            return P;
        }
    }
    return NULL;
}

address findElmByName(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = first(L);
    if (first(L) != NULL)
    {
        while ((next(P) != first(L)) && (info(P).name != x.name))
        {
            P = next(P);
        }
        if (info(P).name == x.name)
        {
            return P;
        }
    }
    return NULL;
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if (first(L) == NULL)
    {
        cout<<"empty list \n";
    }
    else
    {
        if (next(first(L)) == NULL)
        {
            next(first(L)) = NULL;
            prev(first(L)) = NULL;
        }
        else
        {
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
            prev(P) = NULL;
            prev(first(L)) = prev(first(L));
            next(prev(first(L))) = first(L);
        }
    }
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    P = first(L);
    if (P == NULL)
    {
        cout<<"empty list \n";
    }
    else
    {
        if (next(first(L) == first(L)))
        {
            next(first(L)) = NULL;
            prev(first(L)) = NULL;
        }
        else
        {
            address Q = prev(first(L));
            next(Q) = NULL;
            prev(Q) = NULL;
            next(prev(first(L))) = first(L);
            prev(first(L)) = prev(first(L));
        }
    }
}

void insertAfter(List &L, address &Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    if (first(L) == NULL)
    {
        cout<<"empty list \n";
    }
    else
    {
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void deleteAfter(List &L, address &Prec, address &P)
{
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    if (first(L) == NULL)
    {
        cout<<"empty list \n";
    }
    else
    {
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

