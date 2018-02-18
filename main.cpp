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
    infotype X,d;
    int t=1;
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
            X = create_data(d);
            P = allocate(X);
            insertAndSort(L,P);
            break;
        case 2:
            printInfo(L);
            break;
        case 3:
            cout<<"Masukkan ID yang ingin dicari : ";
            cin>>X.id;
            P=findElm(L, X);
            X=info(P);
            view_data(X);
            break;
        case 4:
            cout<<"Masukkan ID yang ingin dicari : ";
            cin>>X.id;
            P=findElm(L, X);
            X=info(P);
            edit_data(X);
            info(P)=X;
            break;
        case 5:
            cout<<"Masukkan ID Buku yang ingin di hapus : ";
            cin>>X.id;
            deletebyID(L, X);
            break;
        case 0:
            t=0;
            break;
        }
    } while(t==1);

    //----------------------------------------
}
