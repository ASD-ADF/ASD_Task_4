#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED

#include <iostream>
using namespace std;

struct mytype2{
string nama;
int id;
string fkl;
};

mytype2 create_data(mytype2 x);
void view_data(mytype2 d);
void edit_data(mytype2 &d);



#endif // MY_DATA2_H_INCLUDED
