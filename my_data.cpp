
#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : Supra Yogi
    STUDENT ID : 1301174264
**/

mytype create_data(mytype d) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan ID Buku : ";
    cin>>d.id;
    cout<<"Masukkan Judul Buku : ";
    cin>>d.judul;
    cout<<"Masukkan Penerbit : ";
    cin>>d.penerbit;
    cout<<"Masukkan Harga Buku : ";
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
    cout<<"ID : "<<d.id<<endl;
    cout<<"Judul : "<<d.judul<<endl;
    cout<<"Penerbit : "<<d.penerbit<<endl;
    cout<<"Harga : "<<d.harga<<endl;




    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan Judul Buku Baru : ";
    cin>>d.judul;

    cout<<"Masukkan Penerbit Baru : ";
    cin>>d.penerbit;

    cout<<"Masukkan Harga Buku Baru : ";
    cin>>d.harga;




    // ===========================
}

