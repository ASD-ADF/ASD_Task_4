
#include "my_data2.h"

/**
    CLASS      :IF-40-INT
    NAME       :gede b. wiswa pranata
    STUDENT ID :1301160413
**/
mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Input ID             :";
    cin>>d.id;
    cout<<"Input Phone Number   :";
    cin>>d.NOphone;
    cout<<"Input Study Program  :";
    cin>>d.study;




    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID               : "<<d.id<<endl;
    cout<<"Number Phone     : "<<d.NOphone<<endl;
    cout<<"Study Program    : "<<d.study<<endl;




    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cin.get();
    cout<<"Number Phone     :";
    cin>>d.NOphone;
    cout<<"Study Program   :";
    cin>>d.study;



    // ===========================
}

