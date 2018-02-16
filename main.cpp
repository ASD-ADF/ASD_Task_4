#include <iostream>
#include "doublelist.h"
#include "operation.h"
#include "my_data2.h"
#include "my_data.h"

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
            X = create_data2();
            P = allocate(X);
            insertAndSort(L,P);
            break;
        case 2:
            printInfo(L);
            break;
        case 3:
            if (first(L)==NULL) {
                cout<<"list kosong"<<endl;
                break;
            }
            mytype2 x;
            cout<<"ID yang Dicari : ";
            cin>>x.ID;
            cout<<endl;
            P=findElm(L,x);
            view_data2(info(P));
            break;
        case 4:
            if (first(L)==NULL) {
                cout<<"list kosong"<<endl;
                break;
            }
            cout<<"ID yang ingin di edit : ";
            cin>>X.ID;
            P=findElm(L,X);
            if (P==NULL) {
                cout<<"ID tidak ditemukan"<<endl;
            } else {
                edit_data2(info(P));
                cout<<endl;
            }
            break;
        case 5:
            if (first(L)==NULL) {
                cout<<"list kosong"<<endl;
                break;
            }
            cout<<"ID yang ingin di hapus : ";
            cin>>X.ID;
            deletebyID(L,X);
            break;
        case 0:
            return;
        }
    } while(true);

    //----------------------------------------
}
