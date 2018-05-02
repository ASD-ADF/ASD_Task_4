#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

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

address allocate(infotype x,infotype2 x2) {
    address P;
    P = new elmlist;
    info(P) = x;
    info2(P) = x2;
    next(P) = NULL;
    prev(P) = NULL;
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
    if (first(L) == NULL & last(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
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
    if (first(L) == NULL && last(L) == NULL) {
        insertFirst(L,P);
    } else {
        next(P) = NULL;
        last(L) = NULL;
        prev(P) = last(L);
        next(last(L)) = P;
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
    P = first(L);
    if (first(L)!= NULL ) {
            while (P!=NULL && P->info.id != x.id) {
                if (P->info.id == x.id) {
                    return P;
                } else {
                    p = next(P);
                }
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
    if (first(L) != NULL && last(L) != NULL){
        P = first(L);
        if (first(L)==last(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            P = first(L);
            first(L) = next(first(L));
            prev(P) = NULL;
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
     if (first(L) != NULL && last(L) != NULL){
        P = first(L);
        if (first(L)==last(L)){
            deleteFirst(L,P);
        } else {
            P = last(L);
            last(L) = prev(last(L));
            prev(P) = NULL;
            next(last(L)) = NULL;
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
    address P = new elmlist;
    if (first(L)== NULL) {
        cout << "empty list" << endl;
    } else {
        P = first(L);
        while (P != NULL) {
            view_data(info(P));
            P = next(P);
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
    if (Prec!= NULL) {
        if (next(Prec) != NULL) {
            next(P) = NULL;
            last(P) = NULL:
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec)) = P;
            next(Prec) = P;
        } else {
            insertLast(L,P);
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
     if (Prec!= NULL) {
        if (next(next(Prec))!= NULL) {
            next(Prec) = next(P);
            prev(next(P))=Prec;
            prev(P) = NULL;
            next(P) = NULL;
        } else {
            deleteLast(L,P);
        }
    }
    //----------------------------------------
}

