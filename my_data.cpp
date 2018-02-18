
#include "my_data.h"

/**
    CLASS      : IF 39 INT
    NAME       : M. Ihsan Amien I.
    STUDENT ID : 13011532628
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;

    cout<<"ID: ";
    cin>>d.id;
    cout<<"Name: ";
    cin>>d.name;
    cout<<"NIM: ";
    cin>>d.nim;
    cout<<"Score: ";
    cin>>d.score;

    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    cout<<"ID: "<<d.id<<endl;
    cout<<"Name: "<<d.name<<endl;
    cout<<"NIM: "<<d.nim<<endl;
    cout<<"Score: "<<d.score<<endl;

}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    cout<<"Name  : ";
    cin>>d.name;
    cout<<"NIM: ";
    cin>>d.nim;
    cout<<"Score   : ";
    cin>>d.score;

}

