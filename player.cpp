#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    /** YOU DON'T NEED TO MODIFY THIS */
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    * YOU DON'T NEED TO MODIFY THIS
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    * YOU DON'T NEED TO MODIFY THIS
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //------------- YOUR CODE HERE -------------

    address P = L.first,Q ;
    int i,k ;
    i = 0 ;
    do{
        P = P->next ;
        i++ ;
    }
    while (P != first(L)) ;
    while (i > 0){
        P = L.first ;
        k = randomInt(i) ;
        while (k != 0)
        {
            P = P->next ;
            k-- ;
        }
        Q = P ;
        deleteAfter(L,P->prev,Q) ;
        insertFirst(L,Q) ;
        i-- ;
    }
    //----------------------------------------
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------
    address P=L.first;
    int i=0;
    while (i<n){
        do{
            playMusic(P);
            P= P->next;
        }
        while(P != L.first);
        i++;
    }

    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //------------- YOUR CODE HERE -------------

    address P,Q;
    P=findElmByID(L,x);
    if (P == L.first){
        deleteFirst(L,P);
        deallocate(P);
    }else if (P == L.first->prev){
        deleteLast(L,P);
        deallocate(P);
    }else if (P!=NULL){
        Q=P->prev;
        deleteAfter(L,Q,P);
        deallocate(P);
    }

    //----------------------------------------

}
