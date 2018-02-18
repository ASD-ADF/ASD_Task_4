
#include "my_data.h"

/**
    CLASS      :IF-40-INT
    NAME       :gede b. wiswa pranata
    STUDENT ID :1301160413
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout << "Input ID : ";
    cin >> d.id;
    cout << "Input Name : ";
    cin >> d.name;
    cout << "Input Faculty : ";
    cin >> d.fac;
    cout << "Input Score : ";
    cin >> d.score;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout << "ID     : " << d.id << endl;;
    cout << "Name   : " << d.name << endl;
    cout << "Faculty: " << d.fac << endl;
    cout << "Score  : " << d.score << endl;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout << "Input Name     : ";
    cin >> d.name;
    cout << "Input Faculty      : ";
    cin >> d.fac;
    cout << "Input Score    : ";
    cin >> d.score;
    // ===========================
}

