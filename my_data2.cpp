
#include "my_data2.h"

/**
    CLASS      : IF-39-INT
    NAME       : Prabu Chaidir
    STUDENT ID : 1301153629
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"ID: ";
    cin>>d.id;
    cout<<"Name: ";
    cin>>d.name;
    cout<<"NIM: ";
    cin>>d.nim;
    cout<<"Score: ";
    cin>>d.score;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID: "<<d.id<<endl;
    cout<<"Name: "<<d.name<<endl;
    cout<<"NIM: "<<d.nim<<endl;
    cout<<"Score: "<<d.score<<endl;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Name  : ";
    cin>>d.name;
    cout<<"NIM: ";
    cin>>d.nim;
    cout<<"Score   : ";
    cin>>d.score;
    // ===========================
}

