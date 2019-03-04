#include "player.h"
#include <ctime>

int randomInt(int  max_int)
{
    /** YOU DON'T NEED TO MODIFY THIS */
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L)
{
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    * YOU DON'T NEED TO MODIFY THIS
    */

    address Q = first(L);
    do
    {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    }
    while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P)
{
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    * YOU DON'T NEED TO MODIFY THIS
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L)
{
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    List L1;
    createList(L1);
    int i = 0;
    address P = first(L);
    do{
        if ( i % 2 == 0){
            insertFirst(L1, P);
        }
        else{
            insertLast(L1, P);
        }
        i++;
        P = next(P);
    }
    while(P!= first(L));
    address Q = first(L1);
    do
    {
        playMusic(Q);
        Q = next(Q);
    }
    while(Q!=first(L1));
}

void playRepeat(List &L, int n)
{
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    address P = first(L);
    for (int i = 0; i < n; i++)
    {
        do
        {
            playMusic(P);
            P = next(P);
        }
        while(P!=first(L));
    }
}

void deleteMusicByID(List &L, infotype x)
{
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    if (first(L) == NULL)
    {
        cout<<"empty list \n";
    }
    else
    {
        address P = first(L);
        while(next(P) != first(L) && info(P).ID != x.ID)
        {
            P = next(P);
        }
        if (info(P).ID == x.ID)
        {

            if (next(P) == first(L))
            {
                next(P) = NULL;
                prev(P) = NULL;
            }
            else if(P == first(L))
            {
                address Q = prev(first(L));
                next(Q) = next(first(L));
                prev(next(first(L))) = Q;
                first(L) = next(first(L));
                next(P) = NULL;
                prev(P) = NULL;
            }
            else
            {
                address Q = prev(P);
                next(Q) = next(P);
                prev(next(P)) = Q;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}

