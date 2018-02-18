#include "my_data2.h"
#include "my_data.h"

/**
    CLASS      : IF 41-08
    NAME       : Muhammad Khaifa Gifari
    STUDENT ID : 1301170382
**/

mytype create_data(mytype &d) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan ID : "<<endl;
    cin>>d.id;
    cout<<"Masukkan Nama : "<<endl;
    cin>>d.nama;
    cout<<"Masukkan NIM : "<<endl;
    cin>>d.nim;
    cout<<"Masukkan Nilai : "<<endl;
    cin>>d.nilai;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID : "<< d.id << endl;
    cout<<"Nama : "<< d.nama << endl;
    cout<<"NIM : "<< d.nim << endl;
    cout<<"Nilai : "<< d.nilai << endl;

    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan Nama : "<<endl;
    cin>>d.nama;
    cout<<"Masukkan NIM : "<<endl;
    cin>>d.nim;
    cout<<"Masukkan Nilai : "<<endl;
    cin>>d.nilai;

    // ===========================
}

