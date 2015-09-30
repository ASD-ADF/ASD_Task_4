#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>

using namespace std;

List L;
address P;
infotype x;
int id;

void menu();
void displayMenu();
void runMenu(int menu);

int main() {
    id = 1;
    cout << "Hello world!" << endl;

    createList(L);
    // example of data initialization
//    x.ID = 1;
//    x.location = "";
//    x.name = "clapping.wav";
//    P = alokasi(x);
//    insertFirst(L,P);

    x.ID = id;
    id++;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertFirst(L,P);

  //  clearList(L);

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
        <<"5. exit"<<endl
        <<"6. Clear"<<endl
        <<"7. Delete After"<<endl
        <<"8. Count nodes"<<endl;
    cout<<"choose menu : ";
}

void runMenu(int menu) {
    switch(menu) {
        case 0:
            cout<<"input new song : "<<endl;
            inputNewSong(x);
            x.ID = id;
            id++;
            P = alokasi(x);
            insertFirst(L,P);
            break;
        case 1 :
            cout<<"input new song : "<<endl;
            inputNewSong(x);
            x.ID = id;
            id++;
            P = alokasi(x);
            insertLast(L,P);
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
            cout<<"thank you"<<endl;
            break;
        case 6:
            clearList(L); break;
        case 7: {
            infotype a;
            address Pr;
            cout << "Ingin menghapus node setelah..." << endl
                << "Masukkan nama lagu: ";
            cin >> a.name;
            Pr = findElm(L, a);
            if(Pr != NULL)
                deleteAfter(L, P, Pr);
            break;
        }
        case 8:
            cout << countNodes(L) << endl;
            break;
        case 9:
            sortByID(L);
            break;
        case 10:
            sortByName(L);
            break;
        default:
            cout<<"wrong input"<<endl;
    }
}
