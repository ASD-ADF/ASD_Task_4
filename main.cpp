#include "player.h"

List L;
address P;
infotype x;
int index_ID,n;

void menu();
void displayMenu();
void runMenu(int menu);

int main()
{

    index_ID = 1;
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


void menu()
{
    /**
    * prosedur menu utama
    */
    int pil;
    do
    {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    }
    while (pil!=12);
}


void displayMenu()
{
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

    cout<<"1.  input new Song "<<endl
        <<"2.  search song by ID"<<endl
        <<"3.  view list"<<endl
        <<"4.  Short the Song"<<endl
        <<"5.  play first song"<<endl
        <<"6.  play again the last song played"<<endl
        <<"7.  play next "<<endl
        <<"8.  play Prev"<<endl
        <<"9.  Play Repeat All"<<endl
        <<"10. Suffle List"<<endl
        <<"11. Delete Song by ID"<<endl
        <<"12. Exit"<<endl;
    cout<<"choose menu : ";



    //----------------------------------------
}

void runMenu(int menu)
{
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

    int pil;

    switch(menu)
    {
    case 1 :
        cout<<"input new song : "<<endl;
        x.ID = index_ID++;
        inputNewSong(x);

        P = alokasi(x);
        insertFirst(L,P);

        cout <<"Lagu berhasil diinput";
        getch();
        system("cls");

        break;
    case 2:
        cout <<"Masukan ID atau Judul Lagu "<<endl;
        cout <<"1. byID"<<endl
             <<"2. byName"<<endl;
        cout <<"pilih menu : ";
        cin >> pil;

        if (pil == 1)
        {
            cout <<"ID lagu    : ";
            cin >> x.ID;
            P = findElm(L,x);
            cout <<"ID Lagu    : "<<Info(P).ID<<endl;
            cout <<"Judul Lagu : "<<Info(P).name<<endl;
            cout <<"Lokasi     : "<<Info(P).location<<endl;
            playSong(P);
            cout <<endl
                 <<endl;
        }
        else if (pil == 2)
        {
            cout <<"Judul lagu (.wav) : ";
            cin >> x.name;
            P = findElm2(L,x);
            cout <<"ID Lagu    : "<<Info(P).ID<<endl;
            cout <<"Judul Lagu : "<<Info(P).name<<endl;
            cout <<"Lokasi     : "<<Info(P).location<<endl;
            playSong(P);
            cout <<endl
                 <<endl;
        }
        else
        {
            cout <<"wrong menu";
            getch();
            system("cls");
        }
        break;
    case 3:
        printInfo(L);
        getch();
        system("cls");
        break;
    case 4 :
        cout <<"Sort list berdasarkan ID dan nama lagu "<<endl;
        cout <<"1. Sort byID"<<endl
             <<"2. Sort byName"<<endl;
        cout <<"sorting berdasarkan : ";
        cin >> pil;
        cout << endl;
        if (pil == 1 or pil == 2)
        {
            sortList(L,pil);
            cout <<endl;
            getch();
            system("cls");
        }
        else
        {
            cout <<"wrong input";
            getch();
            system("cls");
        }
        break;
    case 5 :
        P = First(L);
        playSong(P);
        getch();
        system("cls");
        break;
    case 6:
        playSong(P);
        getch();
        system("cls");
        break;
    case 7:
        playNext(P);
        getch();
        system("cls");
        break;
    case 8:
        playPrev(P);
        getch();
        system("cls");
        break;
    case 9:
        cout <<"repeat sebanyak : ";
        cin >> n;
        playRepeat(L, n);
        getch();
        system("cls");
        break;
    case 10:
        shuffleList(L);
        cout <<"list teracak";
        cout <<endl;
        printInfo(L);
        getch();
        system("cls");
        break;
    case 11:
        deleteSong(L);
        cout <<"lagu berhasil di hapus";
        break;
    case 12:
        cout<<"thank you"<<endl;
        break;
    default :
        cout<<"wrong input"<<endl;
        getch();
        system("cls");
    }


    //----------------------------------------
}
