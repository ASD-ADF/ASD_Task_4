
#include "my_data.h"

/**
    CLASS      : IF-40-INT
    NAME       : Muhammad Naimullah
    STUDENT ID : 1301160449
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Input Your Data :"<<endl;
    cout<<"Your Name?"<<endl;
    cin>>d.nama;
    cout<<"Your ID?"<<endl;
    cin>>d.id;
    cout<<"Your Class?"<<endl;
    cin>>d.kelas;
    cout<<"What's score?"<<endl;
    cin>>d.nilai;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Nama ="<<d.nama<<endl;
    cout<<"ID ="<<d.id<<endl;
    cout<<"Class ="<<d.kelas<<endl;
    cout<<"Score ="<<d.nilai<<endl;





    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"New Name Maybe?"<<endl;
        cin>>d.nama;
        cout<<"New Class maybe?"<<endl;
        cin>>d.kelas;
        cout<<"What's the new score?"<<endl;
        cin>>d.nilai;





    // ===========================
}

