
#include "my_data2.h"

/**
    CLASS      : IF 40 INT
    NAME       : RANDY KUSTIWA KOESMA
    STUDENT ID : 1301162472
**/

mytype2 create_data(mytype2 x2) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"your code here"<<endl;

    cout<<"===** LECTURER **==="<<endl;
    cout<<"Input ID      : ";cin>>d.id_lec;
    cout<<"Input Name    : ";cin>>d.name_lec;
    cout<<"Input Subject : ";cin>>d.clas_lec;



    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"your code here"<<endl;

        string beforeUpdateName = d.name_lec;
        cout<<"===** LECTURER **==="<<endl;
        cout<<"Input New Name    : ";
        cin>>d.name_lec;
        cout<<"Input New Subject : ";
        cin>>d.clas_lec;
        cout<<beforeUpdateName<<" Updated become : "<<d.name_lec<<endl;
        cout<<endl;



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
        cout<<"Input New Name    : ";
        cin>>d.name_lec;
        cout<<"Input New Subject : ";
        cin>>d.clas_lec;
        cout<<beforeUpdateName<<" Updated become : "<<d.name_lec<<endl;
        cout<<endl;


    // ===========================
}

