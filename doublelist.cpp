#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
   // cout<<"your code here"<<endl;
    first(L)=NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
   // cout<<"your code here"<<endl;
    P = new elmlist;
    info(P)=x;
    next(P)=NULL;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
   // cout<<"your code here"<<endl;
    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
   // cout<<"your code here"<<endl;
        next(P)=first(L);
        first(L)=P;

    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    //cout<<"your code here"<<endl;
    address Q = first(L);
    if(first(L)!=NULL){
        while(Q!=NULL){
            Q = next(Q);
        }
        next(Q)=P;
    }else{
        first(L)=P;
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
   // cout<<"your code here"<<endl;
     P = first(L);
    if(first(L)!= NULL){
        while(P != NULL && P->info.yid2 != x.yid2){
            if(P->info.yid2 == x.yid2){
                return P;
            }else{
                P=next(P);
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
    //cout<<"your code here"<<endl;
     if(first(L)!=NULL){
        P = first(L);
        first(L) = next(first(L));
        next(P)=NULL;
    }else{
        P = NULL;
    }


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    //cout<<"your code here"<<endl;
    address Q = first(L);
    if(first(L)!=NULL){
        if(next(first(L))==NULL){
        deleteFirst(L,P);
        }else{
            while(next(Q)!=NULL){
              Q = next(next(Q));
            }
            P = next(Q);
            next(Q)=NULL;
        }
    }else{
        P = NULL;
    }


    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
   // cout<<"your code here"<<endl;
    address P = first(L);
    if(first(L)!=NULL){
        cout<<"calling data of users"<<endl;
        while(P!=NULL){
            cout<<"Address   : "<<P->info.yblood<<endl;
            cout<<"ID     : "<<P->info.yid2<<endl;
            cout<<"Blood type  : "<<P->info.yblood<<endl;

            P = next(P);
        }
    }else{
        cout<<"empty list"<<endl;
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
   // cout<<"your code here"<<endl;
     if(next(Prec)!=NULL){
        next(P) = next(Prec);
        next(Prec) = P;
    }else{
        insertLast(L,P);
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
   // cout<<"your code here"<<endl;
     if(Prec!=NULL){
        if(next(Prec)!=NULL){
            P = next(Prec);
            next(Prec) = next(next(Prec));
            P = NULL;
        }else{

        }
    }

    //----------------------------------------
}

