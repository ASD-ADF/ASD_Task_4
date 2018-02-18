
#include "my_data.h"

/**
    CLASS      : IF- 41- 08
    NAME       : Aanisah Rifda Rusjdy
    STUDENT ID : 1301174057
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Insert ID   : ";
    cin>>d.id;
    cout<<"Insert Name : ";
    cin>>d.nama;
    cout<<"Insert Class: ";
    cin>>d.kelas;
    cout<<"Insert Score: ";
    cin>>d.nilai;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID     : "<<d.id<<" "<<endl;
    cout<<"Name   : "<<d.nama<<" "<<endl;
    cout<<"Class  : "<<d.kelas<<" "<<endl;
    cout<<"Score  : "<<d.nilai<<" "<<endl;
    // ===========================
}

void edit_data(mytype &d) {
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
        cout<<"Insert Score : ";
        cin>>d.nilai;
    // ===========================
}
