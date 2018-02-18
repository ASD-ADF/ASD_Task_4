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
    infotype X2;
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
            cout<<"ID   : ";
            cin>>ifo.id;
            address fo = findElm(L,ifo);
            if(fo != NULL){
                cout<<"STUDENT"<<endl;
                cout<<"ID       : ";cout<<fo->info.id<<endl;
                cout<<"NAMA     : ";cout<<fo->info.name<<endl;
                cout<<"KELAS    : ";cout<<fo->info.clas<<endl;
                cout<<"SCORE    : ";cout<<fo->info.score<<endl;
                cout<<"LECTURER"<<endl;
                cout<<"ID       : ";cout<<fo->info2.id_lec<<endl;
                cout<<"NAME     : ";cout<<fo->info2.name_lec<<endl;
                cout<<"SUBJECT  : ";cout<<fo->info2.sub<<endl;
                cout<<"--------------"<<endl;
            }else{
                cout<<"ID NOT EXIST"<<endl;
            }
            break;
            }
        case 4:{
            infotype ifo;
            cout<<"ID : ";
            cin>>ifo.id;
            address fo = findElm(L,ifo);
            if(fo != NULL){
                edit_data(info(fo));
                edit_data(info2(fo));
            }else{
                cout<<"ID NOT EXIST"<<endl;
            }
            break;
        }
        case 5:{
            infotype ifo;
            cout<<"ID : ";
            cin>>ifo.id;
            deletebyID(L,ifo);
    }
        }
    } while(true);

    //----------------------------------------
}
