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
//    if (first(L) == NULL)
//    {
//        insertFirst(L, P);
//        return;
//    }
//
//    address X = findElm(L, info(P));
//
//    if (X == NULL)
//    {
//        address Q = first(L);
//        address Prec = first(L);
//        while (next(Q) != NULL)
//        {
//            Q = next(Q);
//        }
//        if (info(P).id < info(first(L)).id)
//        {
//            insertFirst(L,P);
//        }
//        else if (info(P).id > info(Q).id)
//        {
//            insertLast(L,P);
//        }
//        else
//        {
//            while (info(next(Prec)).id < info(P).id)
//            {
//                Prec = next(Prec);
//            }
//            cout<<info(Prec).id<<endl;
//            insertAfter(L, Prec, P);
//        }
//    }
//    else
//    {
//        cout<<" ID Sudah Terdaftar "<<endl;
//    }
//-------------------------------------------------

    if (first(L) == NULL)
    {
        insertFirst(L, P);
        return;
    }

    address X = findElm(L, info(P));

    if (X == NULL)
    {
        if (info(P).id <= info(first(L)).id)
            {
                insertFirst(L, P);
            }
        else if (info(P).id >= info(last(L)).id)
            {
                insertLast(L, P);
            }
        else
            {
                address Prec = first(L);
                while (info(next(Prec)).id < info(P).id)
                    {
                        Prec = next(Prec);
                    }
                insertAfter(L, Prec, P);
            }
    }
    else
    {
        cout<<"ID already registered"<<endl;
    }
}


void deletebyID(List &L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = x.id is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    P = findElm(L,x);
    Prec = first(L);

    if (next(P) == NULL)
    {
        deleteLast(L,P);
    }
    else if(P == first(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        while (next(Prec) != P)
        {
            Prec = next(Prec);
        }
        deleteAfter(L,Prec,P);
    }

    //----------------------------------------
}
