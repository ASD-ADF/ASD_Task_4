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
    adr Q = First(L);
    do
    {
        cout<<"Name     : "<<Info(Q).name<<endl;
        cout<<"ID       : "<<Info(Q).ID<<endl;
        cout<<"Location : "<<Info(Q).location<<endl;
        Q = Next(Q);
    }while(Q != First(L));
}


void playSong(adr P){
	/**
	* PR : memainkan lagu yang ditunjuk oleh pointer P
	*/

    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}


void playNext(adr &P){
	/**
	* PR : memainkan file lagu pada elemen setelah P
	* FS : P menunjuk next lagu dan lagu dimainkan
	*/
    P = Next(P);
    playSong(P);
}


void playPrev(adr &P){
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
    adr P = L.first;
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


    //----------------------------------------

}

void playRepeat(List &L, int n){
	/**
	* PR : memainkan seluruh lagu di dalam list
	*      dari lagu pertama hingga terakhir sebanyak n kali
	*/
	//-------------your code here-------------
    adr P = L.first;
    int totData = countElm(L);
    playSong(P);
    for(int i=1; i < totData*n; i++)
    {
        playNext(P);
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
    int number;
	adr P;
    cout <<"Pilih Posisi    : 1. First"<<endl
             <<"                  2. After"<<endl
             <<"                  3. Last"<<endl
             <<"Masukkan Posisi : ";cin>>number;
        if (number == 1) {
            deleteFirst(L,P);
            cout << "Lagu Berhasil Dihapus";
        }
        else if (number == 2) {
            adr R = new elmlist;
            cout << "Masukkan ID Element Sebelum Element Yang Akan Dihapus : ";
            cin >> R->info.ID;
            deleteAfter(L,P,R);
            cout << "Lagu Berhasil Dihapus";
        }
        else if (number == 3) {
            deleteLast(L,P);
            cout << "Lagu Berhasil Dihapus";
        }
        else {
            cout <<"Menu Salah"<<endl;
        }
    //----------------------------------------
}
