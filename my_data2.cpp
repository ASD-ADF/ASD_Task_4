#include "my_data2.h"


mytype2 create_data()
{
    mytype2 d;

    cout<<"Masukkan ID    : ";
    cin>>d.id;
    cout<<"Masukkan Nama  : ";
    cin>>d.nama;
    cout<<"Masukkan Usia  : ";
    cin>>d.usia;
    cout<<endl;

    return d;
}


void view_data(mytype2 d)
{
    cout<<"ID   : "<<d.id<<endl;
    cout<<"Nama : "<<d.nama<<endl;
    cout<<"Usia : "<<d.usia<<endl;
    cout<<endl;
}

void edit_data(mytype2 &d)
{
    cout<<"ID  : "<<d2.id<<endl;
    cout<<"Edit Nama : ";
    cin>>d.nama;
    cout<<"Edit Usia : ";
    cin>>d.usia;
    cout<<endl;
}
