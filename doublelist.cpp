#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L){
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;
    //----------------------------------------
}

address allocate(infotype x){
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P = new elmlist;
    //-------------your code here-------------
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P){
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P){
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    if (first(L)!=NULL){
        address Q = first(L);
        next(P) = Q;
        prev(Q) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P){
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    if (first(L)==NULL){
        insertFirst(L, P);
    }else{
        address Q = new elmlist;
        Q = last(L);
        next(Q) = P;
        prev(P) = Q;
        last(L) = P;
    }
    //----------------------------------------
}

address findElm(List L, infotype x){
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */
    address Q = new elmlist;
    bool found = false;
    //-------------your code here-------------
    if (first(L)!=NULL){
        Q = first(L);
        while(Q!=NULL && !found){
            if(info(Q).id == x.id){
                return Q;
                found = true;
            }
            Q = next(Q);
        }
    }else if (first(L)==NULL || !found){
        return NULL;
    }
    //----------------------------------------
}

void deleteFirst(List &L, address &P){
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L)==NULL){
        cout << "empty list"<< endl;
    }else{
        if(first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }else{
            P = first(L);
            prev(next(P)) = NULL;
            first(L) = next(P);
            next(P) = NULL;
        }

    }
    //----------------------------------------
}

void deleteLast(List &L, address &P){
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L)==NULL){
        cout << "empty list" << endl;
    }else if (first(L)==last(L)){
            deleteFirst(L, P);
          }else{
            address Q = prev(last(L));
            P = last(L);
            prev(last(L)) = NULL;
            next(Q) = NULL;
            last(L) = Q;
        }
    //----------------------------------------
}

void printInfo(List L){
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P = new elmlist;
    if (first(L)==NULL){
        cout << "empty list" << endl;
    }else{
        P = first(L);
        do{
            view_data(info(P));
            P = next(P);
        }
        while(P!=NULL);
    }
    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P){
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    if (Prec==NULL && P==NULL){
        insertLast(L, P);
    }else{
        if(next(Prec)!=NULL){
            address Q = next(Prec);
            next(P) = Q;
            prev(Q) = P;
            next(Prec) = P;
            prev(P) = Prec;
        }
    }
    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P){
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    if(Prec!=NULL){
        if(next(next(Prec))==NULL){
            deleteLast(L, P);
        }else{
            P = next(Prec);
            address Q = next(P);
            next(Prec) = Q;
            prev(Q) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
    //----------------------------------------
}
