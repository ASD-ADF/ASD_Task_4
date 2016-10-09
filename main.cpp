#include "player.h"

List L;
address P;
infotype x;
int index_ID;
int number, condition;

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
    } while (pil!=11);
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

    cout<<"1. input new "<<endl
        <<"2.  view list"<<endl
        <<"3.  play first song"<<endl
        <<"4.  play next "<<endl
        <<"5.  search song"<<endl
        <<"6.  play previous"<<endl
        <<"7.  play again the last song played"<<endl
        <<"8.  shuffle list"<<endl
        <<"9.  sort the song"<<endl
        <<"10. play repeat all"<<endl
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
        cout << "Masukkan id musik yang ingin diputar : "; cin>>x.ID;
        playSong(findElm(L, x));
        break;
    case 6:
        playPrev(P);
        break;
    case 7:
        playNext(P);
        break;

    case 8:
        shuffleList(L);
        break;

    case 9:
        cout << "Pilihan Sort : 1. Sort By ID"<<endl
             << "               2. Sort By Name"<<endl
             << "Pilihan      : ";cin >> condition;
        sortList(L,condition);
        break;

    case 10:
        int n;
        cout << "Masukkan Nilai Repeat-an : ";cin>>n;
        playRepeat(L, n);
        break;

    case 11:
        cout<<"Keluar"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }


    //----------------------------------------
}
