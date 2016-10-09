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
    Info(P)=x;
    Next(P)=NULL;

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
    if (L.first == NULL){
        L.first = P;
        L.last = P;
        P->prev = L.last;
        P->next = L.first;
    }
    else{
        P->next=L.first;
        L.first->prev=P;
        L.first=P;
        L.first->prev=L.last;
        L.last->next=L.first;
    }

    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if(First(L)==NULL){
        insertFirst(L,P);
    }
    else{
        L.last->next=P;
        P->prev=L.last;
        L.last=P;
        L.last->next=L.first;
        L.first->prev= L.last;
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
        if (L.first != NULL){
        P=L.first;
        while(Next(P) != L.first && info(P).ID != x.ID)
            P=Next(P);
        
        if (info(P).ID -- x.ID)
            return P;
        else
            return NULL;
    }
    else {
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
      if (L.first == NULL){
        cout<<"List Kosong"<<endl;
    }
    else if (L.first->next==NULL){
        P=L.first;
        P->prev=NULL;
        P->next=NULL;
        L.first=NULL;
        L.last=NULL;
        dealokasi(P);
    else{
        P=L.first;
        L.first=P->next;
        L.last->next=L.first;
        L.first->prev=L.last;
        P->next=NULL;
        P->prev=NULL;
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
    if(L.first==NULL){
        cout<<"List Kosong"<<endl;
    }
    else if(L.first->next==NULL){
        P=L.first;
        P->prev=NULL;
        P->next=NULL;
        L.first=NULL;
        L.last=NULL;
        dealokasi(P);
    }
    else{
        P=L.first;
        L.first=P->next;
        L.last->next=L.first;
        L.first->prev=L.last;
        P->next=NULL;
        P->prev=NULL;
        dealokasi(P);
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
    address S=L.first;
    for (int i=1; i<= cpountElm(L); i++){
        if(Prec->info.ID==S->info.ID){
            break;
        }
        S=S->next;
    }
    Prec=S;
    
    P->next=Prec->next;
    P->prev=Prec;
    
    P->next->rev=P;
    Prec->next=P;

    //----------------------------------------

}
void deleteAfter(address Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    address S=L.first;
    for (int i=1; i<= countEm(L);i++){
        if(Prec->info.ID==S->info.ID){
            break;
        }
        S=S->next;
    }
    Prec=S;
    
    P=Prec->next;
    Prec->next=P->next;
    P->next=NULL;
    P->prev=NULL;
    dealokasi(P);
    //----------------------------------------
}

