
#include "my_data.h"

/**
    CLASS      : IF 40 INT
    NAME       : Muhammad Rich-q R
    STUDENT ID : 1301160456
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<" == Input Stud Info == "<<endl;
    cout<<"Input ID   :  "; cin>>d.id;
    cout<<"Input name :  "; cin>>d.name;
    cout<<"Input Class:  "; cin>>d.Class;
    cout<<"Input Score:  "; cin>>d.score;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<" == THE DATA == "<<endl;
    cout<<"ID    : "<<d.id<<endl;
    cout<<"Name  : "<<d.name<<endl;
    cout<<"Class : "<<d.Class<<endl;
    cout<<"Score : "<<d.score<<endl;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    string beforeUpdateName = d.name;
    cout<<" == Student New info == "<<endl;
    cout<<"Input Name : ";
    cin>>d.name;
    cout<<"Input Class: ";
    cin>>d.Class;
    cout<<"Input Score: ";
    cin>>d.score;
    cout<<beforeUpdateName<<" == Edited to "<<d.name<<endl;
    cout<<endl;
    // ===========================
}

