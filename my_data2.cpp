
#include "my_data2.h"

/**
    CLASS      :IF - 40 - INT
    NAME       :Muhammad Rizky Anugrah Sakti
    STUDENT ID :1301164489
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"===LECTURER==="<<endl;
    cout<<"input your id      : ";cin>>d.id_lec;
    cout<<"input your name    : ";cin>>d.name_lec;
    cout<<"input your Subject : ";cin>>d.clas_lec;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"===LECTURER==="<<endl;
    cout<<"Id     : "<<d.id_lec<<endl;
    cout<<"Name   : "<<d.name_lec<<endl;
    cout<<"Subject: "<<d.clas_lec<<endl;

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
        cout<<"Input new name    : ";
        cin>>d.name_lec;
        cout<<"Input new Subject : ";
        cin>>d.clas_lec;
        cout<<beforeUpdateName<<" Updated become "<<d.name_lec<<endl;
        cout<<endl;




    // ===========================
}

