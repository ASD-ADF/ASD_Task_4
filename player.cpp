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
    List L2;
    createList(L2);
    address P = NULL;
    while (first(L) != NULL) {
        deleteFirst(L,P);
        int x = randomInt(15);
        cout<<x<<endl;
        if (x > 5) {
            insertFirst(L2,P);
        } else {
            insertLast(L2,P);
        }
    }
    L = L2;
    //----------------------------------------
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------
    for (int i = 0; i < n; i++) {
        address P = first(L);
        while (next(P) != first(L)) {
            playMusic(P);
            P = next(P);
        }
        if (next(P) == first(L)) {
            playMusic(P);
            P = next(P);
        }
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
    if (first(L) != NULL) {
        address P = findElmByID(L,x);
        cout<<info(P).ID<<endl;
        if (P != NULL) {
            if (P == first(L)) {
                deleteFirst(L,P);
            } else if (next(P) == first(L)) {
                deleteLast(L,P);
            } else {
                address Prec = prev(P);
                deleteAfter(L,Prec,P);
            }
            deallocate(P);
        } else {
            cout<<"music not found"<<endl;
        }
    }
    //----------------------------------------

}
