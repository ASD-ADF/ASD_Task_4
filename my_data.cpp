
#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : IRIYANTO
    STUDENT ID : 1301174295
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Enter game ID    : "; cin>>d.id;
    cin.get();
    cout<<"Enter game Name  : "; cin.getline(d.name, 30);
    cout<<"Enter game Genre : "; cin.getline(d.genre, 30);
    cout<<"Enter game Price : "; cin>>d.price;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID       : "<<d.id<<endl;
    cout<<"Name     : "<<d.name<<endl;
    cout<<"Genre    : "<<d.genre<<endl;
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
    cout<<"Enter new Genre : "; cin.getline(d.genre, 30);
    cout<<"Enter new Price : "; cin>>d.price;
    // ===========================
}

