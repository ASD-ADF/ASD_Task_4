#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "list.h"
#include "player.h"
using namespace std;

int main()
{
    int pil=0, pil2, temp1=0, pildel;
    list L;
    MUSIC m;
    address P, temp2=NULL, Prec, P1, P2, P3;
    infotype x, delmus;

    create_list(L);
    while (pil==0)
    {
        system("cls");
        cout<<"=====MUSIC PLAYER====="<<endl;
        cout<<"1.Import Music"<<endl;
        cout<<"2.View Playlist"<<endl;
        cout<<"3.Play (First Music)"<<endl;
        cout<<"4.Play (Next)"<<endl;
        cout<<"5.Play (Prev)"<<endl;
        cout<<"6.Play (Last Played Music)"<<endl;
        cout<<"7.Play (Shuffle)"<<endl;
        cout<<"8.Play (Repeat All Music)"<<endl;
        cout<<"9.Sort Playlist"<<endl;
        cout<<"10.Search Music (by Name)"<<endl;
        cout<<"11.Delete Music"<<endl;
        cout<<"12.Exit Program"<<endl;
        cout<<"======================="<<endl;
        if (temp2!=NULL)
        {
            cout<<"Current Music : "<<info(temp2).id<<" "<<info(temp2).name<<endl;
        }
        cout<<"Masukkan pilihan Anda : ";
        cin>>pil;
        if (pil>12)
        {
            cout<<"Pilihan tidak tersedia !!, press any key";
            getch();
            pil=0;
        }
        else
        {
            switch(pil)
            {
            case 1:
                system("cls");
                input_music(x);
                x.id=temp1+1;
                P=allocate(x);
                insert_first(L,P);
                temp1=x.id;
                cout<<"Press any key"<<endl;
                getch();
                pil=0;
                break;
            case 2:
                system("cls");
                print_info(L);
                cout<<"Press any key"<<endl;
                getch();
                pil=0;
                break;
            case 3:
                system("cls");
                P=first(L);
                play_music(P);
                temp2=P;
                pil=0;
                break;
            case 4:
                system("cls");
                play_next(P);
                temp2=P;
                pil=0;
                break;
            case 5:
                system("cls");
                play_prev(P);
                temp2=P;
                pil=0;
                break;
            case 6:
                system("cls");
                play_last_played(P);
                temp2=P;
                pil=0;
                break;
            case 7:
                system("cls");
                play_shuffle(L,temp1,P);
                temp2=P;
                pil=0;
                break;
            case 8:
                system("cls");
                cout<<"=====REPEAT MUSIC====="<<endl;
                play_repeat(L,P);
                temp2=P;
                pil=0;
                break;
            case 9:
                system("cls");
                cout<<"=====SORTING MUSIC====="<<endl;
                sorting(L,temp1);
                cout<<"Playlist sorted by Name, press any key"<<endl;
                getch();
                pil=0;
                break;
            case 10:
                system("cls");
                search_data(L,P);
                temp2=P;
                cout<<"Press any key"<<endl;
                getch();
                pil=0;
                break;
            case 11:
                system("cls");
                cout<<"=====DELETE DATA====="<<endl;
                cout<<"1.Delete First"<<endl;
                cout<<"2.Delete After"<<endl;
                cout<<"3.Delete Last"<<endl;
                cout<<"Masukkan pilihan : "<<endl;
                cin>>pildel;
                if (pildel==1)
                {
                    P1=new element_list;
                    delete_first(L,P1);
                }
                else if (pildel==2)
                {
                    cout<<"Masukkan nama Music : ";
                    cin>>delmus.name;
                    Prec=find_elm(L,delmus);
                    if (Prec==NULL)
                    {
                        cout<<"Music tersebut belum diinput, press any key";
                        getch();
                        pil=0;
                        break;
                    }
                    else
                    {
                        P2=new element_list;
                        delete_after(L,P2,Prec);
                    }
                }
                else if (pildel==3)
                {
                    P3=new element_list;
                    delete_last(L,P3);
                }
                else
                {
                    cout<<"Input salah, press any key";
                }
                cout<<"======DATA DELETED=====";
                getch();
                pil=0;
                break;
            case 12:
                system("cls");
                cout<<"========SELESAI========";
                break;
            }
        }
    }
    return 0;
}
