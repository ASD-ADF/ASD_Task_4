#include "doublelist.h"
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

    address P;
    //-------------your code here-------------
    P=new elmlist;
    info(P)=x;
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
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
    } else {
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
    if (first(L)==NULL && last(L)==NULL) {
        insertFirst(L,P);
    } else {
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
    if (first(L)==NULL) {
        return NULL;
    } else {
        while(P!=last(L)) {
            if (info(P).ID==x.ID) {
                return P;
            }
            P=next(P);
        }
        if ((P==last(L)) && (info(P).ID==x.ID)) {
            return P;
        } else {
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
    if (first(L)!=NULL) {
        P=first(L);
        if (first(L)==last(L)) {
            first(L)=NULL;
            last(L)=NULL;
        } else {
            first(L)=next(first(L));
            prev(P)=NULL;
            prev(first(L))=NULL;
            next(P)=NULL;
        }

    }
    deallocate(P);


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L)!=NULL) {
        P=last(L);
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(last(L))=NULL;
    }
    deallocate(P);


    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P = first(L);
    if (first(L)!=NULL) {
        do {
            view_data2(info(P));
            P=next(P);
        } while (P!=NULL);
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
    if (Prec!=NULL) {
        next(P)=next(Prec);
        prev(P)=Prec;
        prev(next(Prec))=P;
        next(Prec)=P;
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
    if (Prec!=NULL) {
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P)=NULL;
    }
    deallocate(P);

    //----------------------------------------
}

