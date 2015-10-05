#include "list.h"
#include "player.h"

List L;
address P,Q;
infotype x;
int pil;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    createList(L);
    // example of data initialization
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

    menu();
    return 0;
}

void menu() {
    int pil;
    do {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    } while (pil!=5);
}

void displayMenu() {
    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next "<<endl
        <<"5.  play previous song"<<endl
        <<"6. search song by name"<<endl
        <<"7. play the last played song"<<endl
        <<"8. sort song"<<endl
        <<"9. repeat playlist"<<endl
        <<"10. exit"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
    case 1 :
        cout<<"input new song : "<<endl;
        inputNewSong(x);
        P = alokasi(x);
        insertFirst(L,P);
        getch();
        break;
        
    case 2:
        printInfo(L);
        getch();
        break;
        
    case 3 :
        P = First(L);
        playSong(P);
        getch();
        break;
        
    case 4:
        playNext(P);
        getch();
        break;
        
    case 5:
         playPrev(P);
          getch();
         break;
        
     case 6: 
        cout<<"Input name song that want to find: "; cin>> x.name;
        P=findElm(L,x);
        if (P!= NULL) {
            playSong(P);
            //Q=P;
        }
        else {
            cout<<"Not found"<<endl;
        }
        getch();
        break;

    case 7: 
        if (Q==NULL) {
            cout<<"No song that recently played"<<endl;

        }
        else {
            playSong(Q);
        }
        getch();
        break;

    case 8: 
        cout<<"1. By ID"<<endl
            <<"2. By Name"<<endl
            <<"Input yours choosen: "; cin>>pil;
        if(pil<1 && pil>2) {
            cout<<"INPUT UNDEFINED";
        }
        else {
            sortList(L,pil);
        }
        getch();
        break;

    case 9: 
        int n;
        cout<<"How many repeat that you want?"; cin>>n;
        playRepeat(L,n);
        getch();
        break;

    case 10: 
        cout<<"Thank you"<<endl;
        break;
        getch();
    default :
        cout<<"wrong input"<<endl;
    }
}
