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
    if (first(L)==NULL && last(L)==NULL){
        first(L)=P;
        last(L)=P;
    }

    address Q =findElm(L,info(P));
    if(Q!=NULL){
        cout<<"ID is already exist (No Duplicate ID)"<<endl;
    }else{
        if(info(P).id < info(first(L)).id){
            insertFirst(L,P);
        }else if (info(P).id > info(last(L)).id){
            insertLast(L,P);
        }else{
            address U=first(L);
            while (info(next(U)).id < info(P).id){
                U=next(U);
            }insertAfter(L,U,P);
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
    P=findElm(L,x);
    if (P==NULL){
        cout<<"ID is not found"<<endl;
        return;
    }
    if (first(L)==P){
        deleteFirst(L,P);
    }else if(last(L)=P){
        deleteLast(L,P);
    }else{
        Prec=first(L);
        while (next(Prec)!=P){
            Prec=next(Prec);
        }deleteAfter(L,Prec,P);
    }
    deallocate(P);
    cout<<"Delete successed"<<endl;
    //----------------------------------------
}
