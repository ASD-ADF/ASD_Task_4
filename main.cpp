#include <iostream>
#include "doublelist.h"
#include "operation.h"
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
            X = create_data(X);
            P = allocate(X);
            insertAndSort(L,P);
            break;

        case 2:
            printInfo(L);
            break;

        case 3:
            if (first(L) == NULL)
                {
                    cout<<"No Data"<<endl;
                    break;
                }
            cout<<" Find ID : ";
            cin>>X.id;
            P = findElm(L,X);
            if (P != NULL)
                {
                    view_data(info(P));
                }
            else
                {
                    cout<<"Data Not Found"<<endl;
                }
            break;

        case 4:
            if (first(L) == NULL)
                {
                    cout<<"No Data"<<endl;
                    break;
                }
            cout<<" Edit ID: ";
            cin>>X.id;
            P = findElm(L,X);
            if (P != NULL)
                {
                    edit_data(info(P));
                }
            else
                {
                    cout<<"Data Not Found"<<endl;
                }
            break;

        case 5:
            if (first(L) == NULL)
                {
                    cout<<"No Data"<<endl;
                    break;
                }
            cout<<" Delete ID :";
            cin>>X.id;
            P = findElm(L,X);
            if ( P != NULL)
                {
                    deletebyID(L,X);
                }
            else
                {
                    cout<<"Data Not Found"<<endl;
                }
            break;
        case 0:
            cout<<"Thank You"<<endl;
            return;
        }
    cout<<endl<<endl;
    } while(true);

    //----------------------------------------
}
