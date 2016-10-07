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
    } while (pil!=7);
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
        <<"5. play Prev "<<endl
        <<"6. sort List "<<endl
        <<"7. exit"<<endl;
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
        int sortby;
        sortby = 0;
        cout << "Sort by :\n1. ID\n2.Name\nInput = ";
        while(sortby!=1 && sortby != 2)cin >> sortby;
        sortList(L,sortby);
        break;
    case 7:
        cout<<"thank you"<<endl;
        break;
    case 8:
        deleteFirst(L,P);
        break;
    case 9:
        deleteSong(L,1, P);
        break;
    default :
        cout<<"wrong input"<<endl;
    }


    //----------------------------------------
}
