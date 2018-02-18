
#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : M. fadhil ihsan
    STUDENT ID : 1301170505
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukkan Nama anda: "<<endl;
    cin>>d.nama;
    cout<<"Masukkan ID anda: "<<endl;
    cin>>d.id;
    cout<<"Masukkan Kelas anda: "<<endl;
    cin>>d.kelas;
    cout<<"Masukkan Nilai anda: "<<endl;
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
    cout<<"Nama Anda: "<<d.nama<<endl;
    cout<<"Nama ID: "<<d.id<<endl;
    cout<<"Nama Kelas: "<<d.kelas<<endl;
    cout<<"Nama Nilai: "<<d.nilai<<endl;




    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    char jawaban;
    cout<<"Ingin mengedit Nama anda?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Nama anda: "<<endl;
        cin>>d.nama;
    }
    cout<<"Maaf ID tidak bisa diubah: "<<endl;
    cout<<"Ingin mengedit Kelas anda?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Kelas anda: "<<endl;
        cin>>d.kelas;
    }
    cout<<"Ingin mengedit Nilai anda?: ";
    cin>>jawaban;
    if (jawaban == 'y')
    {
        cout<<"Masukkan Nilai anda: "<<endl;
        cin>>d.nilai;
    }





    // ===========================
}

