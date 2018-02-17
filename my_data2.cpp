#include "my_data2.h"

/**
    CLASS      : IF 40 INT
    NAME       : HASNA ZAKIYYAH
    STUDENT ID : 1301164599
**/

mytype2 create_data2(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"----Book's Detail----"<<endl;
    cout<<"Input Book's ID: ";cin>>d.idbook;
    cout<<"Input Book's Title: ";cin>>d.title;
    cout<<"Input Book's year: "; cin>>d.year;
    cout<<"Input Book's publisher: ";cin>>d.publish;
    cout<<"---------------------"<<endl;
    // ===========================
    return d;
}

void view_data2(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"----Book's Detail----"<<endl;
    cout<<"Book's ID      : "<<d.idbook<<endl;
    cout<<"Book's Title    : "<<d.title<<endl;
    cout<<"Book's Year  : "<<d.year<<endl;
    cout<<"Book's publisher: "<<d.publish<<endl;
    cout<<"---------------------"<<endl;
    // ===========================
}


void edit_data2(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    string beforeUpdate=d.title;
    cout<<"--Update book's detail--"<<endl;
    cout<<"Input  new Title  : ";cin>>d.title;
    cout<<"Input new year of book: ";cin>>d.year;
    cout<<"Input new publisher: ";cin>>d.publish;
    cout<<beforeUpdate<<" Updated become "<<d.title<<endl;
    cout<<"------------------------"<<endl;

    // ===========================
}
