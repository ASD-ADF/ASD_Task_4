#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED
#include <iostream>

using namespace std;

/**
    CLASS      : IF 40 INT
    NAME       : HASNA ZAKIYYAH
    STUDENT ID : 1301164599
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
    int idbook;
    char title[40],publish[40];
    float year;

    // YOUR CODE ENDS HERE
    //=================================================
};


mytype2 create_data2(mytype2 x);
void view_data2(mytype2 d);
void edit_data2(mytype2 &d);

#endif // MY_DATA2_H_INCLUDED
