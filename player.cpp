#include "player.h"

void inputNewSong(infotype &x){
	/**
	* PR : meminta input user untuk mengisi nama dan lokasi file
	* FS : infotype x terisi nama dan lokasi file
	*/

    cout<<"Input name song (.wav) : ";
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
        if (Q != NULL)
        {cout<<"name : "<<Info(Q).name<<endl
            <<"ID: "<<Info(Q).ID<<endl;
        cout<<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
        }
        else
        {
            cout<<"LIST KOSONG"<<endl<<endl;
        }
    }while(Q != First(L));
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
    address P,Q;
    P = L.first;
    int counter = 0;
    do
    {
        counter++;
        P=Next(P);
    }
    while(P!=First(L));
    List L2;
    infotype x;
    createList(L2);
    for (int i=counter;i>0;i--)
    {
        x.ID=0;
        while(x.ID == 0)x.ID=rand()%counter;
        Q=findElm(L,x);
        if (findElm(L2,x) == NULL)
        {
            insertFirst(L2,alokasi(findElm(L,x)->info));
        }
    }
    P=First(L);
    do
    {
        x=Info(P);
        Q=findElm(L2,x);
        if (Q==NULL)
        {
            insertFirst(L2, alokasi(x));
        }
        P = Next(P);
    }
    while (P!=L.first);
    L=L2;

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
    address P,Q;
    infotype x;
    int max1,batas1 = 0;
    string max2,batas2 = "";
    List L2;
    createList(L2);
    P=First(L);
    int counter = 0;
    do
    {
        counter++;
        P=Next(P);
    }
    while(P!=First(L));

    for (int i=counter;i!=0;i--)
    {
        if(batas1 == 0 && batas2 == "")
        {
            do
            {
                x=Info(P);
                if (x.ID>batas1 && condition == 1)
                {
                    batas1=x.ID;
                    batas2=x.name;
                }
                P=P->next;
            }
            while (P != L.first);
            x.ID=batas1;
            x.name=batas2;
            insertFirst(L2,alokasi(findElm(L,x)->info));
        }
        else
        {
            do
            {
                x = Info(P);
                if (x.ID > max1 && x.ID<batas1 &&condition ==1)
                {
                    max1=x.ID;
                    max2=x.name;
                }
                P=Next(P);
            }while (P!=First(L));

            batas1=max1;
            batas2=max2;
            x.ID=batas1;
            if (batas1 != 0)
                insertFirst(L2,alokasi(findElm(L,x)->info));
            max1=0;
            max2="";
        }
    }
    L=L2;

    //----------------------------------------

}

void playRepeat(List &L, int n){
	/**
	* PR : memainkan seluruh lagu di dalam list
	*      dari lagu pertama hingga terakhir sebanyak n kali
	*/
	//-------------your code here-------------
    address P;
    P=L.first;
    for(int i = 0; i<n;i++)
    {
        do
        {
            playSong(P);
            P=Next(P);
        }
        while(P != L.first);
    }

    //----------------------------------------
}

void deleteSong(List &L, int input, address &P){
	/**
	* IS : list L mungkin kosong
	* PR : menerima input user untuk ID lagu yang ingin dihapus
	*      jika ID lagu ditemukan, hapus (dealokasi) lagu dari list
	* FS : elemen dengan ID yang dicari didealokasi
	*/
	//-------------your code here-------------
    infotype x;
    x.ID = input;

    P=findElm(L,x);
    if(P!=NULL)
    {
        deleteAfter(L,Prev(P),P);
    }
    else
    {
        cout<<"LIST KOSONG"<< endl;
    }

    //----------------------------------------

}
