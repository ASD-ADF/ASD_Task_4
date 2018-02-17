
#include "my_data2.h"

/**
    CLASS      :
    NAME       :
    STUDENT ID :
**/

mytype2 create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"ID: ";
    cin>>d.id;
    cout<<"Judul Film 1: ";
    cin>>d.film1;
    cout<<"Judul Film 2: ";
    cin>>d.film2;




    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID: "<<d.id<<endl;
    cout<<"Film yang sedang tayang:"<<endl;
    cout<<"1. "<<d.film1<<endl;
    cout<<"2. "<<d.film2<<endl;




    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID Bioskop: "<<d.id;
    cout<<"Film yang sedang tayang: "<<endl;
    cout<<"1. "<<d.film1<<endl;
    cout<<"2. "<<d.film2<<endl;
    cout<<"Film baru yang akan tayang: "<<endl;
    cout<<"1: ";
    cin>>d.film1;
    cout<<"2: ";
    cin>>d.film2;





    // ===========================
}

