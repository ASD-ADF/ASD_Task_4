#include "my_data2.h"

/**
    CLASS      : IF-41-08
    NAME       : Muchtarom Yahya
    STUDENT ID : 1301174052
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukan Kode          : "; cin>>d.id;
    cin.get();
    cout<<"Masukan Nama          : "; cin.getline(d.nama, 30);
    cout<<"Masukan Usia          : "; cin>>d.usia;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"kode       : "<<d.id<<endl;
    cout<<"Nama       : "<<d.nama<<endl;
    cout<<"Usia       : "<<d.usia<<endl;
    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cin.get();
    cout<<"Masukan nama baru   : "; cin.getline(d.nama, 30);
    cout<<"Masukan usia baru : "; cin>>d.usia;
    // ===========================
}
