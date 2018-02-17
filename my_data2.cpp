
#include "my_data2.h"

/**
    CLASS      : IF 39 INT
    NAME       : M. Ihsan Amien I
    STUDENT ID : 1301153628
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Enter Film ID            : "; cin>>d.id;
    cin.get();
    cout<<"Enter Film Name          : "; cin>>d.name;
    cout<<"Enter Film Rating (1-10) : "; cin>>d.rating;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID       : "<<d.id<<endl;
    cout<<"Name     : "<<d.name<<endl;
    cout<<"Rating   : "<<d.rating<<endl;
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
    cout<<"Enter new Name   : "; cin>>d.name;
    cout<<"Enter new Rating : "; cin>>d.rating;
    // ===========================
}

