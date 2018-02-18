#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;


    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P=new elmlist;
    //-------------your code here-------------
    info(P)=x;


    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    delete(P);


    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
    }
    else {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }


    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
    }
    else {
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
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
    P=first(L);
        while (P!=NULL){
            if (info(P).id==x.id){
                return P;
            }
            P=next(P);
        }
    return NULL;
    //----------------------------------------
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    P=first(L);
    if ((next(first(L)))==NULL) {
        first(L)=NULL;
        last(L)=NULL;
    }
    else if (first(L)!=NULL) {
        first(L)=next(P);
        prev(first(L))=NULL;
        next(P)=NULL;
    }
    else {

    }



    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    P=first(L);
    if ((next(first(L)))==NULL) {
        first(L)=NULL;
        last(L)=NULL;
    }
    else if (first(L)!=NULL) {
        last(L)=prev(P);
        next(last(L))=NULL;
        prev(P)=NULL;
    }
    else {

    }



    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P=first(L);
    do {
        view_data(info(P));
        P=next(P);
    }while (P!=NULL);


    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    next(P)=next(Prec);
    prev(P)=Prec;
    prev(next(Prec))=P;
    next(Prec)=P;

    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    P=next(Prec);
    prev(next(P))=Prec;
    next(Prec)=next(P);
    next(P)=NULL;
    prev(P)=NULL;


    //----------------------------------------
}

