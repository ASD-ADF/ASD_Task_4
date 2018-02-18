#include "doublelist.h"
#include "my_data.h"
#include "my_data2.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */
    //-------------your code here-------------
        first(L)=NULL;
        last(L)=NULL;


    //----------------------------------------
}

address allocate(infotype x, infotype2 x2) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    address P;
    //-------------your code here-------------
    P = new elmlist;
    info(P)=x;
    info2(P)=x2;
    prev(P)=NULL;
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
    if(first(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L)= P;
        last(L)=P;
    }


    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    cout<<"your code here"<<endl;
    if(first(L) != NULL){
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    } else {
        insertFirst(L,P);
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
    cout<<"your code here"<<endl;
    P = first(L);
    if (first(L) != NULL){
        while (P != NULL && P -> info.id != x.id){
            if ( P -> info.id == x.id){
                return P;
            } else {
                P = next(P);
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
    cout<<"your code here"<<endl;
    if(first(L) != NULL){
        if (first(L) == last(L)){
            P = first(L);
            next(first(L)) = NULL;
            prev(first(L)) = NULL;
        } else {
            P = first(L);
            next(P) = NULL;
            prev(P) = NULL;
            first(L) = next(first(L));
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
    cout<<"your code here"<<endl;
    if(first(L) != NULL){
        if(first(L)==last(L)){
            P = first(L);
            first(L)=NULL;
            last(L)=NULL;
        }else{
            P = last(L);
            last(L)=prev(last(L));
            next(last(L))=NULL;
            prev(P)=NULL;
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
    cout<<"your code here"<<endl;
    address e = first(L);
    cout << "==>><<==>><<==<<>>==>><<==>><<==" << endl;

    while (e != NULL) {
        cout<<"=STUDENT="<<endl;
        cout<<"ID    : ";cout<<e->info.id<<endl;
        cout<<"Name  : ";cout<<e->info.name<<endl;
        cout<<"Class : ";cout<<e->info.clas<<endl;
        cout<<"Score : ";cout<<e->info.score<<endl;
        cout<<"=Lecturer="<<endl;
        cout<<"ID      : ";cout<<e->info2.id_lec<<endl;
        cout<<"Name    : ";cout<<e->info2.name_lec<<endl;
        cout<<"Subject : ";cout<<e->info2.clas_lec<<endl;
        cout<<"--------------"<<endl;
         e = next(e);
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
    cout<<"your code here"<<endl;
    if (first(L) != NULL) {
        if (Prec ==  last(L)) {
            insertLast(L,P);
        } else {
            next(P) = next(Prec);
            prev(P) = Prec;
            next(Prec) = P;
            prev(next(Prec)) = P;
        }
    } else {
        insertFirst(L,P);
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
    cout<<"your code here"<<endl;
    if(first(L)!=NULL){
        if(first(L)!=last(L)){
            if(next(Prec)==last(L)){
                deleteLast(L,P);
            }else if(Prec!=last(L)){
                P = next(Prec);
                next(Prec)=next(P);
                prev(next(P))=Prec;
                prev(P)=NULL;
                next(P)=NULL;
            }
        }
    }

    //----------------------------------------
}

