#include "doublelist.h"
#include "operation.h"
#include "my_data.h"
#include "my_data2.h"


void insertAndSort(List &L, address P) {
    /**
    * IS : List may be empty
    * PR : insert an element pointed by P into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID
    *      procedure must also check if such ID is already exists (No Duplicate ID)
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    if (L.First == NULL || P->info.id < L.First->info.id)
        insertFirst(L,P);
    else if (P->info.id > L.Last->info.id)
        insertLast(L,P);
    else
    {
        address Q = L.First;
        while (Q->next->info.id < P->info.id)
            Q = Q->next;
        insertAfter(L,Q,P);
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
    if (L.First != NULL)
    {
        if (L.First->info.id == x.id)
            deleteFirst(L,P);
        else if (L.Last->info.id == x.id)
            deleteLast(L,P);
        else
        {
            Prec = L.First;
            while (Prec != NULL && Prec->next->info.id != x.id)
                Prec = Prec->next;
            deleteAfter(L,Prec,P);
        }


    }


    //----------------------------------------
}
