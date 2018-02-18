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
            X = create_data();
            P = allocate(X);
            insertFirst(L,P);
            break;
        case 2 :
            if (first(L) == NULL ) {
                cout << "empty" << endl;
            } else {
                printInfo(L);
            }
            cout << endl;
            break;
        case 3 :
            if (first(L) == NULL ) {
                cout << "empty" << endl;
            }
            cout << "find ID : " ;
            cin >> x.id;
            P = findElm(L,X);
            if (P == NULL ) {
                cout << "ID not found"<< endl;
            } else {
                view_data(info(P));
                cout << endl;
            }
            break;
        case 4 :
            if (first(L) == NULL ) {
                cout << "empty" << endl;
            }
            cout << "edit ID : " ;
            cin >> x.id;
            P = findElm(L,X);
            if (P == NULL ) {
                cout << "ID not found"<< endl;
            } else {
                edit_data(info(P));
                cout << endl;
            }
            break;
        case 5 :
            if (first(L) == NULL ) {
                cout << "empty" << endl;
            }
            cout << "delete ID : " ;
            cin >> x.id;
            deletebyID(L,X);
            break;
        case 0 :
            cout << "Thank You " << endl;
            return;
            break;
        }
    } while(true);

    //----------------------------------------
}
