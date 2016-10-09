#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) diset Nil
    */
    //-------------your code here-------------
        First(L) = NULL;
        Last(L) = NULL;

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
    Prev(P) = NULL;

    //----------------------------------------
    return P;
}

void dealokasi(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    P = NULL;
	delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (First(L) == NULL) {
        First(L) = P;
        Last(L) = P;
        Prev(P) = Last(L);
        Next(P) = First(L);
    }else{
        Next(P) = First(L);
        Prev(First(L)) = P;
        First(L) = P;
        First(L) = P;
        Prev(First(L)) = Last(L);
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
    if (First(L) == NULL){
        insertFirst(L,P);
    }else{
        Next(Last(L)) = P;
        Prev(P) = Last(L);
        Last(L)= P;
        Next(Last(L)) = First(L);
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
    if (First(L) != NULL){
        P = First(L);
        while (Next(P) != First(L) && Info(P).ID != x.ID)
            P = Next(P);
        if (Info(P).ID == x.ID)
            return P;
        else
            return NULL;
    }
    else{
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
    if (First(L) == NULL) {
        cout << "List NULL / Kosong"<<endl;
    }
    else if (Next(First(L)) == NULL){
        P = First(L);
        Prev(P) = NULL;
        Next(P) = NULL;
        First(L) = NULL;
        Last(L) = NULL;
        dealokasi(P);
    }else{
        P = First(L);
        First(L) = Next(P);
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
        Next(P) = NULL;
        Prev(P) = NULL;
        dealokasi(P);
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
    if (Last(L) == First(L)){
        deleteFirst(L,P);
    }else{
        P = Last(L);
        Q = Prev(P);
        Next(Q) = First(L);
        Last(L) = Q;
        Prev(First(L)) = Q;

    }

    //----------------------------------------
}

void insertAfter(List &L, address Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    /*if (Prec == Last(L))
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Prev(Next(Prec)) = P;
    Next(Prec) = P;*/

    address Q = First(L);
    for (int i = 1; i <= countElm(L); i++){
        if (Info(Prec).ID == Info(Q).ID){
            break;
        }
        Q = Next(Q);
    }
    Prec = Q;
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Prev(Next(P)) = P;
    Next(Prec) = P;
    //----------------------------------------

}
void deleteAfter(List &L, address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    address Q = First(L);
    for (int i = 1; i <= countElm(L); i++){
        if (Info(Prec).ID == Info(Q).ID){
            break;
        }
        Q = Next(Q);
    }
    Prec = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
    Prev(P) = NULL;
    dealokasi(P);

    //----------------------------------------
}
int countElm(List L){
    int no = 0;
    if (First(L) == NULL) return 0;
    address Q = First(L);
    do{
        no++;
        Q = Next(Q);
    }while(Q != First(L));
    return no;
}
