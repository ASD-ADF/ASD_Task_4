#include "doublelist.h"
#include "my_data.h"

void createList(List &L)
{
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    first(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x)
{
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    return P;
    //----------------------------------------
}

void deallocate(address &P)
{
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(first(L)) = P;
        next(P) = first(L);
        first(L) = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    address Q = first(L);
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
    //----------------------------------------
}

address findElm(List L, infotype x)
{
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    address P = first(L);
    //-------------your code here-------------
    while (P != NULL)
    {
        if (x.id == info(P).id)
        {
            return P;
        }
        else
        {
            P = next(P);
        }
    }
    cout<<"ID not found"<<endl;
    return NULL;
    //----------------------------------------
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L) != NULL)
    {
        P = first(L);
        if (next(first(L)) == NULL)
        {
            first(L) = NULL;
        }
        else
        {
            P = first(L);
            first(L) = next(P);
            prev(next(P)) = NULL;
            next(P) = NULL;
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    P = first(L);
    address Q  = first(L);

    if (first(L) != NULL)
    {
        if (next(first(L)) == NULL)
        {
            deleteFirst(L, P);
        }
        else
        {
            while (next(next(Q)) != NULL)
            {
                Q = next(Q);
            }
            P = last(L);
            last(L) = prev(P);
            next(prev(P)) = NULL;
            prev(P) = NULL;
        }
    }
    //----------------------------------------
}

void printInfo(List L)
{
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P = first(L);

    while (P != NULL)
    {
        view_data(info(P));
        P = next(P);
    }
    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P)
{
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    if (first(L) == NULL)
    {
        first(L) = P;
    }
    else if ((next(Prec)) == NULL)
    {
        next(Prec) = P;
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P)
{
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    if (next(Prec) != NULL)
    {
        P = next(Prec);
        prev(next(P)) = Prec;
        next(Prec) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
    //----------------------------------------
}
