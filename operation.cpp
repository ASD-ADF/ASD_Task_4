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
   if(first(L)==NULL){
            insertFirst(L,P);
        }else if(info(first(L)).id >= info(P).id){
            insertFirst(L,P);
        }else if(info(first(L)).id <= info(P).id){
            address Q = first(L);
            address F = Q;
            if(first(L) == last(L)){
                insertLast(L,P);
            }else{
                while(Q!=NULL){
                    if(info(Q).id <= info(P).id){
                        F = Q;
                    }
                    Q = next(Q);

                }
                insertAfter(L,F,P);

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
    if(first(L)!=NULL){
        Prec = findElm(L,x);
        if(Prec == first(L)){
            deleteFirst(L,P);
            cout<<"Data with ID : "<<info(P).id<<" Deleted "<<endl;
        }else if(Prec == last(L)){
            deleteLast(L,P);
            cout<<"Data with ID : "<<info(P).id<<" Deleted "<<endl;
        }else{
            deleteAfter(L,prev(Prec),P);
            cout<<"Data with ID : "<<info(prev(P)).id<<" Deleted "<<endl;
        }
    }else{
        cout<<"Empty List"<<endl;
    }



    //----------------------------------------
}
