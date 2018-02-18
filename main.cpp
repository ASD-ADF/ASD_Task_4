#include <iostream>
#include "doublelist.h"
#include "operation.h"
#include "my_data.h"
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
    infotype2 X2;
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
            X = create_data(X);
            X2 = create_data(X2);
            P = allocate(X,X2);
            insertAndSort(L,P);
            break;
        case 2:{
            printInfo(L);
            break;
            }
        case 3:{
            infotype ifo;
            cout<<"Input Your ID : ";
            cin>>ifo.id;
            address fo = findElm(L,ifo);
            if(fo != NULL){
                cout<<"======== MY DATA ========"<<endl;
                cout<<"Name    : ";cout<<fo->info.name<<endl;
                cout<<"Class  : ";cout<<fo->info.clas<<endl;
                cout<<"ID : ";cout<<fo->info.id<<endl;
                cout<<"Score : ";cout<<fo->info.score<<endl;
                cout<<"======== DATA LECTURE ========"<<endl;
                cout<<"Name      : ";cout<<fo->info2.name_lec<<endl;
                cout<<"Major    : ";cout<<fo->info2.major<<endl;
                cout<<"ID : ";cout<<fo->info2.id_lec<<endl;
                cout<<"--------------"<<endl;
            }else{
                cout<<"ID doesn't exist"<<endl;
            }
            break;
            }
        case 4:{
            infotype ifo;
            cout<<"Input Your ID : ";
            cin>>ifo.id;
            address fo = findElm(L,ifo);
            if(fo != NULL){
                edit_data(info(fo));
                edit_data(info2(fo));
            }else{
                cout<<"ID doesn't exist"<<endl;
            }
            break;
        }
       case 5:{
            infotype ifo;
            cout<<"Input Your ID : ";
            cin>>ifo.id;
            deletebyID(L,ifo);
       }
        }
    } while(true);

    //----------------------------------------
}
