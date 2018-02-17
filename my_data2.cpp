
#include "my_data2.h"

/**
    CLASS      : IF-41-08
    NAME       : IRIYANTO
    STUDENT ID : 1301174295
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Enter game ID            : "; cin>>d.id;
    cin.get();
    cout<<"Enter game Name          : "; cin.getline(d.name, 30);
    cout<<"Enter game Rating (1-10) : "; cin>>d.rating;
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
    cout<<"Enter new Name   : "; cin.getline(d.name, 30);
    cout<<"Enter new Rating : "; cin>>d.rating;
    // ===========================
}

