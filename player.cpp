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

    if (first(L) != NULL)
    {
        int n = 1;
        address N = first(L);
        while (next(N) != first(L)) {
            N = next(N);
            n++;
        }

        int x,y;
        x = randomInt(n);
        address Prec,P;
        for (int i = 0; i < n; i++) {
            Prec = first(L);
            y = randomInt(i+1);
            for (int j = 0; j < y; j++) {
                Prec = next(Prec);
            }
            deleteAfter(L,Prec,P);
            insertFirst(L,P);
        }
    }
    //----------------------------------------
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------

    address P;
    int i = 1;
    while (i < n+1)
    {
        P = first(L);
        playMusic(P);
        P = next(P);
        while (P != first(L))
        {
            playMusic(P);
            P = next(P);
        }
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
    address P = findElmByID(L,x);

    if (P == first(L))
    {
        deleteFirst(L,P);
    }
    else if (next(P) == first(L))
    {
        deleteLast(L,P);
    }
    else if (next(P) != P)
    {
        address Prec = next(P);
        deleteAfter(L,Prec,P);
    }
    //----------------------------------------

}
