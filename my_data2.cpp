#include "my_data2.h"


mytype2 create_data2() {
    mytype2 d;

    cout<<"Masukkan ID        : ";
    cin>>d.id;
    cout<<"Masukkan Nama Dosen: ";
    cin>>d.gim_nama;
    cout<<"Masukkan Usia      : ";
    cin>>d.batas_umur;
    cout<<endl;

    return d;
}


void view_data(mytype2 d) {
    cout<<"ID        : "<<d.id<<endl;
    cout<<"Nama Dosen: "<<d.gim_nama<<endl;
    cout<<"Usia      : "<<d.batas_umur<<endl;
    cout<<endl;
}

void edit_data(mytype2 &d) {
    cout<<"ID Game: "<<d.id<<endl;
    cout<<"Edit Nama Gim      : ";
    cin>>d.gim_nama;
    cout<<"Edit Batasan Umur  : ";
    cin>>d.batas_umur;
    cout<<endl;
}
