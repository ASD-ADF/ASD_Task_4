
#include "my_data2.h"

/**
    CLASS      : IF 41-08
    NAME       : Muhammad Khaifa Gifari
    STUDENT ID : 1301170382
**/

mytype2 create_data(mytype2 &D) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan ID : "<<endl;
    cin>>D.id;
    cout<<"Universitas : "<<endl;
    cin>>D.kampus;
    cout<<"Program Studi : "<<endl;
    cin>>D.prodi;

    // ===========================
    return D;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID : "<<d.id<<endl;
    cout<<"Universitas : "<< d.kampus <<endl;
    cout<<"Program Studi : "<< d.prodi <<endl;
    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"Universitas : ";
        cin>> d.kampus;
        cout<<"Program Studi : ";
        cin>> d.prodi;
    // ===========================
}

