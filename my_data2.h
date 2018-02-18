#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED

#include <iostream>
using namespace std;

struct mytype2 {
    int id;
    string gim_nama;
    int batas_umur;
};


mytype2 create_data();
void view_data(mytype2 d);
void edit_data(mytype2 &d);

#endif // MY_DATA2_H_INCLUDED
