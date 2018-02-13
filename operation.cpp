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
    address Q, Prec, duplicate;
    duplicate = NULL;

    duplicate = findElm(L,info(P));

    if(duplicate != NULL){
        cout<<endl<<"WARNING: Can't input same ID!"<<endl;
    }
    else{
        if(first(L) != NULL){
            Q = first(L);
            while(next(Q) != NULL){
                Q = next(Q);
            }
        }
        //for mytype, use player_id
        //for mytype2, use team_id
        if((first(L) == NULL) || (info(P).team_id < info(first(L)).team_id)){
            insertFirst(L,P);
        }
        else if(info(P).team_id > info(Q).team_id){
            insertLast(L,P);
        }
        else{
            Prec = first(L);
            while(info(next(Prec)).team_id <= info(P).team_id){
                Prec = next(Prec);
            }
            insertAfter(L,Prec,P);
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
    P = findElm(L,x);
    if(P == first(L)){
        deleteFirst(L,P);
    }
    else if(next(P) == NULL){
        deleteLast(L,P);
    }
    else{
        Prec = first(L);
        while(next(Prec) != P){
            Prec = next(Prec);
        }
        deleteAfter(L,Prec,P);
    }
    //----------------------------------------
}
