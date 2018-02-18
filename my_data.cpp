
#include "my_data.h"

/**
    CLASS      : IF 41 08
    NAME       : Ahmad Satriamulya
    STUDENT ID :
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan ID Member : ";
    cin>>d.id;
    cout<<"Masukkan Nama      : ";
    cin>>d.nama;
    cout<<"Masukkan Nomor HP  : ";
    cin>>d.no_telp;
    cout<<"Masukkan Umur      : ";
    cin>>d.umur;
    cout<<endl;




    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Member ID   : "<<d.id<<endl;
    cout<<"Nama        : "<<d.nama<<endl;
    cout<<"Nomor HP    : "<<d.no_telp<<endl;
    cout<<"Umur        : "<<d.umur<<endl<<endl;




    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID  : "<<d.id<<endl;
    cout<<"Edit Nama : ";
    cin>>d.nama;
    cout<<"Edit NIM  : ";
    cin>>d.no_telp;
    cout<<"Edit IPK  : ";
    cin>>d.umur;
    cout<<endl;




    // ===========================
}

