
#include "my_data.h"

/**
    CLASS      : IF-40-INT
    NAME       : Aditya Ramadhan Moesya
    STUDENT ID : 1301160471
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"STUDENT"<<endl;
    cout<<"ID       : ";cin>>d.id;
    cout<<"NAME     : ";cin>>d.name;
    cout<<"CLASS    : ";cin>>d.clas;
    cout<<"SCORE    : ";cin>>d.score;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"DATA"<<endl;
    cout<<"ID       : "<<d.id<<endl;
    cout<<"NAME     : "<<d.name<<endl;
    cout<<"CLASS    : "<<d.clas<<endl;
    cout<<"SCORE    : "<<d.score<<endl;
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
    cout<<"===STUDENT==="<<endl;
    cout<<"NAME     : ";
    cin>>d.name;
    cout<<"CLASS    : ";
    cin>>d.clas;
    cout<<"SCORE    : ";
    cin>>d.score;
    cout<<beforeUpdateName<<"UPDATED    :"<<d.name<<endl;
    cout<<endl;
    // ===========================
}

