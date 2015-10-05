#include <iostream>
#include <string>
#include <windows.h>
#include "list.h"
#include "player.h"

using namespace std;

void inputNewSong(infotype &x){
    cout<<"input name song (.wav) : ";
    cin>>x.name;
    cout<<"input song location "<<endl<<"(write - for default location) :";
    cin>>x.location;
    if(x.location=="-"){x.location="";}
}

void printInfo(List L)
{
    address Q = First(L);
    while(Q != NULL)
    {
        cout<<"name : "<<Info(Q).name<<endl
            <<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
    }
}

void playSong(address P){
    string filename = Info(P).location+Info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}

void playNext(address &P){
    P = Next(P);
    playSong(P);
}

void playPrev(address &P){
    P=Prev(P);
    playSong(P);
}

void playRepeat(List &l, int n){
    int a=1;
    address p=First(l);
    while(a<=n){
        playSong(p);
        p=Next(p);
        if (p==First(l)){
            a++;
        }
    }
}

void sortList(List &l, int condition){
    if (condition==1){
        address p,q;
        List l2;
        createList(l2);
        p=First(l);
        while (First(l)!=NULL){
            deleteFirst(l,p);
            insertid(l2,p);
        }
        while (First(l2)!=NULL){
            deleteFirst(l2,p);
            insertLast(l,p);
        }
    }
    else{
        address p,q;
        List l2;
        createList(l2);
        p=First(l);
        while (First(l)!= NULL){
            deleteFirst(l,p);
            insertname(l2,p);
        }
        while (First(l2)!=NULL){
            deleteFirst(l2,p);
            insertLast(l,p);
        }
    }
}

void shuffleList(List &l){
    address p,q;
    List l2;
    int a;
    a=0;
    createList(l2);
    p=First(l);
    while(First(l)!=NULL){
        deleteFirst(l,p);
        if(a%2==0){
            insertLast(l2,p);
            a=a+1;
        }
        else{
            insertFirst(l2,p);
            a=a+1;
        }
    }
    while(First(l2)!=NULL){
        deleteFirst(l2,p);
        insertLast(l,p);
    }
}
