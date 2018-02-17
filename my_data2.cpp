#include "my_data2.h"

mytype2 create_data(mytype2 x){
    mytype2 a;
    cout<<"Masukkan Nama Dosen : ";
    cin>>a.nama;
    cout<<"Masukkan ID dosen : ";
    cin>>a.id;
    cout<<"Masukkan Fakultas : ";
    cin>> a.fkl;
    return a;
    }

void view_data(mytype2 a){
    cout<<"nama     : "<<a.nama<<" "<<endl;
    cout<<"ID       : "<<a.id<<"" ""<<endl;
    cout<<"Fakultas : "<<a.fkl<<"" ""<<endl;

    }
void edit_data(mytype2 &a){

    cout<<"Masukkan Nama Dosen : ";
    cin>> a.nama;
    cout<<"Masukkan Fakultas : ";
    cin>> a.fkl;
    }
