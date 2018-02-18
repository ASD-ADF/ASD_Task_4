#include "my_data2.h"


mytype2 create_data2()
{
    mytype2 d;

    cout<<"Masukkan ID        : ";
    cin>>d.id;
    cout<<"Masukkan Nama Dosen: ";
    cin>>d.nama;
    cout<<"Masukkan Usia      : ";
    cin>>d.usia;
    cout<<endl;

    return d;
}


void view_data(mytype2 d)
{
    cout<<"ID        : "<<d.id<<endl;
    cout<<"Nama Dosen: "<<d.nama<<endl;
    cout<<"Usia      : "<<d.usia<<endl;
    cout<<endl;
}

void edit_data(mytype2 &d)
{
    cout<<"ID             : "<<d.id<<endl;
    cout<<"Edit Nama Dosen: ";
    cin>>d.nama;
    cout<<"Edit Usia      : ";
    cin>>d.usia;
    cout<<endl;
}
