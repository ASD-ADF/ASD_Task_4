#include "player.h"
#include "list.h"
#include <conio.h>
#include <windows.h>

List L;
address P;
infotype x;
int index_ID;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    address P;
    infotype x;
    List L;
    int index_ID;


    index_ID = 1;
    createList(L);

    menu();
    /*

    //-----------------------------------------
    // example of data initialization
    //-----------------------------------------
    //displayMenu();
    x.ID = index_ID++;
    x.location = "asset";
    x.name = "do.wav";
    P = allocate(x);
    insertFirst(L,P);

    x.ID = index_ID++;
    x.location = "asset";
    x.name = "re.wav";
    P = allocate(x);
    insertLast(L,P);

    x.ID = index_ID++;
    x.location = "asset";
    x.name = "mi.wav";
    P = allocate(x);
    insertLast(L,P);

    //-----------------------------------------
    // view data
    //-----------------------------------------
    printInfo(L);


    //-----------------------------------------
    // call main menu
    //-----------------------------------------
    */
    return 0;
}


void menu() {
    /**
    * MAIN MENU PROCEDURE
    * YOU DON'T NEED TO MODIFY THIS
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
    * PROCEDURE TO SHOW THE MENU TEXT
    * YOU DON'T NEED TO MODIFY THIS
    */
    cout<<"======================MENU====================="<<endl
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
        <<"12. play repeat all music"<<endl
        <<"13. delete music by ID"<<endl
        <<"0. exit"<<endl;
    cout<<"choose menu : ";
}

address inputMusic() {
    /**
    * PR : ASKS USER INPUT TO FILL THE MUSIC NAME AND LOCATION
    * FS : ALLOCATE AND RETURN THE ADDRESS OF THE ELEMENT
    * YOU DON'T NEED TO MODIFY THIS
    */
    cout<<"input music filename (.wav) : ";
    cin>>x.name;
    cout<<"input music location "<<endl<<"(write - for default /asset location) :";
    cin>>x.location;
    if(x.location=="-") {
        x.location="asset";
    }
    x.ID = index_ID++;
    return allocate(x);
}

void runMenu(int menu) {
    /**
    * PROCESS MENU ACCORDING TO USER CHOICE
    * TODO : MODIFY THE CODE TO PROCESS USER CHOICE
    */

    switch(menu) {
    case 1:
        cout<<"==============================================="<<endl;
        P = inputMusic();
        insertFirst(L,P);
        cout<<"==============================================="<<endl;
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 2:
        // insert last music
        //------------- YOUR CODE HERE -------------
        cout<<"==============================================="<<endl;
        P = inputMusic();
        insertLast(L,P);
        cout<<"==============================================="<<endl;
        //----------------------------------------
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 3:
        cout<<"==============================================="<<endl;
        cout<<"             DAFTAR MUSIK DALAM LIST           "<<endl;
        cout<<"==============================================="<<endl;
        if (first(L) != NULL){
                printInfo(L);
        }else{
            cout << "Belum Ada Lagu di Dalam List"<<endl;
            cout << "Silahkan Masukkan Terlebih Dahulu Lagu ke Dalam List"<<endl;
        }

        cout<<"==============================================="<<endl;
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 4:
        // play first music
        P = first(L);
        playMusic(P);
        system ("CLS");
        break;
    case 5:
        // play last music
        //------------- YOUR CODE HERE -------------
        P = prev(first(L));
        playMusic(P);
        system ("CLS");

        //----------------------------------------
        break;
    case 6:
        // search music by name
        //------------- YOUR CODE HERE -------------
        cout<<"input music filename (.wav) : ";
        cin>>x.name;
        P = findElmByName(L, x);
        if ((P != NULL) && (info(P).name == x.name)){
            cout<<"music '"<<x.name << "' found"<<endl;
        }else{
            cout << "Lagu Tidak Terdaftar di Dalam List"<<endl;
        }
        //----------------------------------------
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 7:
        // search music by ID
        //------------- YOUR CODE HERE -------------
        cout<<"input music ID : ";
        cin>>x.ID;
        P = findElmByID(L, x);
        if ((P != NULL) &&(info(P).ID == x.ID)){
            cout<<"music with ID "<<x.ID<<" found : "<<info(P).name<<endl;
        }else{
            cout << "ID Tidak Ada Dalam List"<<endl;
        }

        //----------------------------------------
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 8:
        // play current music
        if(P!=NULL) {
            playMusic(P);
        }
        system ("CLS");
        break;
    case 9:
        // play next music
        if(P!=NULL) {
            P = next(P);
            playMusic(P);
        }
        system ("CLS");
        break;
    case 10:
        // play previous music
        //------------- YOUR CODE HERE -------------
        if (P != NULL){
            P = prev(P);
            playMusic(P);
        }
        system ("CLS");
        //----------------------------------------
        break;
    case 11:
        // shuffle list
        shuffleList(L,index_ID);
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 12:
        // play repeat all music
        int n;
        cout<<"input repeat times : ";
        cin>>n;
        playRepeat(L,n,index_ID);
        cout<<"==LAGU SELESAI=="<<endl;
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 13:
        // delete music by ID
        if (first(L)==NULL){
            cout << "File Yang Ingin Dihapus Tidak Terdapat Di Dalam List"<<endl;
        }else{
            cout<<"input music ID : ";
            cin>>x.ID;
            deleteMusicByID(L, x);
        }
        cout<<"press enter";getche();
        system ("CLS");
        break;
    case 0:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
    }
}
