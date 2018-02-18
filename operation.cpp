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
    address Z = first(L);
    address F = findElm(L,info(P));
    if (first(L) == NULL && last(L) == NULL) {
        first(L) = P;
        last(L) = P;
        return;
    }
    if (F != NULL) {
        cout << "ID is already exists"<< endl;
    } else {
        if (info(P).id <= info(first(L)).id){
            insertFirst(L,P);
        } else if (info(P).id >= info(last(L)).id) {
            insertLast(L,P);
        } else {
            while (info(next(Z)).id < info(P).id) {
                Z = next(Z);
            }
            insertAfter(L,P,Z);
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
    T = findElm(L,X);
    if (T==NULL) {
        cout << "ID not found"<< endl;
        return;
    }
    if (first(L)==T) {
        deleteFirst(L,T);
    } else if (last(L)==T) {
        deleteLast(L,T);
    } else {
        Prec = first(L);
        while (next(Prec) != T) {
            Prec = next(Prec);
        }
        deleteAfter(L,T,Prec);
    }
    deallocate(T);


    //----------------------------------------
}
