#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L)=NULL;
    last(L)=NULL;
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    P = NULL;
    delete P;
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    if (first(L)==NULL&&last(L)==NULL)
    {
        first(L)=P;
        last(L)=P;
        next(P)=P;
        prev(P)=P;
    }
    else
    {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=first(L);
        next(last(L))=P;
        first(L)=P;
        if(next(first(L))==last(L))
        {
            prev(last(L))=P;
        }
        first(L)=P;
        next(last(L))=first(L);
    }
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    if(first(L)==NULL&&last(L)==NULL);
    {
        insertFirst(L,P);
    }
    else
    {
        prev(P)=prev(last(L));
        next(prev(last(L)))=P;
        last(L)=P;
        next(P)=first(L);
        prev(first(L))=last(L);
    }
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    if(first(L)!=NULL)
    {
        P=first(L);
        while(next(P)!=first(L)&&info(P).ID!=x.ID)
        {
            P=next(P);
        }
        if(info(P).ID==x.ID)
        {
            return P;
        }            
        else
        {
           return NULL; 
        }
    }
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    if(next(first(L))!=last(L)&&first(L)!=NULL)
    {
        P=first(L);
        first(L)=next(P);
        prev(first(L))=last(L);
        next(last(L))=first(L);
        next(P)=NULL;
        prev(P)=NULL;
    }
    else
    {
        cout<<"List Kosong";
        P=first(L);
        next(P)=NULL;
        prev(P)=NULL;
        first(L)=NULL;
        last(L)=NULL;
    }
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    address Q;
    if(last(L)==first(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        P=last(L);
        Q=prev(P);
        next(Q)=first(L);
        last(L)=Q;
        prev(first(L))=Q;
    }
}

void insertAfter(address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    if(Prec==last(L))
    {
        insertLast(L,P);
    }
    else if(Prec==first(L))
    {
        insertFirst(L,P);
    }
    else
    {
        if(next(Prec)==last(L))
        {
            insertLast(L,P);
        }
        else
        {
            prev(next(Prec))=P;
            next(P)=next(Prec);
            prev(P)=Prec;
            next(P)=NULL;
            prev(P)=NULL;
        }
    }

}
void deleteAfter(address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    if(Prec!=NULL)
    {
        P=next(Prec);
        if(P==Last(L))
        {
            deleteLast(L,P);
            cout<<"List Kosong";
        }
        else if(P==first(L))
        {
            deleteFirst(L,P);
        }
    else
    {
        cout<<"Kosong";
        next(Prec)=next(P);
        prev(next(P))=Prec;
    }
    }
}
