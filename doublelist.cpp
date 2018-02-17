#include "doublelist.h"
#include "my_data2.h"

void createList(List &L)
{
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;
    first(L)=NULL;
    last(L)=NULL;

    //----------------------------------------
}

address allocate(infotype x)
{
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    P=new elmlist;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P)
{
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    if(first(L)==NULL&&last(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
        next(P)=first(L);
        prev(next(P))=P;
        first(L)=P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    if(first(L)==NULL&&last(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }


    //----------------------------------------
}

address findElm(List L, infotype x)
{
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    address P;
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    //bool found=false;
    P=first(L);

    if(first(L)==NULL&&last(L)==NULL)
    {
        return NULL;
    }
    else
    {
        while(P!=NULL)
        {
            if(x.ID==info(P).ID)
            {
                return P;
            }
            P=next(P);
        }
        return NULL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P)
{
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    if(first(L)==NULL&&last(L)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        if(next(first(L))==NULL)
        {
            P=first(L);
            first(L)=NULL;
            last(L)=NULL;
            deallocate(P);
        }
        else
        {
            P=first(L);
            first(L)=next(P);
            prev(next(P))=NULL;
            deallocate(P);
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;

    if(first(L)==NULL&&last(L)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        if(next(last(L))==NULL)
        {
            P=last(L);
            first(L)=NULL;
            last(L)=NULL;
            deallocate(P);
        }
        else
        {
            if(next(first(L))==NULL)
            {
                P=first(L);
                first(L)=NULL;
                last(L)=NULL;
                deallocate(P);
            }
            else
            {
                address Q=first(L);
                while(next(next(Q))!=NULL)
                {
                    Q=next(Q);
                }
                P=next(Q);
                last(L)=Q;
                next(Q)=NULL;
                prev(P)=NULL;
                deallocate(P);
            }
        }
    }
    //----------------------------------------
}

void printInfo(List L)
{
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;
    address P=first(L);
    int i=1;

    while(P!=NULL)
    {
        cout<<i<<". ";
        view_data(info(P));
        i++;
        P=next(P);
    }

    //----------------------------------------
}


void insertAfter(List &L, address Prec, address P)
{
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;
//    address z=first(L);

    Prec=first(L);
    if(first(L)==NULL&&last(L)==NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        if(info(P).ID>=info(first(L)).ID&&info(P).ID<=info(last(L)).ID)
        {
            while(info(Prec).ID<info(P).ID)
            {
                Prec=next(Prec);
            }
            next(P)=Prec;
            prev(P)=prev(Prec);
            next(prev(Prec))=P;
            prev(Prec)=P;
        }
    }
    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P)
{
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;
    address z=first(L);

//    Prec=first(L);
    if(first(L)==NULL&&last(L)==NULL)
    {
        cout<<"list kosong"<<endl;
    }
    else
    {
        if(next(first(L))==NULL)
        {
            if(info(Prec).ID==info(first(L)).ID)
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
            if(info(Prec).ID>info(first(L)).ID&&info(Prec).ID<info(last(L)).ID)
            {
                while(info(next(z)).ID!=info(Prec).ID)
                {
                    z=next(z);
                }
                P=next(z);
                prev(next(P))=z;
                next(z)=next(P);
                prev(P)=NULL;
                next(P)=NULL;
                deallocate(P);
            }
        }

    }
    //----------------------------------------
}

