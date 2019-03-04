#include "list.h"

void createList(List &L)
{
    /**
    * FS : first(L) diset Nil
    */
    //------------- YOUR CODE HERE -------------
    L.first = NULL;
    //----------------------------------------
}

address allocate(infotype x)
{
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //------------- YOUR CODE HERE -------------
    P = new elmlist;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P)
{
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //------------- YOUR CODE HERE -------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (L.first != NULL)
    {
        P->next = L.first;
        P->prev = (L.first)->prev;
        (P->prev)->next = P;
        (L.first)->prev = P;
        L.first = P;
    }
    else
    {
        L.first = P;
        P->next = L.first;
        P->prev = L.first;
    }
    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //------------- YOUR CODE HERE -------------
    if (L.first == NULL)
    {
        L.first = P;
        P->next = P;
        P->prev = P;
    }
    else
    {
        address Prec = (L.first)->prev;
        P->next = L.first;
        P->prev = Prec;
        Prec->next = P;
        (L.first)->prev = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = L.first;
    //------------- YOUR CODE HERE -------------
    while (P!=NULL)
    {
        if (P->info.ID == x.ID)
        {
            return P;
        }
        else
        {
            P->next = P;
        }
    }
    //----------------------------------------
    return NULL;
}

address findElmByName(List L, infotype x)
{
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = L.first;
    //------------- YOUR CODE HERE -------------
    while (P!=NULL)
    {
        if (P->info.name == x.name)
        {
            return P;
        }
        else
        {
            P->next = P;
        }
    }
    //----------------------------------------
    return NULL;
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (L.first != (L.first)->prev)
    {
        L.first = (L.first)->next;
        address Q = (L.first)->prev;
        (L.first)->prev = Q->prev;
        (Q->prev)->next = L.first;
        Q->next = NULL;
        Q->prev = NULL;
    }
    else
    {
        L.first = NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    if (((L.first)->next) == L.first)
    {
        L.first = NULL;
        P->next = NULL;
        P->prev = NULL;
    }
    else
    {
        P = L.first->prev;
        L.first->prev = P->prev;
        (P->prev)->next = L.first;
        P->next = NULL;
        P->prev = NULL;
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P)
{
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //------------- YOUR CODE HERE -------------
    P->next = Prec->next;
    P->prev = Prec;
    Prec->next = P;
    (P->next)->prev = P;
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P)
{
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //------------- YOUR CODE HERE -------------
    P = Prec->next;
    Prec->next = P->next;
    (P->next)->prev = Prec;
    P->prev = NULL;
    P->next = NULL;
    //----------------------------------------
}
