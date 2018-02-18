#ifndef MY_DATA_H_INCLUDED
#define MY_DATA_H_INCLUDED

#include "my_data2.h"
#include <iostream>
using namespace std;

/**
    CLASS      : IF 41-08
    NAME       : Muhammad Khaifa Gifari
    STUDENT ID : 1301170382
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
    string nim;
    float nilai;
    // YOUR CODE ENDS HERE
    //=================================================
};


mytype create_data(mytype &d);
void view_data(mytype d);
void edit_data(mytype &d);

#endif // MY_DATA_H_INCLUDED
