#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
        First(L) = NULL;

    //----------------------------------------
}

address alokasi(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
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
       	if (First(L) == NULL && Last(L) == NULL)
      {
          First(L) = P;
          Last(L) = P;
          Next(P) = P;
          Prev(P) = P;
      }
      else
      {
          Next(P) = First(L);
          Prev(P) = Last(L);
          Next(Last(L)) = First(L);
          Next(Last(L)) = P;
          First(L) = P;
          if (Next(First(L)) == Last(L))
          {
              Prev(Last(L)) = P;
          }
          First(L) = P;
          Next(Last(L)) = First(L);
      }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
        if (First(L) == NULL && Last(L) == NULL)
      {
          insertFirst(L,P);
      }
      else
      {
          Prev(P) = Prev(Last(L));
          Next(Prev(Last(L))) = P;
          Last(L) = P;
          Next(P) = First(L);
          Prev(First(L)) = Last(L);

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
          P = First(L);
          x = Info(P);
            if (Next(P) && Prev(P) == NULL)
            {
                cout<<"list masih kosong";
            }
            else
            {
                while ((Next(P) != First(L)) && (Info(P).ID != x.ID))
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
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if (Next(P) && Prev(P) == NULL)
            {
                cout<<"list masih kosong";
            }
        else
        {
            P = First(L);
            First(L) = Next(First(L));
            Next(Last(L)) = Prev(First(L));
            Prev(First(L)) = Next(Last(L));
            Next(P) = NULL;
            Prev(P) = NULL;
        }


    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        if (Next(P) && Prev(P) == NULL)
            {
                cout<<"list masih kosong";
            }
        else
        {
            P = Last(L);
            Last(L) = Prev(Last(L));
            Prev(First(L)) = Next(Last(L));
            Next(Last(L)) = Prev(First(L));
            Next(P) = NULL;
            Prev(P) = NULL;
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
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Prev(Next(Prec)) = P;
        Next(Prec) = P;

    //----------------------------------------

}
void deleteAfter(address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
        Next(Prec) = Next(P);
        Prev(Next(P)) = Prec;
        Prev(P) = NULL;
        Next(P) = NULL;
    //----------------------------------------
}

