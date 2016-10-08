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
        if (Q != NULL){
        cout<<"name : "<<Info(Q).name<<endl
        <<"ID: "<<Info(Q).ID<<endl;
        cout<<"location: "<<Info(Q).location<<endl;
        Q = next(Q);
        }
        else
        {
            cout << "list Kosong" << endl << endl;
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
    _sleep(50); //delay 1 second
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
    do{
        counter++;
        P = P->next;
    }while(P!=L.first);
    List L2;
    infotype x;
    createList(L2);
    for (int i = counter;i>0;i--){
            x.ID = 0;
            while(x.ID == 0)x.ID = rand() % counter;
            Q = findElm(L,x);
            if (findElm(L2,x) == NULL){
                insertFirst(L2,alokasi(findElm(L,x)->info));
            }
    }
    P = L.first;
    do{
        x = info(P);
        Q = findElm(L2,x);
        if (Q == NULL){
            insertFirst(L2,alokasi(x));
        }
        P = P->next;
    }while(P!=L.first);
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
	address P,Q;
	infotype x;
	int maxmax,batasi = 0;
	string maxmaxs,batass = "";
    List L2;
    createList(L2);
    P = L.first;
    int counter = 0;
    do{
        counter++;
        P = P->next;
    }while(P!=L.first);

    for (int i = counter;i!=0;i--){
    if (batasi == 0 && batass == ""){
        do{
            x = P->info;
            if (x.ID > batasi && condition == 1){
                batasi = x.ID;
                batass = x.name;
            }
            if (x.name > batass && condition == 2){
                batasi = x.ID;
                batass = x.name;
            }
            P = P->next;
        }while(P!=L.first);
        x.ID = batasi;
        x.name = batass;
        insertFirst(L2,alokasi(findElm(L,x)->info));
    }
    else
    {
        do{
            x = P->info;
            if (x.ID > maxmax && x.ID < batasi && condition == 1){
                maxmax = x.ID;
                maxmaxs = x.name;
            }
            if (x.name > maxmaxs && x.name < batass && condition == 2){
                maxmax = x.ID;
                maxmaxs = x.name;
            }
            P = P->next;
        }while(P!=L.first);

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
	P = L.first;
    for(int i = 0;i<n;i++){
        do{
            playSong(P);
            P = P->next;
        }
        while(P != L.first);
    }

    //----------------------------------------
}


void deleteSong(List &L,int isi, address &P)
{
    //-------------your code here-------------
    infotype x;
    x.ID = isi;

    P = findElm(L,x);
    if (P != NULL)
    {
        deleteAfter(L,P->prev,P);
    }
    else
    {
        cout << "Tidak ditemukan" << endl;
    }
    //----------------------------------------
}



/**
contoh yang salah
void sortList(List &L, int condition){

	//-------------your code here-------------
	address P;
	infotype x;
	int maxmax = 0;
    List L2;
	if (condition == 1){
    createList(L2);
    P = L.first;
        do{
        x = P->info;
        if (x.ID > maxmax)
            maxmax=x.ID;
        P->next;
        }while(P!=L.first);

        cout << maxmax;
        for(int i = maxmax;i>0;i--){
        x.ID = i;
        P = findElm(L,x);
        if (P!=NULL)
        insertFirst(L2,alokasi(findElm(L,x)->info));
        }
    L = L2;
    }



    //----------------------------------------

}*/
/**

void sortList(List &L, int condition){

	//-------------your code here-------------
	address P,Q,batas;
	infotype x;
	int maxmax = 0;
	string maxmaxs = "";
    List L2;
    createList(L2);
   while(L.first!=NULL){
        P = L.first;
        if (P!=NULL){
        do{
                cout << "X";
            x = P->info;
            if (x.ID > maxmax && condition == 1){
                maxmax=x.ID;
                maxmaxs = x.name;
            }
            if (x.name > maxmaxs && condition == 2){
                maxmaxs = x.name;
                maxmax=x.ID;
            }
            P = P->next;
        }while(P!=L.first);

        cout << "Delete " << maxmaxs << endl;
        deleteSong(L,maxmax,P);

        if (P!=NULL){
        insertLast(L2,alokasi(P->info));
        cout << "Insert " << P->info.name << endl;
        dealokasi(P);
        }
        else
        cout << "NULL EUY" << endl;
        maxmax = 0;
        maxmaxs = "";
    }
   }

 L = L2;
    cout << "sorted" << endl;


    //----------------------------------------

}*/
/**

void shuffleList(List &L){
	//-------------your code here-------------
    address P,Q;
    P = L.first;
    int counter = 0;
    do{
        counter++;
        P = P->next;
    }while(P!=L.first);
    List L2;
    infotype x;
    createList(L2);
    for (int i = counter;i>0;i--){
            x.ID = 0;
            while(x.ID == 0)x.ID = rand() % counter;
            Q = findElm(L,x);
            if (findElm(L2,x) == NULL){
                insertFirst(L2,alokasi(findElm(L,x)->info));
            }
    }
    P = L.first;
    do{
        x = info(P);
        Q = findElm(L2,x);
        if (Q == NULL){
            insertFirst(L2,alokasi(x));
        }
        P = P->next;
    }while(P!=L.first);
    L = L2;


    //----------------------------------------
}*/
