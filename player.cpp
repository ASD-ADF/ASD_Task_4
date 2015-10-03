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
    do
    {
        cout<<"name : "<<Info(Q).name<<endl;
        cout<<"location: "<<Info(Q).location<<endl;
        Q = Next(Q);
    }while(Q != First(L));
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
    P = Prev(P);
    playSong(P);
}

void shuffleList(List &L){
    List L2;
	address arrList[20];
	address arrList2[20];
	int i = 0;
	int k = 0;
	address P;
	P = First(L);
	bool value = false;

	createList(L2);
	do{
		arrList[i] = P;
		P = Next(P);
	}while(P != First(L));

	int random = rand() % i;

	while(arrList2[20] != NULL){
		value = false;
		k = 0;
		while(k<=20 and !value and arrList2[k] != NULL){
			if(arrList[random] == arrList2[k]){
				value = true;
			}else{
				k++;
			}
		}

		if(arrList2[k] == NULL){
			arrList2[k] = arrList[random];
			P = alokasi(Info(arrList[random]));
			insertFirst(L2, P);
		}
	}

	L = L2;
}


void sortList(List &, int condition);
// sort song List by some condition
// example if condition = 1, then sort by ID
//          if condition = 2, then sort by name

void playRepeat(List &L, int n){
// play the song list from the first song
// and repeat the list n times
    address P;
    for(int i=0; i<n; i++){
        P = First(L);
        playSong(P);
        if(Next(First(L)) != First(L)){
            P = Next(P);
            while(P != First(L)){
                playSong(P);
                P = Next(P);
            }
        }
    }
}
