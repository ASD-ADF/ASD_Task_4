
#include "my_data.h"

/**
    CLASS      :
    NAME       :
    STUDENT ID :
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"ID       : "<<d.id<<endl;
    cout<<"Name     : "<<d.name<<endl;
    cout<<"Type    : "<<d.type<<endl;
    cout<<"Price    : Rp."<<d.price<<endl;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cin.get();
    cout<<"ID       : "<<d.id<<endl;
    cout<<"Name     : "<<d.name<<endl;
    cout<<"Type    : "<<d.type<<endl;
    cout<<"Price    : Rp."<<d.price<<endl;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cin.get();
    cout<<"Enter new Name  : "; cin.getline(d.name, 30);
    cout<<"Enter new Genre : "; cin.getline(d.type, 30);
    cout<<"Enter new Price : "; cin>>d.price;
    // ===========================
}

