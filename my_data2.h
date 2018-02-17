#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED

//#ifndef MY_DATA_H_INCLUDED
//#define MY_DATA_H_INCLUDED

#include <iostream>
using namespace std;

/**
    CLASS      : IF 41-08
    NAME       : Fareza adityanto
    STUDENT ID : 1301174228
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
    int ID;
    string name;
    string isbn;
    float score;

    // YOUR CODE ENDS HERE
    //=================================================
};


mytype create_data();
void view_data(mytype d);
void edit_data(mytype &d);

#endif // MY_DATA2_H_INCLUDED
