
#include "my_data.h"

/**
    CLASS      : IF 40 INT
    NAME       : Muhammad Rich-q R
    STUDENT ID : 1301160456
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<" == Input Stud Info == "<<endl;
    cout<<"Input ID   :  "; cin>>d.id_lec;
    cout<<"Input name :  "; cin>>d.name_lec;
    cout<<"Input Class:  "; cin>>d.Class_lec;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<" == THE DATA == "<<endl;
    cout<<"ID    : "<<d.id_lec<<endl;
    cout<<"Name  : "<<d.name_lec<<endl;
    cout<<"Class : "<<d.Class_lec<<endl;
    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    string beforeUpdateName = d.name;
    cout<<" == Student New info == "<<endl;
    cout<<"Input Name : ";
    cin>>d.name_lec;
    cout<<"Input Class: ";
    cin>>d.Class_lec;
    cout<<beforeUpdateName<<" == Edited to "<<d.name<<endl;
    cout<<endl;




    // ===========================
}

