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
    do
    {
        cout<<"name    : "<<Info(Q).name<<endl
            <<"ID      : "<<Info(Q).ID<<endl;
        cout<<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
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
    address P = First(L);
    int numRand = rand() % 10 + 1;
    for (int i = 1; i <= numRand; i++){
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
    int maxmax, batas = 0;
    string maxmaxs, batass = "";
    List L2;
    createList(L2);
    P = First(L);
    int temp = 0;
    do{
        temp++;
        P = Next(P);
    }
    while (P != First(L));

    for (int i = temp; i != 0; i--){
        if (batas == 0 && batass == "")
        {
            do{
                x = Info(P);
                if (x.ID > batas && condition == 1){
                    batas = x.ID;
                    batass = x.name;
                }
                if (x.name > batass && condition == 2){
                    batas = x.ID;
                    batass = x.name;
                }
                P = Next(P);
            }
            while (P != First(L));
            x.ID = batas;
            x.name = batass;
            insertFirst(L2,alokasi(findElm(L,x)->info));
        }
        else{
            do{
                x = Info(P);
                if (x.ID > maxmax && x.ID < batas && condition == 1){
                    maxmax = x.ID;
                    maxmaxs = x.name;
                }
                if (x.name > maxmaxs && x.name < batass && condition == 2){
                    maxmax = x.ID;
                    maxmaxs = x.name;
                }
                P = Next(P);
            }
            while (P != First(L));{
                batas = maxmax;
                batass = maxmaxs;
                x.ID = batas;
                if (batas != 0)
                    insertFirst(L2,alokasi(findElm(L,x)->info));
                maxmax = 0;
                maxmaxs = "";
            }
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
    address P = First(L);
    int totData = countElm(L);
    playSong(P);
    for (int i=1; i < totData*n; i++){
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
    int numb;
    address P;
    cout<<" Pilih Posisi        : 1. First"<<endl
        <<"                       2. After"<<endl
        <<"                       3. Last"<<endl;
    cout<<"Masukkan Posisi      : ";cin>>numb;
        if (numb == 1){
            deleteFirst(L,P);
            cout<<"Lagu Telah Dihapus";
        }
        else if (numb == 2){
            address R = new elmlist;
            cout<< "Masukkan ID element sebelum element yang akan dihapus : ";
            cin>>Info(R).ID;
            deleteAfter(L,P,R);
            cout<<"Lagu Telah Dihapus";
        }
        else if (numb == 3){
            deleteLast(L,P);
            cout<<"Lagu Telah Dihapus";
        }else{
            cout<<"Input Menu Error"<<endl;
        }
    //----------------------------------------

}
