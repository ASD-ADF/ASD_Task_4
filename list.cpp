#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
    First(L)= NULL;
    Last(L)= NULL;

    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address P;
    //-------------your code here-------------
    address P = new elmlist;
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

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
	address Q;
	if (First(L)==NULL)
	{
	    First(L)=P;
	    Last(L)=P;
	    Next(P)=P;
	    Prev(P)=P;
	}
	else
    {
        Next(P)=First(L);
        Prev(First(L))=P;
        Prev(P)=Last(L);
        Next(Last(L))=P;
        First(L)=P;

    }

    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (Last(L)=NULL)
    {
        Last(L)=P;
        First(L)=P;
        Next(P)=P;
        Prev(P)=P;
    }
    else
    {
        Next(P)=First(L);
        Next(Last(L))=P;
        Prev(first(L))=P;
        Prev(P)=Next(Last(L));
        Last(L)=P;

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
    P=First(L));
    do
{

    if (Info(P)==x)
    {
        return P;
    }
}
    else
    {
        P=Next(P);
    }

	while (P!= L.First);
	return NULL;
    //----------------------------------------
   // return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (First(L) != NULL)
    {
        P = First(L);
        First = NULL;
    }
    else
    {
        P = First(L);
        address Q = First(L).
        while (Next(Q)!= First(L))
        {
            Q = Next(First(L))

        }
        Next(Q)=Next(First(L));
        first(L)=Next(First(L));

    }
    dealokasi(P);
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (First(L)== NULL)
    {

        if (Next(First(L))==First(L))
        {
            P=First(L);
            First(L)=NULL;

        }
        else
        {
            address Q = First(L);
            while (Next(Next(Q))!= First(L))
            {
                Q = Next(Q);

            }
            P=Next(Q);
            Next(Q)=First(L);
        }
    }


    //----------------------------------------
}

void insertAfter(address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    Next(P)= Next(Prec);
    Next(Prec)=P;

    //----------------------------------------

}
void deleteAfter(address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (First(L)!= NULL)
    {
        if (Next(First(L)==First(L))
            {
                P=First(L);
                First(L)= NULL;

            }
            else
            {
                P=Next(Prec);
                if (Next(Prec)==First(L))
                {
                    First(L)=Next(First(L));
                }
                Next(Prec)= Next(P);
                dealokasi(P);
            }



    }

    //----------------------------------------
}

