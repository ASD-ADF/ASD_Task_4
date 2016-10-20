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
    x.ID = 1;
    x.location = "";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = 2;
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
    } while (pil!=5);
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


    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next "<<endl
        <<"5. play previous"<<endl
        <<"6. Play again the last song played"<<endl
        <<"7. Shuffle list"<<endl
        <<"8. Sort the song"<<endl
        <<"9. Play repeat"<<endl
        <<"10. Search"<<endl
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
        inputNewSong(x);
        x.ID = index_ID++;
        P = alokasi(x);
        insertFirst(L,P);
        break;
    case 2:
        printInfo(L);
        break;
    case 3 :
        P = First(L);
        playSong(P);
        break;
    case 4:
        playNext(P);
        break;
    case 5:
        playPrev(P);
        break;
    case 6:
        if(P!=NULL)
            playSong(P);
        else
            cout<<"Belum memutar lagu"<<endl;
    case 7:
        int sortby;
        sortby = 0;
        cout<<"Sory By :\n 1.ID \n 2. Name \n Input= ";
        cin>>sortby;
        while(sortby!=1&&sortby!=2)
        {
            sortList(L,sortby);
        }
        break;
    case 8 :
        shuffleList(L);
        break;
    case 9:
        int n;
        n=NULL;
        cout<<"Banyak pengulangan = ";
        cin>>n;
        playRepeat(L,n);
        n=NULL;
        break;
    case 10;
        cout <<"Judul ID lagu (.wav) : ";
            cin >> x.ID;
            P = findElm(L,x);
            cout <<"ID Lagu    : "<<Info(P).ID<<endl;
            cout <<"Judul Lagu : "<<Info(P).name<<endl;
            cout <<"Lokasi     : "<<Info(P).location<<endl;
            playSong(P);
            cout
                 <<endl;
    case 11:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }


    //----------------------------------------
}
