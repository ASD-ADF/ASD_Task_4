
#include "my_data.h"

/**
    CLASS      : IF 40 INT
    NAME       : Purnama Sari Nur Mellinda
    STUDENT ID : 1301160541
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<endl;
    cout<<"======== MY DATA ========"<<endl;
    cout<<"Name: ";d.name;cin>>d.name;
    cout<<"Class: ";cin>>d.clas;
    cout<<"ID: ";cin>>d.id;
    cout<<"Score: ";cin>>d.score;
    cout<<endl;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<endl;
    cout<<"======== VIEW DATA ========"<<endl;
    cout<<"Name: "<<d.name<<endl;
    cout<<"Class: "<<d.clas<<endl;
    cout<<"ID: "<<d.id<<endl;
    cout<<"Score: "<<d.score<<endl;
    cout<<endl;
   // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<endl;
    cout<<"======== NEW DATA ========"<<endl;
    cout<<"Name: ";cin>>d.name;
    cout<<"Class: ";cin>>d.clas;
    cout<<"ID: ";cin>>d.id;
    cout<<"Score: ";cin>>d.score;
    cout<<endl;
    // ===========================
}

