#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    First(L)=NULL;
    Last(L)=NULL;

    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    P=new elmlist;
    Info(P)=x;
    Next(P)=NULL;
    Prev(P)=NULL;
    //----------------------------------------
    return P;
}

void dealokasi(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    P=NULL;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
      if (First(L)==NULL && Last(L)==NULL)
    {
        First(L) = Last(L)= P;
        Next(P)=P;
        Prev(P)=P;

    }
    else
    {
        Next(P)=First(L);
        Prev(P)=Last(L);
        Next(Last(L))=First(L);
        Next(Last(L))=P;
        First(L)=P;
        if (Next(First(L))==Last(L)){
            Prev(Last(L))=P;
        }


        First(L)=P;
        Next(Last(L))=First(L);
    }


    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (First(L)==NULL && Last(L)==NULL){
        insertFirst(L,P);
    }
    else {
        Prev(P)=Prev(First(L));
        Next(Prev(Last(L)))=P;
        Last(L)=P;
        Next(P)=First(L);
        Prev(First(L))=Last(L);
    }

    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    //-------------your code here-------------
    P=First(L);
    if (P==NULL)
        return 0;
    else
    {
        while(P!=Last(L))
        {
            if (Info(P).ID == x.ID)
            {
                return P;
            }
            P=Next(P);
        }
        if (Info(P).ID==x.ID)
            return P;
        else
            return NULL;
    }

    //----------------------------------------
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
     if (First(L)->next != Last(L) && First(L) != NULL){
        P = First(L);
        First(L) = Next(P);
        Prev(First(L)) = Last(L);
        Next(Last(L)) = First(L);
        Next(P) = NULL;
        Prev(P)= NULL;
    }
    else
        {
        cout<<"??";
        P=First(L);
        Next(P)=NULL;
        Prev(P)=NULL;
        First(L)=NULL;
        Last(L)=NULL;
    }


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    address Q;
    if (Last(L) == First(L))
    {
        deleteFirst(L,P);
    }
    else
    {
        P = Last(L);
        Q = Prev(P);
        Next(Q) = First(L);
        Last(L) = Q;
        Prev(First(L)) = Q;
    }

    //----------------------------------------
}

void insertAfter(List&L, address Prec , address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if ( Prec == Last(L))
    {
        insertLast(L,P);
    }
    else if (Prec == First(L)){
        insertFirst(L,P);
    }
    else
    {
        if (Next(Prec) == Last(L))
            insertLast(L,P);
        else
        {

            Prev(Next(Prec)) = P;
            Next(P)= Next(Prec);
            Prev(P)= Prec;
            Next(Prec)= P;
            Next(P)= NULL;
            Prev(P)= NULL;
        }
    }



    //----------------------------------------

}
void deleteAfter(List &L,address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
     if (Prec != NULL)
    {
        P = Next(Prec);
        if (P == Last(L))
        {
            deleteLast(L,P);
            cout << "Lagu terakhir telah dihapus";
        }
        else if (P == First(L))
            deleteFirst(L,P);

    }
    else
    {
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
    }
}


