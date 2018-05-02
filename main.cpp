#include <iostream>
#include "doublelist.h"
#include "operation.h"
#include "my_data.h"
#include "my_data2.h"

using namespace std;

void mainMenu();
    List L;
    infotype x;
    infotype2 x2;

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
            X2 = create_data(X2);
            P = allocate(X);
            insertFirst(L,P);
            insertAndSort(L,P);
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
            infotype in;
            cout<<"Input ID : ";
            cin>>ifo.id;
            address fo = findElm(L,in);
            if(fo != NULL){
                cout<<"=STUDENT="<<endl;
                cout<<"ID    : ";cout<<fo->info.id<<endl;
                cout<<"Nama  : ";cout<<fo->info.name<<endl;
                cout<<"Kelas : ";cout<<fo->info.clas<<endl;
                cout<<"Score : ";cout<<fo->info.score<<endl;
                cout<<"=Lecturer="<<endl;
                cout<<"ID      : ";cout<<fo->info2.id_lec<<endl;
                cout<<"Name    : ";cout<<fo->info2.name_lec<<endl;
                cout<<"Subject : ";cout<<fo->info2.clas_lec<<endl;
                cout<<"--------------"<<endl;
                }else{
                    cout<<"ID Not found/exist"<<endl;
                }
                break;
        case 4 :
            infotype in;
            cout<<"Input ID : ";
            cin>>ifo.id;
            address fo = findElm(L,in);
            if(fo != NULL){
                edit_data(info(fo));
                edit_data(info2(fo));
            }else{
                cout<<"ID Not found/exist"<<endl;
            }
            break;
        case 5 :
            infotype in;
            cout<<"Input ID : ";
            cin>>in.id;
            deletebyID(L,in);
            break;
        case 0 :
            cout << "Thank You " << endl;
            return;
            break;
        }
    } while(true);

    //----------------------------------------
}
