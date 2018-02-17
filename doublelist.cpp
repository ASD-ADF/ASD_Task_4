#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"
#include <iostream>

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;

    //----------------------------------------
}

address allocate(infotype x, infotype2 x2) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
    P=new elmlist;
    info(P)=x;
    info2(P)=x2;
    next(P)=NULL;
    prev(P)=NULL;
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
    if(first(L)!=NULL && last(L)!=NULL){
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }else{
        last(L)=P;
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
    if(first(L)!=NULL && last(L)!=NULL){
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }else{
        first(L)=P;
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
    if (first(L)!=NULL && last(L)!=NULL){
        address P=first(L);
        while ((info(P).id !=  x.id) && (next(P)!=NULL)) {
            P=next(P);
        }
        if (info(P).id == x.id){
            return P;
        }else{
            return NULL;
        }
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
    P=first(L);
    if (first(L)==last(L)){
        createList(L);
    }else{
        prev(first(L))=NULL;
        first(L)=next(first(L));
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    P=last(L);
    if (last(L)==first(L)){
        createList(L);
    }else{
        next(last(L))=NULL;
        last(L)=prev(last(L));
    }
    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    if(first(L)!=NULL && last(L)!=NULL){
        address P = first(L);
        while (P!=last(L)){
            view_data(info(P));
            view_data2(info2(P));
            cout<<endl;
            P=next(P);
        }
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
    if(Prec!=NULL){
        next(P)=next(Prec);
        prev(P)=Prec;
        next(Prec)=P;
        if(Prec==last(L)){
            last(L)=P;
        }else{
            prev(next(P))=P;
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
    if (Prec!=NULL){
        P=next(Prec);
        if (P!=last(L)){
            next(Prec)=next(P);
            prev(next(P))=Prec;
            prev(P)=NULL;
            next(P)=NULL;
        }else{
            next(Prec)=NULL;
            last(L)=Prec;
        }
    }
    //----------------------------------------
}

