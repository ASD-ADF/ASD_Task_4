#include "player.h"

List L;
address P,Q;
infotype x;
string s;
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
    x.ID = index_ID++;
    x.location = "";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = index_ID++;
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
    } while (pil!=0);
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
        <<"3. play first song"<<endl
        <<"4. play next "<<endl

        <<"5. search song"<<endl
        <<"6. play previous"<<endl
        <<"7. play again (last song)"<<endl
        <<"8. shuffle list"<<endl
        <<"9. short the song"<<endl
        <<"10.repeat all"<<endl
        <<"11.Delete By ID"<<endl
        <<"0. exit"<<endl;
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
    case 3:
        P = first(L);
        playSong(P);
        break;
    case 4:
        playNext(P);
        break;
    case 5:
        cout << "Search song by Name : ";
        cin >> s;
        s = s+".wav";
        Q = findElm(L,s);
        if (Q==Nil){
            cout <<"File not found";
        } else {
            cout <<"File founded"<<endl;
            cout <<"Playing..."<<endl;
            P = Q;
            playSong(P);
        };
        break;
    case 6:
        playPrev(P);
        break;
    case 7:
        playSong(P);
        break;
    case 8:
        shuffleList(L);
        break;
    case 9:
        int cond;
        cout << "1, sort by ID"<<endl
             << "2, sort by Name"<<endl
             << "choose > ";
        cin >> cond;
        sortList(L,cond);
        break;
    case 10:
        int n;
        cout<<"how many times to repeat : ";
        cin >> n;
        playRepeat(L,n);
        break;
    case 11:
        deleteSong(L);
        break;
    case 0 :
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }


    //----------------------------------------
}
