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

    //-------------your code here-------------
    if ((first(L)==NULL) &&(last(L)==NULL))
    {
        insertFirst(L,P);
    }
    else if (info(P).id<info(first(L)).id)
    {
        insertFirst(L,P);
    }
    else if(info(P).id >info(last(L)).id)
    {
        insertLast(L,P);
    }
    else
    {
        address Q = first(L);
        while (info(next(Q)).id < info(P).id)
        {
            Q = next(Q);
            insertAfter(L,Q,P);
        }
    }



    //----------------------------------------
}


void deletebyID(List &L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = x.id is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    address Q;
    P = findElm(L,x);
    if( P == first(L))
    {
        deleteFirst(L,P);
    }
    else if(next(P) == NULL)
    {
        deleteLast(L,P);
    }
    else
    {
        while(next(Q) != P)
        {
            Q = next(Q);
        }
    deleteAfter(L,Q,P);
    }


    //----------------------------------------
}
