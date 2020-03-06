#include "player.h"
#include "list.h"
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
    menu();


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
        // insert first music
        P = inputMusic();
        insertFirst(L,P);
        cout<<"press enter";getche();
        break;
    case 2:
        // insert last music
        //------------- YOUR CODE HERE -------------
        cout<<"UNDER MAIN TENIS"<<endl;
        //input music
        //insertLast()
        P = inputMusic();
        insertLast(L,P);

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
        //------------- YOUR CODE HERE -------------
        P = prev(first(L));
        playMusic(P);
        //----------------------------------------
        break;
    case 6:
        // search music by name
        //------------- YOUR CODE HERE -------------
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
        //------------- YOUR CODE HERE -------------
         cout<<"input music ID (.wav) : ";
        cin>>x.ID;
        P = findElmByID(L, x);
        if(P != NULL){
            cout<<"music found"<<endl;
        }

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
        //------------- YOUR CODE HERE -------------
        if(P!=NULL) {
            P = prev(P);
            playMusic(P);
        }
        break;

        //----------------------------------------
        break;
    case 11:
        // shuffle list
        shuffleList(L);
        cout<<"press enter";getche();
        break;
    case 12:
        // play repeat all music
        int n;
        cout<<"input repeat times : ";
        cin>>n;
        playRepeat(L,n);
        cout<<"press enter";getche();
        break;
    case 13:
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
