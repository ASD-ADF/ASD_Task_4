#ifndef MY_DATA_H_INCLUDED
#define MY_DATA_H_INCLUDED

#include <iostream>
using namespace std;

/**
    CLASS      : IF-41-08
    NAME       : Nuurshadieq
    STUDENT ID : 1301171087
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
    string judul;
    string genre;
    float price;

    // YOUR CODE ENDS HERE
    //=================================================
};


mytype create_data1(mytype x);
void view_data1(mytype d);
void edit_data1(mytype &d);

#endif // MY_DATA_H_INCLUDED
