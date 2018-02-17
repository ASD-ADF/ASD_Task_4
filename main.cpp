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
    infotype x;
    infotype2 x2;
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
        switch(choice){
        case 1:
            x = create_data(x);
            x2= create_data2(x2);
            P = allocate(x,x2);
            insertAndSort(L,P);
            break;
        case 2:{
            printInfo(L);
            break;
            }
        case 3:{
            infotype x;
            cout<<"Input ID : ";
            cin>>x.id;
            address id = findElm(L,x);
            if(x.id!= NULL){
                cout<<"--Student's biodata--"<<endl;
                cout<<"ID   : ";cin>>x.id;
                cout<<"Name : ";cin>>x.name;
                cout<<"Class : ";cin>>x.clas;
                cout<<"Score: ";cin>>x.score;
                cout<<"---------------------"<<endl;
                cout<<"----Book's Detail----"<<endl;
                cout<<"Book's ID      : "<<x2.idbook<<endl;
                cout<<"Book's Title    : "<<x2.title<<endl;
                cout<<"Book's Year  : "<<x2.year<<endl;
                cout<<"Book's publisher: "<<x2.publish<<endl;
                cout<<"---------------------"<<endl;

            }else{
                cout<<"ID is not Exist"<<endl;
            }
            break;
            }
        case 4:{
            infotype x;
            cout<<"Input ID : ";
            cin>>x.id;
            address id = findElm(L,x);
            if(x.id!= NULL){
                edit_data(info(P));
                edit_data2(info2(P));
            }else{
                cout<<"ID not Exist"<<endl;
            }
            break;
        }
       case 5:{
            infotype x;
            cout<<"Input ID : ";
            cin>>x.id;
            deletebyID(L,x);
            }
        }
    }
     while(true);

    //----------------------------------------
}
