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

    //-------------your code here-------------

    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. search song"<<endl
        <<"4. sort the song"<<endl
        <<"5. shuffel list"<<endl
        <<"6.  Play first song"<<endl
        <<"7.  Play again the last song played"<<endl
        <<"8.  Play next "<<endl
        <<"9.  Play Prev"<<endl
        <<"10. Play Repeat All"<<endl
        <<"11. Delete Song"<<endl
        <<"12. Exit"<<endl;
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
        cout<<"masukkan judul lagu (.wav)"<<endl;
	cin >> x.name;
	P = findElm(L,x);
	cout <<"Judul Lagu : "<<Info(P).name<<endl;
        cout <<"Lokasi     : "<<Info(P).location<<endl;
        playSong(P);
        cout <<endl
        <<endl;	
        break;
    case 4:
        cout <<"1. Sort byID"<<endl
             <<"2. Sort byName"<<endl
             <<"sorting berdasarkan : ";
        cin >> pil;
        cout << endl;
        if (pil == 1 or pil == 2)
        {
            sortList(L,pil);
            cout <<endl;
        }
        else
        {
            cout <<"input salah";
        }
       break;
     case 5:
        shuffleList(L);
	printInfo(L);
        break;
	case 6:
        P = First(L);
        playSong(P);
        break;
     case 7:
        playSong(P);
        break;
     case 8:
        playNext(P);
        break;
     case 9:
        playPrev(P);
        break;
     case 10:
        cout <<"repeat sebanyak : ";
        cin >> n;
        playRepeat(L, n);
        break;
     case 11:
        deleteSong(L);
        break;
     case 12:
        cout<<"thank you"<<endl;
        break;
     default :
        cout<<"wrong input"<<endl;
    }


    //----------------------------------------
}
