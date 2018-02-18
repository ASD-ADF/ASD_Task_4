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
    infotype2 X2;
    bool exit = false;
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
            infotype m;
            cout<<"Input ID : ";
            cin>>m.id;
            address n = findElm(L,m);
            if(n != NULL){
                cout<<"-----STUDENT-----"<<endl;
                cout<<"ID    : ";
                cout<<info(n).id<<endl;
                cout<<"Nama  : ";
                cout<<info(n).nama<<endl;
                cout<<"Kelas : ";
                cout<<info(n).kelas<<endl;
                cout<<"Score : ";
                cout<<info(n).nilai<<endl;
                cout<<"-----Lecturer-----"<<endl;
                cout<<"ID      : ";
                cout<<info2(n).id<<endl;
                cout<<"Name    : ";
                cout<<info2(n).dosen<<endl;
                cout<<"Subject : ";
                cout<<info2(n).mapel<<endl;
            }else{
                cout<<"ID is not Found"<<endl;
            }
            break;
            }
        case 4:{
            infotype m;
            cout<<"Input ID : ";
            cin>>m.id;
            address n = findElm(L,m);
            if(n != NULL){
                edit_data(info(n));
                edit_data(info2(n));
            }else{
                cout<<"ID not Found"<<endl;
            }
            break;
        }
       case 5:{
            infotype m;
            cout<<"Input ID : ";
            cin>>m.id;
            deletebyID(L,m);
       }
       case 0:{
            exit = true;
            break;
       }
        }
    } while(!exit);

    //----------------------------------------
}
