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
    address P = first(L);
    int i = 0;
    do
    {
        P = next(P);
        i++;
    }
    while (P != first(L));
    while ( i > 0)
    {
        P = first(L);
        int j = randomInt(i);
        while( j != 0)
        {
            P = next(P);
            j--;
        }
        address Q = P;
        deleteAfter(L, prev(P), Q);
        insertFirst(L, Q);
        i--;
    }
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------
    int i = 0;
    while (i<n){
        address P = first(L);
        do{
            playMusic(P);
            P=next(P);
        }while(P!=first(L));
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
    if(first(L) == NULL){
        cout<<"Music is Empty"<<endl;
    }else{
        address P = findElmByID(L, x);
        if(P != NULL){
            address Q = prev(P);
            deleteAfter(L, Q, P);
            deallocate(P);
        }else{
            cout<<"ID not found"<<endl;
        }
    }

}
