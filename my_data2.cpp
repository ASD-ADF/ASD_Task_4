#include "my_data2.h"

/**
    CLASS      : IF- 41- 08
    NAME       : Aanisah Rifda Rusjdy
    STUDENT ID : 1301174057
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Insert ID   : ";
    cin>>d.id;
    cout<<"Insert Name : ";
    cin>>d.nama;
    cout<<"Insert Class: ";
    cin>>d.kelas;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID    : "<<d.id<<" "<<endl;
    cout<<"Name  : "<<d.nama<<" "<<endl;
    cout<<"Class : "<<d.kelas<<" "<<endl;
    // ===========================
}

void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"Insert Name  : ";
        cin>>d.nama;
        cout<<"Insert Class : ";
        cin>>d.kelas;
    // ===========================
}
