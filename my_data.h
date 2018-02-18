#ifndef MY_DATA_H_INCLUDED
#define MY_DATA_H_INCLUDED

#include <iostream>
using namespace std;

/**
    CLASS      : IF-40-INT
    NAME       : Muhammad Naimullah
    STUDENT ID : 1301160449
**/

struct mytype {
    /**
     TODO:  create a new Data type with specification:
            - an integer variable acted as an ID
            - two other variables
            - a float variable
    */
    //=================================================
    // YOUR CODE STARTS HERE
    int id;
    string nama;
    string kelas;
    double nilai;


    // YOUR CODE ENDS HERE
    //=================================================
};


mytype create_data(mytype x);
void view_data(mytype d);
void edit_data(mytype &d);

#endif // MY_DATA_H_INCLUDED
