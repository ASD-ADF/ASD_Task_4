#include "doublelist.h"
#include "my_data.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    first(L)=NULL;


    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
    info(P)=info(x);
    next(P)=NULL;


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
    if (first(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
     prev(first(L))=P;
     next(P)=first(L);
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
    if (first(L)==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        next(last(L))=P;
        prev(P)=last(L);
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
    first(L)=P;
    while(P!=NULL)
    {
        if (info(P).id == x.id)
        {
            return P;
        }
        P=next(P);
    }



    //----------------------------------------
    return NULL;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L)==NULL)
    {

    }
    else
    {
        P=first(L);
        first(L)=next(P);
        next(P)=NULL;
        prev(first(L))=NULL;
    }



    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (first(L)==NULL)
    {

    }
    else
    {
        P=last(L);
        last(L)=prev(P);
        next(last(L))=NULL;
        prev(P)=NULL;
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
    while (P!=NULL)
    {
        view_data(info(P));
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
    if (Prec!=NULL)
    {
        if (first(L)==NULL)
        {

        }
        else
        {
            next(P)=next(Prec);
            prev(P)=Prec;
            prev(next(next(P)))=P;
            next(Prec)=P;
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
    if (Prec!=NULL)
    {
        if (Prec==last(L))
        {
            deleteLast(L,P);
        }
        else
        {
        P=next(Prec);
        next(Prec)=next(P);
        prev(next(P))=Prec;
        deallocate(P);
        }
    }


    //----------------------------------------
}

