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

    address Q = First(L);
    while(Q != NULL)
    {
        cout<<"name : "<<Info(Q).name<<endl;
        cout<<"ID: "<<Info(Q).ID<<endl;
        cout<<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
    }
}


void playSong(address P){
	/**
	* PR : memainkan lagu yang ditunjuk oleh pointer P
	*/

    string filename = Info(P).location+Info(P).name;
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
    address P = L.first;
    int numRand = rand() % 10 + 1;
    for(int i=1; i <= numRand; i++)
    {
        P = Next(P);
    }
    playSong(P);

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
    address P;
    infotype x;
    int maxmax,batasi = 0;
    string maxmaxs,batass = "";
    List L2;
    createList(L2);
    P = L.first;
    int counter = 0;
    do
    {
        counter++;
        P = P->next;
    }
    while(P!=L.first);

    for (int i = counter; i!=0; i--)
    {
        if (batasi == 0 && batass == "")
        {
            do
            {
                x = P->info;
                if (x.ID > batasi && condition == 1)
                {
                    batasi = x.ID;
                    batass = x.name;
                }
                if (x.name > batass && condition == 2)
                {
                    batasi = x.ID;
                    batass = x.name;
                }
                P = P->next;
            }
            while(P!=L.first);
            x.ID = batasi;
            x.name = batass;
            insertFirst(L2,alokasi(findElm(L,x)->info));
        }
        else
        {
            do
            {
                x = P->info;
                if (x.ID > maxmax && x.ID < batasi && condition == 1)
                {
                    maxmax = x.ID;
                    maxmaxs = x.name;
                }
                if (x.name > maxmaxs && x.name < batass && condition == 2)
                {
                    maxmax = x.ID;
                    maxmaxs = x.name;
                }
                P = P->next;
            }
            while(P!=L.first);

            batasi = maxmax;
            batass = maxmaxs;
            x.ID = batasi;
            if (batasi != 0)
                insertFirst(L2,alokasi(findElm(L,x)->info));
            maxmax = 0;
            maxmaxs = "";
        }
    }
    L = L2;

    //----------------------------------------
}
void playRepeat(List &L, int n){
	/**
	* PR : memainkan seluruh lagu di dalam list
	*      dari lagu pertama hingga terakhir sebanyak n kali
	*/
	//-------------your code here-------------
    address P;
    P = First(L);
    for(int i = 0; i<n; i++)
    {
        do
        {
            playSong(P);
            P = Next(P);
        }
        while(P != First(L));
    }
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
    infotype x;
    int isi;
    x.ID = isi;
    address P;

    P = findElm(L,x);
    if (P != NULL)
    {
        deleteAfter(L,Prev(P),P);
    }
    else
    {
        cout << "Isi Tidak Ditemukan" << endl;
    }

    //----------------------------------------

}
