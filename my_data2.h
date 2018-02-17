#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED

#include <iostream>
using namespace std;

/**
    CLASS      : IF 39 INT
    NAME       : M. Ihsan Amien I.
    STUDENT ID : 1301153628
**/

struct mytype2 {
    /**
     TODO:  create a new Data type with specification:
            - an integer variable acted as an ID
            - two other variables
    */
    //=================================================
    // YOUR CODE STARTS HERE
    int id;
    char name[30];
    float rating;
    // YOUR CODE ENDS HERE
    //=================================================
};

mytype2 create_data(mytype2 x);
void view_data(mytype2 d);
void edit_data(mytype2 &d);

#endif // MY_DATA2_H_INCLUDED
