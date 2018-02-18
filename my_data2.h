#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED


#include <iostream>
using namespace std;

/**
    CLASS      : IF 41-08
    NAME       : Muhammad Rayhan Alifinzi Ghiffari
    STUDENT ID : 1301174145
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


    int nim;
    string nama;
    string kelas;
    float gpa;


    // YOUR CODE ENDS HERE
    //=================================================
};


mytype2 create_data();
void view_data(mytype2 d);
void edit_data(mytype2 &d);



#endif // MY_DATA2_H_INCLUDED
