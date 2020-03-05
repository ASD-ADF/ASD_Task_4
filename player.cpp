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
    if(first(L)!=NULL){
        do {
            cout<<"name    : "<<info(Q).name<<endl
                <<"ID      : "<<info(Q).ID<<endl
                <<"location: "<<info(Q).location<<endl;
            Q = next(Q);
        } while(Q!=first(L));
    }else{
        cout<<"List Kosong"<<endl;
    }
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

    cout<<"UNDER MAIN TENIS"<<endl;
    address P=first(L);
    int i =0;
    do{
        P=next(P);
        i++;
    }while(P!=first(L));

    address Q,R;
    for(int j=1; j<=i ; j++){
        int acak = randomInt(j);
        int k = 1;
        Q = first(L);
        do{
            Q = next(Q);
            k++;

        }while (Q != first(L) && k < acak);
        deleteAfter(L,prev(Q),R);
        insertFirst(L,R);
    }
    cout<<"Random Done"<<endl;
    //----------------------------------------
}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //------------- YOUR CODE HERE -------------

    cout<<"UNDER MAIN TENIS"<<endl;
    for(int i=0; i<n; i++){
        address P = first(L);
        do{
            playMusic(P);
            P=next(P);
        }while(P!=first(L));
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

    address R;
    address ElmygDicari=findElmByID(L,x);
    cout<<info(ElmygDicari).ID<<endl;
    if (ElmygDicari == first(L)){
        deleteFirst(L, R);
        deallocate(R);
    }else if(ElmygDicari!=NULL){
        deleteAfter(L, prev(ElmygDicari), R);
        deallocate(R);
    }
    //----------------------------------------

}
