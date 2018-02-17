#include <iostream>
#include "doublelist.h"
#include "operation.h"
#include "my_data2.h"

using namespace std;

void mainMenu();
List L;

int main() {
    createList(L);

    mainMenu();

    return 0;
}

void mainMenu() {
    address P;
    infotype X;
    /**
    * IS : List has been created
    * PR : prints menu to user
    *       1. insert new data
    *       2. print all data
    *       3. find and print a data by ID
    *       4. edit data by ID
    *       5. delete data by ID
    *       0. exit
    */
    //-------------your code here-------------
    int choice;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. insert"<<endl;
        cout<<"2. view data"<<endl;
        cout<<"3. find and view"<<endl;
        cout<<"4. find and edit"<<endl;
        cout<<"5. find and delete"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"input choice: ";
        cin>>choice;
        switch(choice) {
        case 1:
            {X = create_data();
            P = allocate(X);
            insertFirst(L,P);
            //insertLast(L,P);      //berhasil!!!
            //insertAndSort(L,P);   //berhasill!!!
            break;}
        case 2: //berhasil!!
            {P=first(L);
            while(P!=NULL){
                view_data(info(P));
                P=next(P);
            }
            break;}
        case 3:   //berhasil!!!!
            {infotype x;
            cout<<"Masukkan id yang ingin dicari = ";
            cin>>x.ID;

            address w=findElm(L,x);
            if(w==NULL){
                cout<<"Data tidak ditemukan"<<endl;
            }else{
                view_data(info(w));
            }break;}
        case 4:   //berhasill!!!!
        	{infotype x;
            cout<<"Masukkan id yang ingin diubah = ";
            cin>>x.ID;

            address m=findElm(L,x);
            if(m==NULL){
                cout<<"Data tidak ditemukan"<<endl;
            }else{
                edit_data(info(m));
            }break;}
        case 5:
		{infotype x;
            cout<<"Masukkan id yang ingin dihapus = ";
            cin>>x.ID;
            deletebyID(L,x);
            break;}
        }
    } while(choice!=0);

    //----------------------------------------
}





















