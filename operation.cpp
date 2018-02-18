#include "doublelist.h"
#include "operation.h"
#include "my_data.h"


void insertAndSort(List &L, address P) {
    /**
    * IS : List may be empty
    * PR : insert an element pointed by P into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID
    *      procedure must also check if such ID is already exists (No Duplicate ID)
    * FS : elements in List L sorted by ID, P is inside List L
    */

    address Prec = first(L);
    address Q = first(L);
    if (first(L)== NULL)
    {
        insertFirst(L,P);
    }
    else if (first(L) != NULL)
    {
        while (next(Q) != NULL)
        {
            Q = next (Q);
        }
        if (info(P).id < info(first(L)).id)
        {
            insertFirst(L,P);
        }
        else if (info(P).id > info(Q).id)
        {
            insertLast(L,P);
        }
        else
        {
            while(info(Prec).id <= info(P).id)
            {
                Prec = next(Prec);
            }
            insertAfter(L,Prec,P);
        }
    }
}


void deletebyID(List &L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = x.id is deleted from List L (deallocate)
    */

    address Prec, P;
    P = findElm(L,x);
    if( P = first(L))
    {
        deleteFirst(L,P);
    }
    else if(next(P) == NULL)
    {
        deleteLast(L,P);
    }
    else
    {
        while(next(Prec) != P)
        {
            Prec = next(Prec);
        }
    }
    deleteAfter(L,Prec,P);
}
