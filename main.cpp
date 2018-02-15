#include <iostream>
#include "doublelist.h"
#include "operation.h"
#include "my_data2.h"

using namespace std;

void mainMenu();
List L;

int main()
{
    createList(L);

    mainMenu();

    return 0;
}

void mainMenu()
{
    infotype d;
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
    int choice, x;
    do
    {
        cout<<"Menu"<<endl;
        cout<<"1. insert"<<endl;
        cout<<"2. view data"<<endl;
        cout<<"3. find and view"<<endl;
        cout<<"4. find and edit"<<endl;
        cout<<"5. find and delete"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"input choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            X = create_data(d);
            P = allocate(X);
            insertAndSort(L, P);
            break;
        case 2:
            printInfo(L);
            break;
        case 3 :
            cout << "Masukkan ID yang ingin dicari : ";
            cin >> x;
            d.id = x;
            P = findElm(L, d);
            view_data(info(P));
            break;
        case 4 :
            cout << "Masukkan ID yang ingin dicari : ";
            cin >> x;
            d.id = x;
            P = findElm(L, d);
            edit_data(info(P));
            break;
        case 5 :
            mytype D;
            cout << "Masukkan ID yang ingin dicari : ";
            cin >> x;
            d.id = x;
            deletebyID(L, d);
            break;
        }
        //----------------------------------------
    }
    while(choice!=0);
}
