#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L)
{
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
    L.First = NULL;
    L.Last = NULL;


    //----------------------------------------
}

address allocate(infotype x)
{
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;


    //----------------------------------------
    return P;
}

void deallocate(address &P)
{
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    delete(P);


    //----------------------------------------
}

void insertFirst(List &L, address P)
{
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    if (L.First != NULL)
        L.First->prev = P;
    P->next = L.First;
    L.First = P;
    if (L.Last == NULL)
        L.Last = L.First;


    //----------------------------------------
}

void insertLast(List &L, address P)
{
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    P->prev = L.Last;
    if (L.Last != NULL)
        L.Last->next = P;
    L.Last = P;
    if (L.First ==  NULL)
        L.First = L.Last;


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
    P = L.First;
    while (P != NULL && P->info.id != x.id)
        P = P->next;


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
    if(L.First != NULL)
    {
        P = L.First;
        L.First = P->next;
        L.First->prev = NULL;
        P->next = NULL;
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
    if (L.First != NULL)
    {
        if (L.First->next == NULL)
            deleteFirst(L,P);
            else
            {
                P = L.Last;
                L.Last = P->prev;
                L.Last->next = NULL;
                P->prev = NULL;
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
    address P = L.First;
    while (P != NULL)
    {
        cout<<"ID: "<<P->info.id<<endl;
        cout<<"FILM 1: "<<P->info.film1<<endl;
        cout<<"FILM 2: "<<P->info.film2<<endl;
        cout<<endl;
        P = P->next;
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
    if (Prec != NULL)
    {
        if (Prec->next == NULL)
            insertLast(L,P);
        else
        {
            P->next = Prec->next;
            P->prev = Prec;
            Prec->next = P;
            P->next->prev == P;
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
    if (L.First != NULL && Prec != NULL && Prec->next != NULL)
    {
        if (Prec->next->next == NULL)
            deleteLast(L,P);
        else
        {
            P = Prec->next;
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }


    //----------------------------------------
}

