
#include "my_data2.h"

/**
    CLASS      : IF-41-08
    NAME       : M. fadhil ihsan
    STUDENT ID : 1301170505
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout << "Masukkan ID : "<<endl;
    cin >> d.id;
    cout << "Fakultas: "<<endl;
    cin >> d.fakultas;
    cout << "Jurusan : "<<endl;
    cin >> d.jurusan;




    // ===========================
    return d;
}

void view_data(mytype2 d) {
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


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    char jawaban;
    cout<<"Ingin mengedit Jurusan anda?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Jurusan anda: "<<endl;
        cin>>d.jurusan;
    }
    cout<<"Maaf ID tidak bisa diubah: "<<endl;
    cout<<"Ingin mengedit Fakultas anda?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Fakultas anda: "<<endl;
        cin>>d.fakultas;
    }




    // ===========================
}

