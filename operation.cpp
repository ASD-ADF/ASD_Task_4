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
    bool check=true;
    int x=info(P).ID;
    address R=first(L);
    while (R!=NULL) {
        if(info(R).ID==x) {
            check=false;
            cout<<"ID YANG DIMASUKKAN SAMA, MASUKKAN ULANG"<<endl;
        }
        R=next(R);
    }

    while (check==true) {
        if (first(L)==NULL) {
            insertFirst(L,P);
        } else if (info(P).ID<=info(first(L)).ID) {
            insertFirst(L,P);
        } else if (info(P).ID>=info(last(L)).ID) {
            insertLast(L,P);
        } else {
            address Q=first(L);
            while (info(P).ID>info(next(Q)).ID) {
                Q=next(Q);
            }
            insertAfter(L,Q,P);
        }
        check=false;
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
    if(first(L)!=NULL) {
        P=findElm(L,x);
    }
    if (P==NULL) {
        cout<<"ID tidak ditemukan"<<endl;
    }
    address last = first(L);
    if (first(L)==P) {
        deleteFirst(L,P);
    } else if (P==last(L)) {
        deleteLast(L,P);
    } else {
        Prec=first(L);
        while (next(Prec)!=P) {
            Prec=next(Prec);
        }
        deleteAfter(L,Prec,P);
    }

    //----------------------------------------
}
