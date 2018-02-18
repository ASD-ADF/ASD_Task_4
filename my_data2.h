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
            - a float variable
    */
    //=================================================
    // YOUR CODE STARTS HERE
    int id;
    string name;
    string nim;
    float score;
    // YOUR CODE ENDS HERE
    //=================================================
};


mytype2 create_data2();
void view_data(mytype2 d);
void edit_data(mytype2 &d);
#endif // MY_DATA2_H_INCLUDED
