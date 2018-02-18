#include "my_data2.h"
/**
    CLASS      :IF 41 08
    NAME       :Hafizh Fadhilah R B
    STUDENT ID :1301170404
**/

mytype2 create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytypeII d1;
    // ===========================
    // YOUR CODE HERE
    cout<<" ID  : ";
    cin>>d1.id;
    cout<<"Toko : ";
    cin>>d1.toko;
    cout<<"Kota  : ";
    cin>>d1.kota;





    // ===========================
    return d1;
}

void view_data(mytypeII d1) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID   : "<<d1.id<<endl;
    cout<<"Toko : "<<d1.toko<<endl;
    cout<<"Kota  : "<<d1.kota<<endl;





    // ===========================
}


void edit_data(mytypeII &d1) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Toko : ";
    cin>>d1.toko;
    cout<<"Kota  : ";
    cin>>d1.kota;





    // ===========================
}
