#include "doublelist.h"
#include "operation.h"
#include "my_data2.h"


void insertAndSort(List &L, address P)
{
    /**
    * IS : List may be empty
    * PR : insert an element pointed by P into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID
    *      procedure must also check if such ID is already exists (No Duplicate ID)
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    cout<<"your code here"<<endl;
    address Prec;

    if(first(L)==NULL&&last(L)==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        address w=findElm(L,info(P));
        if(w==NULL)
        {
            if(info(P).ID<info(first(L)).ID)
            {
                insertFirst(L,P);
            }
            else if(info(P).ID>info(last(L)).ID)
            {
                insertLast(L,P);
            }
            else if(info(P).ID>=info(first(L)).ID&&info(P).ID<=info(last(L)).ID)
            {
                insertAfter(L,Prec,P);
            }
        }
        else
        {
            cout<<"Maaf, id sudah ada"<<endl;
        }
    }
    //----------------------------------------
}


void deletebyID(List &L, infotype x)
{
    /**
    * IS : List L may be empty
    * FS : an element with ID info = x.id is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    if(first(L)==NULL&&last(L)==NULL)
    {
        cout<<"List kosong";
    }
    else
    {
        if(next(first(L))==NULL)
        {
            if(x.ID==first(L)->info.ID)
            {
                deleteFirst(L,P);
            }
            else
            {
                cout<<"Id tidak ditemukan";
            }
        }
        else
        {
            if(x.ID==info(first(L)).ID)
            {
                deleteFirst(L,P);
            }
            else if(x.ID==info(last(L)).ID)
            {
                deleteLast(L,P);
            }
            else if(x.ID>info(first(L)).ID&&x.ID<info(last(L)).ID)
            {
                info(Prec)=x;
                deleteAfter(L,Prec,P);
            }
        }
    }
    //----------------------------------------
}
