
#include "my_data.h"

/**
    CLASS      : IF 40 INT
    NAME       : RANDY KUSTIWA KOESMA
    STUDENT ID : 1301162472
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"your code here"<<endl;
    cout<<"==**STUDENT**=="<<endl;
    cout<<"Input ID    : ";cin>>d.id;
    cout<<"Input Name  : ";cin>>d.name;
    cout<<"Input Class : ";cin>>d.clas;
    cout<<"input Score : ";cin>>d.score;



    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"your code here"<<endl;
    cout<<"========** DATA **========"<<endl;
    cout<<"ID    : "<<d.id<<endl;
    cout<<"Name  : "<<d.name<<endl;
    cout<<"Class : "<<d.clas<<endl;
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
        cout<<"your code here"<<endl;
        string beforeUpdateName = d.name;
        cout<<"===** STUDENT **==="<<endl;
        cout<<"Input New Name : ";
        cin>>d.name;
        cout<<"Input New Class : ";
        cin>>d.clas;
        cout<<"Input New Score : ";
        cin>>d.score;
        cout<<beforeUpdateName<<" Updated become : "<<d.name<<endl;
        cout<<endl;



    // ===========================
}

