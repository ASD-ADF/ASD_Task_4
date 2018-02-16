#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED


#include <iostream>
using namespace std;

/**
    CLASS      : IF 41-08
    NAME       : Gery Nugroho
    STUDENT ID : 1301170116
**/

struct mytype2 {
    /**
     TODO:  create a new Data type with specification:
            - an integer variable acted as an ID
            - two other variables

    */
    //=================================================
    // YOUR CODE STARTS HERE
    int ID;
    char dosen[50];
    char matkul[50];

    // YOUR CODE ENDS HERE
    //=================================================
};


mytype2 create_data2();
void view_data2(mytype2 d);
void edit_data2(mytype2 &d);

#endif // MY_DATA_H_INCLUDED
