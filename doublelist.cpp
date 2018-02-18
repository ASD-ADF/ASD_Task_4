#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    L.first = NULL;
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
    next(P) = first(L);
    first(L) = P;
    prev(first(L)) = P;
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    if (L.first != NULL)
    {
		P->prev = L.last;
		L.last->next = P;
		L.last = P;
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
    bool found = false;
	if (L.first != NULL)
    {
		P = L.first;
		while (P != L.last->next && !found) {
			if (P->info.id == x.id)
				found = true;
			else
				P = P->next;
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
    if(first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if (L.first != NULL)
    {
		P = L.last;
		L.last = L.last->prev;
		L.last->next = NULL;
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
    while (P != NULL)
    {
        view_data (info(P));
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
    if (L.first != NULL && Prec != NULL)
    {
		P->prev = Prec;
		P->next = Prec->next;
		Prec->next->prev = P;
		Prec->next = P;
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
    P = first(L);
    if ((prev(P)==NULL)&&(next(P)!=NULL))
    {
        deleteFirst(L,P);
    }else if ((prev(P)!=NULL)&&(next(P)==NULL))
    {
        deleteLast(L,P);
    }else
    {
        prev(Prec) = next(next(Prec));
        prev(next(P)) = Prec;
        prev(P) = NULL;
        next(P) = NULL;
    }
    //----------------------------------------
}

