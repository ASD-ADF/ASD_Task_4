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
if(first(L) == NULL){
        insertFirst(L, P);
        return;
    }
    address x = findElm(L, info(P));

    if(x == NULL){
        address Q=first(L);
        address Prec=first(L);
        while(next(Q)!=NULL){
            Q=next(Q);
        }
        if(info(P).nim < info(first(L)).nim){
            insertFirst(L, P);
        }
        else if(info(P).nim <info(Q).nim){
            insertLast(L, P);
        }
        else{
            while(info(next(Prec)).nim < info(P).nim){
                Prec=next(Prec);
            }
            cout<<info(Prec).nim<<endl;
            insertAfter(L, Prec, P);
        }
    }else{
        cout<<"ID sudah ditemukkan"<<endl;
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

      P = findElm(L, x);
    if(P==first(L)){
        deleteFirst(L, P);
    }else{
        Prec = first(L);
        while(next(Prec)!=P){
            Prec = next(Prec);
        }
        deleteAfter(L, Prec, P);
    }


    //----------------------------------------
}
