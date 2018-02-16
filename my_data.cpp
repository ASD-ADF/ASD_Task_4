#include <conio.h>
#include <stdio.h>
#include <string>
#include "my_data.h"

/**
    CLASS      : IF 41-08
    NAME       : Gery Nugroho
    STUDENT ID : 1301170116
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan ID    :  ";
    cin>>d.ID;
    cin.get();
    cout<<"Masukkan Nama  :  ";
    gets(d.nama);
    cout<<"Masukkan Kelas :  ";
    gets(d.kelas);

    cout<<"Masukkan Nilai :  ";
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
    cout<<"ID    : "<<d.ID<<endl;
    cout<<"Nama  : "<<d.nama<<endl;
    cout<<"Kelas : "<<d.kelas<<endl;
    cout<<"Nilai : "<<d.nilai<<endl;
    cout<<endl;




    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cin.get();
    cout<<"Masukkan Nama  :  ";
    gets(d.nama);
    cout<<"Masukkan Kelas :  ";
    gets(d.kelas);
    cout<<"Masukkan Nilai :  ";
    cin>>d.nilai;




    // ===========================
}

