#ifndef MY_DATA2_H_INCLUDED
#define MY_DATA2_H_INCLUDED


#include <iostream>
using namespace std;

/**
    CLASS      :IF 41 08
    NAME       :Hafizh Fadhilah R B
    STUDENT ID :1301170404
**/

struct mytypeII {
    /**
     TODO:  create a new Data type with specification:
            - an integer variable acted as an ID
            - two other variables

    */
    //=================================================
    int id;
    string toko;
    string kota;

    //=================================================
};


mytypeII create_data(mytypeII &d1);
void view_data(mytypeII d1);
void edit_data(mytypeII &d1);

#endif // MY_DATA2_H_INCLUDED
