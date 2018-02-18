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
    address P, Q;
    infotype x, b;
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
            x = create_data(x);
            P = allocate(x);
            insertFirst(L,P);
            insertAndSort(L,P);
            break;
        case 2:
            printInfo(L);
            break;
        case 3:
            cout<<"ID   : ";
            cin>>x.id;
            P = findElm(L, x);
            b = P->info;
            view_data(b);
        case 4:
            cout<<"ID   : ";
            cin>>x.id;
            P = findElm(L, x);
            cout<<"Name     : ";
            cin>>P->info.name;
            cout<<"Class   : ";
            cin>>P->info.Class;
            cout<<"Score   : ";
            cin>>P->info.score;
        case 5:
            if (first(L) == NULL) {
                cout<< "List empty" <<endl;
                break;
            }
            cout<< "ID : "; cin>>x.id;
            deletebyID(L,x);
            break;
        }
    } while(true);

    //----------------------------------------
}
