
#include "my_data2.h"

/**
    CLASS      : IF-41-08
    NAME       : Muhammad Mukhtar Dwi Putra
    STUDENT ID : 1301170278
**/

mytype2 create_data(mytype2 &D)
{
    /**
     TODO:  receive input from user
            and assign the value of new data
    */

    // ===========================
    // YOUR CODE HERE
    cout << "Masukkan ID : ";
    cin >> D.id;
    cout << "Fakultas: ";
    cin >> D.fakultas;
    cout << "Jurusan : ";
    cin >> D.jurusan;
    // ===========================
    return D;
}

void view_data(mytype2 d)
{
    /**
     TODO:  view the content of data d
    */
    // ===========================
    // YOUR CODE HERE
    cout << "ID  : " << d.id << endl;;
    cout << "Fakultas : " << d.fakultas << endl;
    cout << "Jurusan : " << d.jurusan << endl;
    // ===========================
}


void edit_data(mytype2 &d)
{
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout << "Fakultas : ";
    cin >> d.fakultas;
    cout << "Jurusan : ";
    cin >> d.jurusan;
    // ================
}
