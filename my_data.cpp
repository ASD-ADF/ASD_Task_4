#include "my_data.h"


mytype create_data()
{
    mytype d;

    cout<<"Masukkan ID    : ";
    cin>>d.id;
    cout<<"Masukkan Nama  : ";
    cin>>d.nama;
    cout<<"Masukkan NIM  : ";
    cin>>d.nim;
    cout<<"Masukkan IPk : ";
    cin>>d.ipk;
    cout<<endl;

    return d;
}


void view_data(mytype d)
{
    cout<<"ID   : "<<d.id<<endl;
    cout<<"Nama : "<<d.nama<<endl;
    cout<<"NIM  : "<<d.usia<<endl;
    cout<<"IPK  : "<<d.ipk<<endl;
    cout<<endl;
}

void edit_data(mytype &d)
{
    cout<<"ID  : "<<d.id<<endl;
    cout<<"Edit Nama : ";
    cin>>d.nama;
    cout<<"Edit NIM  : ";
    cin>>d.nim;
    cout<<"Edit IPK  : ";
    cin>>d.ipk;
    cout<<endl;
}
