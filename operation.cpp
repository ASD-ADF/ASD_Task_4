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
    address Q=first(L);
    if ((first(L)==NULL) || (info(P).id<info(first(L)).id)){
        insertFirst(L, P);
    } else if (info(P).id>info(last(L)).id){
        insertLast(L, P);
    } else {
        while (info(P).id>info(next(Q)).id) {
            Q=next(Q);
            }
        insertAfter(L, Q, P);
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
    findElm(L, x);
    Prec=findElm(L, x);
    if (Prec==first(L)) {
        deleteFirst(L, Prec);
    }
    else if (Prec==last(L)) {
        deleteLast(L, Prec);
    }
    else {
        P=first(L);
        while (next(P)!=Prec) {
            P=next(P);
        }
        deleteAfter(L, P, Prec);
    }
    deallocate(Prec);



    //----------------------------------------
}
