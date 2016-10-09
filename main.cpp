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

    cout<<endl
        <<"=====<<Winamp CMD>>====="<<endl
        <<"1.  Input"<<endl
        <<"2.  View list"<<endl
        <<"3.  Play"<<endl
        <<"4.  Play next"<<endl
        <<"5.  Play previous"<<endl
        <<"6.  Repeat"<<endl
        <<"7.  Shuffle"<<endl
        <<"8.  Repeat all"<<endl
        <<"9.  Search"<<endl
        <<"10. Sort"<<endl
        <<"11. Exit"<<endl;
    cout<<"choose menu : ";
    cout<<endl;



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
        cout<<"Input"<<endl;
        inputNewSong(x);
        x.ID = index_ID++;
        P = alokasi(x);
        cout <<"Position        : 1. First"<<endl
             <<"                  2. After"<<endl
             <<"                  3. Last"<<endl
             <<"Select Position : ";cin>>number;
        if (number == 1) {
            insertFirst(L,P);
            cout << "Success";
        }
        else if (number == 2) {
            address R = new elmlist;
            cout << "Insert ID Element : ";
            cin >> R->info.ID;
            insertAfter(L,P,R);
            cout << "Success";
        }
        else if (number == 3) {
            insertLast(L,P);
            cout << "Success";
        }
        else {
            cout << "Error"<<endl;
        }
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
        playNext(P);
        break;
    case 7:
        shuffleList(L);
        break;
    case 8:
        int n;
        cout << "Repeat Times : ";cin>>n;
        playRepeat(L, n);
        break;
    case 9:
        cout << "Insert ID : "; cin>>x.ID;
        playSong(findElm(L, x));
        break;
    case 10:
        cout << "Sort         : 1. Sort By ID"<<endl
             << "               2. Sort By Name"<<endl
             << "Option      : ";cin >> condition;
        sortList(L,condition);
        break;
   case 11:
        cout<<"Thanks for Using My Program"<<endl;
        break;
    default :
        cout<<"Error"<<endl;
    }


    //----------------------------------------
}
