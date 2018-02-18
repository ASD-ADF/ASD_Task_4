#include "doublelist.h"
#include "my_data.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------

    first(L) = NULL;
    last(L) = NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------

    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------

    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = prev(P);
        first(L) = P;
    }


    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
    prev(P) = first(L);
    last(L) = next(P);
    last(L) = P;
    }


    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    address P;
    //-------------your code here-------------

    if(first(L) !=NULL){
        P = first(L);
        while(P!= NULL){
            if(info(P).nim == x.nim){
                return P;
            }
            else{
                P= next(P);
            }
        };
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------

    if(first(L) == NULL){
        cout<<"List kosong"<<endl;
    }else if(first(L) == first(L)){
        address P = first(L);

        first(L) = NULL;
        last(L) = NULL;
    } else{
        address P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;

    }



    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if(first(L) != NULL){
        if(next(last(L)) == NULL){
           deleteFirst(L, P);
           }else{
            P = last(L);
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P)=NULL;
           }
    }



    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------

    address P;
    P = first(L);
    while(P!= NULL){
        view_data(info(P));
        cout<<endl;
        P = next(P);
    }



    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------

    if(first(L)!= NULL && Prec !=NULL){
        if(next(Prec)== NULL){
            insertLast(L, P);
        }else{
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec)) = P;
            next(Prec) = P;
        }
    }

    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------

    if(first(L) != NULL && Prec!= NULL){
        if(next(Prec)!= NULL){
            if(next(next(Prec))==last(L)){
                deleteLast(L, P);
            }else{
                P = next(Prec);
                next(Prec) = next(P);
                prev(next(P)) = Prec;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
    //----------------------------------------
}

