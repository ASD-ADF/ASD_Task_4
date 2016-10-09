#include "list.h"

void createList(List &L) {
    /**
    * FS : First(L) diset Nil
    */
    //-------------your code here-------------
        First(L) = NULL;
        Last(L) = NULL;
    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, Next elemen = Nil
    */

    address P;
    //-------------your code here-------------
        P = new elmlist;
        Info(P) = x;
        Next(P) = NULL;
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
        if (First(L) = NULL)
        {
            First(L) = P;
            Next(P) = First(L);
        }
        else
        {
            address Q = First(L);
            while (Next(Q) != First(L))
            {
                Q = Next(Q);
            }
            Next(P) = First(L);
            Next(Q) = P;
            Prev(P) = Q;
            Prev(First(L)) = P;
            First(L) = P;
        }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
        if (First(L) = NULL)
        {
            First(L) = P;
            Next(P) = First(L);
        }
        else
        {
            address Q = First(L);
            while (Next(Q) != First(L))
            {
                Q = Next(Q);
            }
            Next(P) = First(L);
            Next(Q) = P;
            Prev(P) = Q;
            Prev(First(L)) = P;
    //----------------------------------------
        }
}

address findElm(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */
    address P;
    //-------------your code here-------------
    if (First(L) != NULL)
    {
        P = First(L);
        while ((Next(P)!= First(L)) && (Info(P).ID != x.ID))
        {
            P = Next(P);
        }
        if (Info(P).ID == x.ID)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if(First(L) != NULL)
        {
            address Q;
            P = First(L);
            First(L) = Next(P);
            Q = P;
            while ((Next(Q)) != P)
            {
                Q = Next(Q);
            }
            Next(Q) = First(L);
            Next(P) = NULL;
        }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if(Next(First(L)) == First(L))
        {
            P = First(L);
            Next(P) = NULL;
            First(L) = NULL;
        }
        else
        {
            address Q = First(L);
            while (Next(Next(Q)) != First(L))
            {
                Q = Next(Q);
            }
            P = Next(Q);
            Next(Q) = First(L);
            Next(P) = NULL;
        }
    //----------------------------------------
}

void insertAfter(List &L,address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
        address Q = First(L);
    for (int i = 1; i <= countElm(L); i++)
        {
            if (Info(Prec).ID == Info(Q).ID)
            {
                break;
            }
            Q = Next(Q);
        }
    Prec = Q;
    Next(Q) = Next(Prec);
    Prev(Q) = Prec;
    Prev(Next(P)) = P;
    Next(Prec) = P;
    //----------------------------------------
}

void deleteAfter(List &L,address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        address Q = First(L);
    for (int i = 1; i <= countElm(L); i++)
    {
        if (Info(Prec).ID == Info(Q).ID)
        {
            break;
        }
        Q = Next(Q);
    }
    Prec = Q;
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
    Prev(P) = NULL;
    //----------------------------------------
}

int countElm(List L)
{
    int num = 0;
    if (First(L) == NULL) return 0;
    address O = First(L);
    do
    {
        num++;
        O = Next(O);
    }while(O != First(L));
    return num;
}
