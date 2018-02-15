
#include "my_data.h"

/**
    CLASS      : IF 41  - 08
    NAME       : Justisio Yan Prawira Adam
    STUDENT ID : 1301174597
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan ID   : ";
    cin>>d.id;
    cout<<"Masukkan NIM  : ";
    cin>>d.nim;
    cout<<"Masukkan nama : ";
    cin>>d.nama;
    cout<<"Masukkan IPK  : ";
    cin>>d.ipk;
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
    cout<<"ID   : "<<d.id<<endl;
    cout<<"Nama : "<<d.nama<<endl;
    cout<<"NIM  : "<<d.nim<<endl;
    cout<<"IPK  : "<<d.ipk<<endl;
    cout<<endl;
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
    cout<<"Edit Nim  : ";
    cin>>d.nim;
    cout<<"Edit IPK  : ";
    cin>>d.ipk;
    cout<<endl;
    // ===========================
}

