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
    int i = 0;
    address Q;
    address P = first(L);
    do{
        i = i + 1;
        P = next(P);
    }while(P !=first(L));
    int random;
    while(i > 0){
        P = first(L);
        random = randomInt(i);
        int k = 1;
        while(k != random ){
            P = next(P);
            k = k + 1;
        }
        deleteAfter(L, prev(P), Q);
        insertLast(L, Q);
        i = i - 1;
    }


    //----------------------------------------
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------
    int i = 0;
    while(i < n){
        address P = first(L);
        do{
            playMusic(P);
            P = next(P);
        }while(P != first(L));
        i = i + 1;
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

    if(first(L) == NULL){
        cout<<"tidak ada lagu"<<endl;
    }else{
        address P = findElmByID(L, x);
        if(P != NULL){
            address Prec = prev(P);
            deleteAfter(L, Prec, P);
            deallocate(P);
        }else{
            cout<<"ID not found"<<endl;
        }
    }

    //----------------------------------------

}
