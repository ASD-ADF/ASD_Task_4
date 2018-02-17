
#include "my_data.h"

/**
    CLASS      : IF 40 INT
    NAME       : Hasna Zakiyyah
    STUDENT ID : 1301164599
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"--Student's biodata--"<<endl;
    cout<<"ID   : ";cin>>d.id;
    cout<<"Name : ";cin>>d.name;
    cout<<"Class : ";cin>>d.clas;
    cout<<"Score: ";cin>>d.score;
    cout<<"---------------------"<<endl;

    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"--------------"<<endl;
    cout<<"ID   :"<<d.id<<endl;
    cout<<"Name : "<<d.name<<endl;
    cout<<"Class : "<<d.clas<<endl;
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
    string beforeUpdate=d.name;
    cout<<"--Student's update biodata--"<<endl;
    cout<<"Enter new Name : ";cin>>d.name;
    cout<<"Enter new Class : ";cin>>d.clas;
    cout<<"Enter new Score: ";cin>>d.score;
    cout<<beforeUpdate<<" Updated become "<<d.name<<endl;
    cout<<"----------------------------"<<endl;
    // ===========================
}

