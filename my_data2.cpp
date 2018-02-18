
#include "my_data2.h"

/**
    CLASS      : IF-40-INT
    NAME       : Aditya Ramadhan Moesya
    STUDENT ID : 1301160471
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"LECTURER"<<endl;
    cout<<"ID       : ";cin>>d.id_lec;
    cout<<"NAME     : ";cin>>d.name_lec;
    cout<<"SUBJECT  : ";cin>>d.sub;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"LECTURER"<<endl;
    cout<<"ID     : "<<d.id_lec<<endl;
    cout<<"NAME   : "<<d.name_lec<<endl;
    cout<<"SUBJECT: "<<d.sub<<endl;
    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    string beforeUpdateName = d.name_lec;
    cout<<"===LECTURER==="<<endl;
    cout<<"NAME    : ";
    cin>>d.name_lec;
    cout<<"Input new Subject : ";
    cin>>d.sub;
    cout<<beforeUpdateName<<" Updated become "<<d.name_lec<<endl;
    cout<<endl;
    // ===========================
}

