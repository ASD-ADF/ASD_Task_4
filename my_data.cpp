
#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : IRBAH SALSABILA
    STUDENT ID : 1301174021
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan Nama  : ";
    cin >> d.nama;
    cout<<"Masukkan Kelas : ";
    cin>> d.kelas;
    cout<<"Masukkan NIM   : ";
    cin>> d.id;
    cout<<"Masukkan Nilai : ";
    cin>> d.nilai;




    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE

    cout<<"nama  : "<<d.nama<<" "<<endl;
    cout<<"Kelas : "<<d.kelas<<" "<<endl;
    cout<<"NIM   : "<<d.id<<"" ""<<endl;
    cout<<"Nilai : "<<d.nilai<<"" ""<<endl;



    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE

    cout<<"Masukkan Nama  : ";
    cin>> d.nama;
    cout<<"Masukkan Kelas : ";
    cin>> d.kelas;
    cout<<"Masukkan Nilai : ";
    cin>> d.nilai;



    // ===========================
}

