#ifndef MY_DATA_H_INCLUDED
#define MY_DATA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/**
CLASS      : IF39INT
NAME       : Pertiwang Sismananda
STUDENT ID : 1301153614
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
	int id, weight, height;
	float variable;
	// YOUR CODE ENDS HERE
	//=================================================
};


mytype2 create_data();
void view_data(mytype2 d);
void edit_data(mytype2 &d);

#endif // MY_DATA_H_INCLUDED
