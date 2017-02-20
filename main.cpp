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
    x.name = "do.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = index_ID++;
    x.location = "asset";
    x.name = "re.wav";
    P = alokasi(x);
    insertLast(L,P);

    x.ID = index_ID++;
    x.location = "asset";
    x.name = "mi.wav";
    P = alokasi(x);
    insertLast(L,P);

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
    cout<<"======================MENU====================="<<endl;
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
    cout<<"input music filename (.wav) : ";
    cin>>x.name;
    cout<<"input music location "<<endl<<"(write - for default /asset location) :";
    cin>>x.location;
    if(x.location=="-") {
        x.location="asset";
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
        cout<<"press enter";getche();
        break;
    case 2:
        // insert last music
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;

        //----------------------------------------
        cout<<"press enter";getche();
        break;
    case 3:
        // view music list
        printInfo(L);
        cout<<"press enter";getche();
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
        break;
    case 6:
        // search music by name
        //-------------your code here-------------
        cout<<"input music filename (.wav) : ";
        cin>>x.name;
        P = findElmByName(L, x);
        if(P != NULL){
            cout<<"music found"<<endl;
        }
        //----------------------------------------
        cout<<"press enter";getche();
        break;
    case 7:
        // search music by ID
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;

        //----------------------------------------
        cout<<"press enter";getche();
        break;
    case 8:
        // play current music
        if(P!=NULL) {
            playMusic(P);
        }
        break;
    case 9:
        // play next music
        if(P!=NULL) {
            P = next(P);
            playMusic(P);
        }
        break;
    case 10:
        // play previous music
        //-------------your code here-------------
        cout<<"UNDER MAIN TENIS"<<endl;

        //----------------------------------------
        break;
    case 11:
        // shuffle list
        shuffleList(L);
        cout<<"press enter";getche();
        break;
    case 12:
        // sort list by ID
        sortListByID(L);
        cout<<"press enter";getche();
        break;
    case 13:
        // play repeat all music
        int n;
        cout<<"input repeat times : ";
        cin>>n;
        playRepeat(L,n);
        cout<<"press enter";getche();
        break;
    case 14:
        // delete music by ID
        cout<<"input music ID : ";
        cin>>x.name;
        deleteMusicByID(L, x);
        cout<<"press enter";getche();
        break;
    case 0:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
