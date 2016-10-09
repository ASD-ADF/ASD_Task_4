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
        cin>>pil; cin.ignore();
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
    cout<<"1. Input New "<<endl
        <<"2. View List"<<endl
        <<"3. Play First song"<<endl
        <<"4. Play Next"<<endl
        <<"5. Search song"<<endl
        <<"6. Play previous"<<endl
        <<"7. Play again the last song played"<<endl
        <<"8. Shuffle list"<<endl
        <<"9. Sort the song"<<endl
        <<"10. Play repeat all"<<endl
        <<"11. Exit"<<endl;
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
    case 5 :
        cout << "Masukkan id musik yang ingin diputar : "; cin>>x.ID;
        playSong(findElm(L, x));
        break;
    case 6 :
        playPrev(P);
        break;
    case 7 :
        playPrev(P);
        break;
    case 8 :
        shuffleList(L);
        break;
    case 9 :
        cout << "Pilihan Sort : 1. Sort By ID"<<endl
             << "               2. Sort By Name"<<endl
             << "Pilihan      : ";cin >> condition;
        sortList(L,condition);
        break;
    case 10 :
        int n;
        cout << "Berapa banyak musik yang ingin direpeat : ";cin>>n;
        playRepeat(L, n);
        break;
    case 11:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
    //----------------------------------------
}
