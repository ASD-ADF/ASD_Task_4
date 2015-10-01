#include <iostream>
#include "list.h"
#include "player.h"
#include <conio.h>

using namespace std;

List L;
address P;
address Prec;
infotype x;
<<<<<<< HEAD
int pilihan;
int number;
=======
int id;
>>>>>>> fcc968103c85a503525044154016c90cd42284ea

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
    } while (pil<8);
}

void displayMenu() {
<<<<<<< HEAD
    cout<<"1. Input New Song"<<endl;
    cout<<"2. View List"<<endl;
    cout<<"3. Play First Song"<<endl;
    cout<<"4. Play Next "<<endl;
    cout<<"5. Delete song"<<endl;
    cout<<"6. Play Previous"<<endl;
    cout<<"7. Repeat Song"<<endl;
    cout<<"8. Shuffle Song"<<endl;
    cout<<"Choose menu: ";
=======
    cout<<"1. input new "<<endl
        <<"2. view list"<<endl
        <<"3. play first song"<<endl
        <<"4. play next "<<endl
        <<"5. exit"<<endl
        <<"6. Clear"<<endl
        <<"7. Delete After"<<endl
        <<"8. Count nodes"<<endl;
    cout<<"choose menu : ";
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
}

void runMenu(int menu) {
    switch(menu) {
<<<<<<< HEAD
    case 1 :
        cout<<"Input New Song "<<endl;
        cout<<"Berikut adalah pilihan untuk posisi input data yang baru:"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"Masukkan nomor menu yang anda inginkan: ";
        cin>>pilihan;
        if (pilihan==1)
        {
            inputNewSong(x);
            P = alokasi(x);
            insertFirst(L,P);
            break;
        }
        else if (pilihan==2)
        {
            inputNewSong(x);
            P = alokasi(x);
            insertLast(L, P);
            break;
        }
        else if (pilihan==3)
        {
            address R=new elemenList;
            cout<<"Masukkan ID lagu yang ingin Anda inputkan dengan data baru setelahnya: ";
            cin>>info(R).ID;
            insertAfter(L,P,R);
            break;
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
        {
        cout<<"Delete Song "<<endl;
        cout<<"Berikut adalah pilihan untuk delete song: "<<endl;
        cout<<"1. Delete First"<<endl;
        cout<<"2. Delete Last"<<endl;
        cout<<"3. Delete After"<<endl;
        cout<<"Masukkan nomor menu yang anda inginkan: ";
        cin>>number;
        if (number==1)
        {
            deleteFirst(L,P);
            break;
        }
        else if (pilihan==2)
        {
            deleteLast(L,P);
            break;
        }
        else if (pilihan==3)
        {
            address R=new elemenList;
            cout<<"Masukkan ID lagu sebelum lagu yang ingin Anda hapus: ";
            cin>>info(R).ID;
            deleteAfter(L,P,R);
            break;
        }
        break;
        }
    case 6:
        {
            playPrev(P);
        }
    case 7:
        {
            repe
        }
    default :
        cout<<"Nomor menu tidak ditemukan. Silahkan masukkan kembali"<<endl;
=======
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
>>>>>>> fcc968103c85a503525044154016c90cd42284ea
    }
}
