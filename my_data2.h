#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED

#include <iostream>
#include "my_data.h"
using namespace std;

/**
    CLASS      : IF-41-08
    NAME       : Nuurshadieq
    STUDENT ID : 1301171087
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
    string film1;
    string film2;

    // YOUR CODE ENDS HERE
    //=================================================
};

mytype2 create_data();
void view_data(mytype2 d);
void edit_data(mytype2 &d);

#endif // MY_DATA2_H_INCLUDED
