
#include "my_data.h"

/**
    CLASS      :IF 41 08
    NAME       :Hafizh Fadhilah R B
    STUDENT ID :1301170404
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<" ID  : ";
    cin>>d.id;
    cout<<"Judul : ";
    cin>>d.buku;
    cout<<"Tahun  : ";
    cin>>d.tahun;
    cout<<"Harga  : ";
    cin>>d.harga;




    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID   : "<<d.id<<endl;
    cout<<"Judul : "<<d.buku<<endl;
    cout<<"Tahun  : "<<d.tahun<<endl;
    cout<<"Harga  : "<<d.harga<<endl;





    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Judul: ";
    cin>>d.buku;
    cout<<"Tahun  : ";
    cin>>d.tahun;
    cout<<"Harga  : ";
    cin>>d.harga;




    // ===========================
}

