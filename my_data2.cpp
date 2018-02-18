
#include "my_data2.h"

/**
    CLASS      : IF-40-INT
    NAME       : Muhammad Naimullah
    STUDENT ID : 1301160449
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Input Your Data :"<<endl;
    cout<<"Your Name?"<<endl;
    cin>>d.dosen;
    cout<<"Your ID?"<<endl;
    cin>>d.id;
    cout<<"Your Subject?"<<endl;
    cin>>d.mapel;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Nama ="<<d.dosen<<endl;
    cout<<"ID ="<<d.id<<endl;
    cout<<"Subject ="<<d.mapel<<endl;
    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"New Name Maybe?"<<endl;
    cin>>d.dosen;
    cout<<"New Subject maybe?"<<endl;
    cin>>d.mapel;
    // ===========================
}

