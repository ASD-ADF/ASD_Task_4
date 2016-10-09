#include "player.h"

void inputNewSong(infotype &x){
	/**
	* PR : meminta input user untuk mengisi nama dan lokasi file
	* FS : infotype x terisi nama dan lokasi file
	*/

    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-"){x.location="";}
}


void printInfo(List L){
	/**
	* PR : menampilkan informasi ID, nama, dan lokasi file
	*/

    address Q = first(L);
    do
    {
        if (Q != Nil)
        {
            cout<<"name : "<<info(Q).name<<endl
                <<"ID: "<<info(Q).ID<<endl;
            cout<<"location: "<<info(Q).location<<endl;
            Q = next(Q);
        }
        else
        {
            cout << "list Kosong" << endl << endl;
        }
    }
    while(Q != first(L));
}



void playSong(address P){
	/**
	* PR : memainkan lagu yang ditunjuk oleh pointer P
	*/

    string filename = info(P).location+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}


void playNext(address &P){
	/**
	* PR : memainkan file lagu pada elemen setelah P
	* FS : P menunjuk next lagu dan lagu dimainkan
	*/
    P = Next(P);
    playSong(P);
}


void playPrev(address &P){
	/**
	* PR : memainkan file lagu pada elemen sebelum P
	* FS : P menunjuk prev lagu dan lagu dimainkan
	*/
	//-------------your code here-------------
    P = Prev(P);
    playSong(P);

    //----------------------------------------

}

void shuffleList(List &L){
	/**
	* PR : mengacak isi (elemen) dari list L
	* FS : isi (elemen) dari list teracak
	*/
	//-------------your code here-------------
    address P,Q;
    P = L.first;
    int counter = 0;
    do
    {
        counter++;
        P = P->next;
    }
    while(P!=L.first);
    List L2;
    infotype x;
    createList(L2);
    for (int i = counter; i>0; i--)
    {
        x.ID = 0;
        while(x.ID == 0)x.ID = rand() % counter;
        Q = findElm(L,x);
        if (findElm(L2,x) == NULL)
        {
            insertFirst(L2,alokasi(findElm(L,x)->info));
        }
    }
    P = L.first;
    do
    {
        x = info(P);
        Q = findElm(L2,x);
        if (Q == NULL)
        {
            insertFirst(L2,alokasi(x));
        }
        P = P->next;
    }
    while(P!=L.first);
    L = L2;


    //----------------------------------------
}

void sortList(List &L, int condition){
	/**
	* PR : mengurutkan isi (elemen) dari list L berdasarkan kondisi
	* FS : isi (elemen) dari list L terurut
	*      jika kondisi = 1, sort by ID
	*      jika kondisi = 2, sort by nama
	*/
	//-------------your code here-------------


    //----------------------------------------

}

void playRepeat(List &, int n){
	/**
	* PR : memainkan seluruh lagu di dalam list
	*      dari lagu pertama hingga terakhir sebanyak n kali
	*/
	//-------------your code here-------------


    //----------------------------------------
}

void deleteSong(List &L){
	/**
	* IS : list L mungkin kosong
	* PR : menerima input user untuk ID lagu yang ingin dihapus
	*      jika ID lagu ditemukan, hapus (dealokasi) lagu dari list
	* FS : elemen dengan ID yang dicari didealokasi
	*/
	//-------------your code here-------------


    //----------------------------------------

}
