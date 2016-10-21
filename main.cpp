#include "player.h"

List L;
address P;
infotype x;
int index_ID;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {

    index_ID = 0;
    createList(L);

	//-----------------------------------------
    // example of data initialization
	//-----------------------------------------
    index_ID++;
    x.ID = index_ID;
    x.location = "";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    index_ID++;
    x.ID = index_ID;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertFirst(L,P);

	//-----------------------------------------
	// memanggil menu utama
	//-----------------------------------------
    menu();


    return 0;
}


void menu() {
	/**
	* prosedur menu utama
	*/
    int pil;
    do {
        displayMenu();
        cin>>pil;
        runMenu(pil);
        cout<<endl;
    } while (pil != 11);
}


void displayMenu() {
	/**
	* prosedur menampilkan pilihan menu
	* TODO : modifikasi menu sehingga juga menampilkan menu:
	*        - search song
	*        - play previous
	*        - play again the last song played
	*        - shuffle list
	*        - sort the song
	*        - play repeat all
	*/

    //-------------your code here-------------

    cout<<"---MENU MP3---"<<endl
        <<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next "<<endl
        <<"5. play prev"<<endl
        <<"6. play again last song played"<<endl
        <<"7. sort List"<<endl
        <<"8. shuffle List"<<endl
        <<"9. play repeat"<<endl
        <<"10. Search "<<endl
        <<"11. exit"<<endl;
    cout<<"choose menu : ";



    //----------------------------------------
}

void runMenu(int menu) {
	/**
	* prosedur memproses input pilihan menu dari user
	* TODO : modifikasi menu sehingga juga memproses menu:
	*        - search song
	*        - play previous
	*        - play again the last song played
	*        - shuffle list
	*        - sort the song
	*        - play repeat all
	*/

    //-------------your code here-------------

    switch(menu) {
    case 1 :
        cout<<"input new song : "<<endl;
        index_ID++;
        x.ID = index_ID;
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        break;
    case 2:
        printInfo(L);
        break;
    case 3 :
        P = first(L);
        playSong(P);
        break;
    case 4:
        playNext(P);
        break;
    case 5:
        playPrev(P);
        break;
    case 6:
        if (P != Nil)
            playSong(P);
        else
            cout<< "Tidak ada lagu yang sudah di play"<<endl;
        break;
    case 7:
        int sortby;
        sortby = 0;
        cout<< "Sort By :\n 1.ID \n 2.Name \n Input= ";
        while(sortby!=1 && sortby!=2)cin>>sortby;
        sortList(L,sortby);
        break;
    case 8:
        shuffleList(L);
        break;
    case 9:
        int n;
        n = Nil;
        cout<<"Banyak pengulangan = ";
        cin>>n;
        playRepeat(L,n);
        n = Nil;
        break;
    case 11:
        cout<<"thank you :)"<<endl;
        break;
    case 10:
         cout <<"Judul ID lagu (.wav) : ";
            cin >> x.ID;
            P = findElm(L,x);
            cout <<"ID Lagu    : "<<info(P).ID<<endl;
            cout <<"Judul Lagu : "<<info(P).name<<endl;
            cout <<"Lokasi     : "<<info(P).location<<endl;
            playSong(P);
            cout
                 <<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }


    //----------------------------------------
}
