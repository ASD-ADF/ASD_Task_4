#include "player.h"
/* nim : 1301140057 */

void inputNewSong(infotype &x)
{
    /**
    * PR : meminta input user untuk mengisi nama dan lokasi file
    * FS : infotype x terisi nama dan lokasi file
    */

    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-")
    {
        x.location="";
    }
}


void printInfo(List L)
{
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = First(L);

    cout <<endl;

    do
    {
        cout<<"ID       : "<<Info(Q).ID<<endl;
        cout<<"name     : "<<Info(Q).name<<endl;
        cout<<"location : "<<Info(Q).location<<endl;
        Q = Next(Q);
    }
    while(Q != First(L));
}


void playSong(address P)
{
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}


void playNext(address &P)
{
    /**
    * PR : memainkan file lagu pada elemen setelah P
    * FS : P menunjuk next lagu dan lagu dimainkan
    */
    P = Next(P);
    playSong(P);
}


void playPrev(address &P)
{
    /**
    * PR : memainkan file lagu pada elemen sebelum P
    * FS : P menunjuk prev lagu dan lagu dimainkan
    */
    //-------------your code here-------------
    P = Prev(P);
    playSong(P);
    //----------------------------------------

}

void shuffleList(List &L)
{
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------
    address P, Q;
    int counter = 0,x;

    Q = First(L);

    do
    {
        counter = counter + 1;
        Q = Next(Q);
    }
    while (Q != First(L));

    srand((unsigned)time(NULL));

    x = rand()%counter+1;

    Q = First(L);
    for (int i=1; i<x; i++)
    {
        Q = Next(Q);
    }
    deleteAfter(L,Q,P);
    insertFirst(L,P);

    //----------------------------------------
}

void sortList(List &L, int condition)
{
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan kondisi
    * FS : isi (elemen) dari list L terurut
    *      jika kondisi = 1, sort by ID
    *      jika kondisi = 2, sort by nama
    */
    //-------------your code here-------------
    address P,Q;
    music x;
    int counter = 0;

    P = First(L);
    do
    {
        counter = counter + 1;
        P = Next(P);
    }
    while (P != First(L));

    if (condition == 1)
    {
        for (int i=0; i<=counter; i++)
        {
            for (int j=i+1; i<=counter; i++)
            {
                P = First(L);
                Q = Next(P);
                do
                {
                    if (Info(P).ID > Info(Q).ID)
                    {
                        x = Info(P);
                        Info(P) = Info(Q);
                        Info(Q) = x;
                    }
                    P = Next(P);
                    Q = Next(Q);
                }
                while (Q != First(L));
            }
        }
        printInfo(L);
    }
    else if (condition == 2)
    {
        printInfo(L);
    }

    //----------------------------------------

}

void playRepeat(List &L, int n)
{
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------
    address P;

    P = First(L);

    for (int i=1; i<=n; i++)
    {
        playSong(P);
        P = Next(P);
        do
        {
            playSong(P);
            P = Next(P);
        }
        while(P != First(L));
    }
    //----------------------------------------
}

void deleteSong(List &L)
{
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (dealokasi) lagu dari list
    * FS : elemen dengan ID yang dicari didealokasi
    */
    //-------------your code here-------------
    address P,Q;
    infotype pil;

    printInfo(L);
    cout <<endl;
    cout <<"Masukan ID yang ingin dihapus : ";
    cin >> pil.ID;

    P = findElm(L,pil);
    P = Prev(P);
    deleteAfter(L,P,Q);
    dealokasi(Q);

    //----------------------------------------

}
