#include "player.h"
#include <conio.h>

List L;
address P;
infotype x;
int index_ID;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {

    index_ID = 1;
    createList(L);

    //-----------------------------------------
    // example of data initialization
    //-----------------------------------------
    x.ID = index_ID++;
    x.location = "asset";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = index_ID++;
    x.location = "asset";
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
    */
    cout<<"=========== MENU =========== "<<endl
        <<"1.  insert first music"<<endl
        <<"2.  insert last music"<<endl
        <<"3.  view music list"<<endl
        <<"4.  play first music"<<endl
        <<"5.  play last music"<<endl
        <<"6.  search music by name"<<endl
        <<"7.  search music by ID"<<endl
        <<"8.  play current music"<<endl
        <<"9.  play next music"<<endl
        <<"10. play previous music"<<endl
        <<"11. shuffle list"<<endl
        <<"12. sort list by ID"<<endl
        <<"13. play repeat all music"<<endl
        <<"14. delete music by ID"<<endl
        <<"0. exit"<<endl;
    cout<<"choose menu : ";
}

address inputMusic() {
    /**
    * PR : meminta input user untuk mengisi nama dan lokasi file
    * FS : mengembalikan alokasi elemen dengan data nama dan lokasi file
    */
    cout<<"input name music (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-") {
        x.location="";
    }
    x.ID = index_ID++;
    return alokasi(x);
}

void runMenu(int menu) {
    /**
    * prosedur memproses input pilihan menu dari user
    * TODO : modifikasi menu sehingga juga memproses menu yang disediakan:
    */

    switch(menu) {
    case 1:
        // insert first music
        P = inputMusic();
        insertFirst(L,P);
        getch();
        break;
    case 2:
        // insert last music
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;

        //----------------------------------------
        getch();
        break;
    case 3:
        // view music list
        printInfo(L);
        getch();
        break;
    case 4:
        // play first music
        P = first(L);
        playMusic(P);
        break;
    case 5:
        // play last music
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;

        //----------------------------------------
        getch();
        break;
    case 6:
        // search music by name
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;
        // cin x.name
        // P = findElmByName(L, x);
        //----------------------------------------
        getch();
        break;
    case 7:
        // search music by ID
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;
        // cin x.id
        // P = findElmByID(L, x)
        //----------------------------------------
        getch();
        break;
    case 8:
        // play current music
        if(P!=NULL) {
            playMusic(P);
        }
        getch();
        break;
    case 9:
        // play next music
        if(P!=NULL) {
            P = next(P);
            playMusic(P);
        }
        getch();
        break;
    case 10:
        // play previous music
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;

        //----------------------------------------
        getch();
        break;
    case 11:
        // shuffle list
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;
        // shuffleList(L)
        //----------------------------------------
        getch();
        break;
    case 12:
        // sort list by ID
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;
        // sortListByID(L)
        //----------------------------------------
        getch();
        break;
    case 13:
        // play repeat all music
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;
        // cin n
        // playRepeat(L,n)
        //----------------------------------------
        getch();
        break;
    case 14:
        // delete music by ID
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;
        // cin x.id
        // deleteMusicByID(L, x)
        //----------------------------------------
        getch();
        break;
    case 0:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
    //----------------------------------------
}
