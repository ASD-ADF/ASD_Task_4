#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED

#include <iostream>
using namespace std;

/**
    CLASS      : IF-41-08
    NAME       : Rachmansyah Adhi Widhianto
    STUDENT ID : 1301170066
**/

struct mytype2 {
    /**
     TODO:  create a new Data type with specification:
            - an integer variable acted as an ID
            - two other variables
    */
    //=================================================
    // YOUR CODE STARTS HERE
    int team_id;
    string team_name;
    string team_homebase;
    // YOUR CODE ENDS HERE
    //=================================================
};

mytype2 create_data_team();
void view_data_team(mytype2 d);
void edit_data_team(mytype2 &d);

#endif // MY_DATA2_H_INCLUDED
