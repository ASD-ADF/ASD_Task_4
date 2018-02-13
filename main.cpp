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
        cout<<"Pilihan: ";
        cin>>choice;
        cout<<endl;
        switch(choice) {
        case 1:
            //for mytype, use X = create_data();
            //for mytype2, use X = create_data_team();
            X = create_data_team();
            P = allocate(X);
            insertAndSort(L,P);
            cout<<endl;
            break;
        case 2:
            if(first(L)!=NULL){
                printInfo(L);
            }
            else{
                cout<<"List kosong."<<endl<<endl;
            }
            break;
        case 3:
            if(first(L) != NULL){
                cout<<"Find and View"<<endl;
                cout<<"Input ID: ";
                //for mytype, use player_id
                //for mytype2, use team_id
                cin>>X.team_id;
                P = findElm(L,X);
                if(P!=NULL){
                    cout<<endl<<"Data ditemukan."<<endl;
                    //for mytype, use view_data
                    //for mytyoe2, use view_data_team
                    view_data_team(info(P));
                }
                else{
                    cout<<"Data tidak ditemukan."<<endl<<endl;
                }
            }
            else{
                cout<<"List kosong."<<endl<<endl;
            }
            break;
        case 4:
            if(first(L) != NULL){
                cout<<"Find and Edit"<<endl;
                cout<<"Input ID: ";
                cin>>X.team_id;
                P = findElm(L,X);
                if(P!=NULL){
                    //for mytyoe, use player_id
                    //for mytype2, use team_id
                    cout<<endl<<"Edit Data ID: "<<X.team_id<<endl;
                    //for mytyoe, use edit_data
                    //for mytype2, use edit_data_team
                    edit_data_team(info(P));
                    cout<<"Data telah diedit."<<endl<<endl;
                }
                else{
                    cout<<"Data tidak ditemukan."<<endl<<endl;
                }
            }
            else{
                cout<<"List kosong."<<endl<<endl;
            }
            break;
        case 5:
            if(first(L) != NULL){
                cout<<"Find and Delete"<<endl;
                cout<<"Input ID: ";
                //for mytyoe, use player_id
                //for mytype2, use team_id
                cin>>X.team_id;
                P = findElm(L,X);
                if(P!=NULL){
                    deletebyID(L,X);
                    cout<<"Data deleted."<<endl<<endl;
                }
                else{
                    cout<<"Data tidak ditemukan."<<endl<<endl;
                }
            }
            else{
                cout<<"List kosong."<<endl<<endl;
            }
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Tidak ada pilihan "<<choice<<" di menu."<<endl<<endl;
            break;
        }
    } while(true);

    //----------------------------------------
}
