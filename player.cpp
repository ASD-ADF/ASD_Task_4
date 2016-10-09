#include "player.h"
#include <string.h>
#include <cstdlib>

void inputNewSong(infotype &x){
	/**
	* PR : meminta input user untuk mengisi nama dan lokasi file
	* FS : infotype x terisi nama dan lokasi file
	*/

    cout<<"input name song (.wav) : ";
    cin>>x.name;
//    string z=x.name;
//    int a = strlen(z);
//    if x.name[a-3] == "."
//        if x.name[a-2] == "w"
//            if x.name[a-1] == "a";
//    //if if { alokasi-insert}

    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-"){x.location="";}
}


void printInfo(List L){
	/**
	* PR : menampilkan informasi ID, nama, dan lokasi file
	*/

    address Q = First(L);
    do {
        if (Q != NULL) {
            cout << "-----------------------------------------"<<endl;
            cout<<"name : "<<Info(Q).name<<endl
                <<"ID: "<<Info(Q).ID<<endl
                <<"location: "<<Info(Q).location<<endl;
            cout << "-----------------------------------------"<<endl;
            Q = Next(Q);
        } else {
            cout << "List Kosong" << endl;
        }
    } while(Q != First(L));
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
	List List1;
	List List2;
    address P=L.first;
    int a = rand();
    while(L.first != NULL){
        P=L.first;
        int a= rand();
        for (int i = 1; i<=a; i++) { //1-a {
            P=Next(P);
        }
//        deletebyID(P);
        insertFirst(List2,P);
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
    address P = L.first;
    for (int i = 1; i<n; i++){
        while (P != L.first) {
            playSong(P);
            P = Next(P);
        }
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
    address P = L.first;
    infotype x;
    cout << "ID Lagu yang akan dihapus: ";
    cin >> x.ID;
    while (P != NULL){
        if(Info(P).ID == x.ID){
            dealokasi(P);
            cout << "Lagu ditemukan dan telah dihapus" << endl;
            printInfo(L);
        }
        P = Next(P);
    }
    //----------------------------------------
}
