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
    infotype2 Y;
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
            Y = create_data(Y);
            P = allocate(X,Y);
            insertAndSort(L,P);
            break;
        case 2:{
            printInfo(L);
            break;
        }
        case 3: {
            infotype i;
            cout<<"Input ID : ";
            cin>>i.id;
            address in = findElm(L,i);
            if(in != NULL){
                cout<<"=STUDENT="<<endl;
                cout<<"ID    : ";cout<<in->info.id<<endl;
                cout<<"Name  : ";cout<<in->info.name<<endl;
                cout<<"Class : ";cout<<in->info.clas<<endl;
                cout<<"Score : ";cout<<in->info.score<<endl;
                cout<<"=Lecturer="<<endl;
                cout<<"ID      : ";cout<<in->info2.id_lec<<endl;
                cout<<"Name    : ";cout<<in->info2.name_lec<<endl;
                cout<<"Subject : ";cout<<in->info2.clas_lec<<endl;
                cout<<"--------------"<<endl;
            }else{
                cout<<"ID is not FOUND"<<endl;
            }
            break;
        }
        case 4: {
            infotype i;
            cout << " Input ID : " ;
            cin >> i.id;
            address in = findElm(L,i);
            if (in != NULL){
                edit_data(info(in));
                edit_data(info2(in));
            } else {
                cout << "ID not FOUND" << endl;
            }
            break;
        }
        case 5: {
            infotype i;
            cout << " ID not FOUND ";
            cin >> i.id;
            deletebyID(L,i);
        }
        }
    } while(true);

    //----------------------------------------
}
