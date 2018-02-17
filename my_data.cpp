
#include "my_data.h"

/**
    CLASS      : If 41-08
    NAME       : Fareza Adityanto
    STUDENT ID : 1301174228
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"your code here"<<endl;

    cout<<"Masukkan id = ";
    cin>>d.ID;
    cout<<"Masukkan judul buku = ";
    cin>>d.name;
    cout<<"Masukkan isbn = ";
    cin>>d.isbn;
    cout<<"Masukkan score buku = ";
    cin>>d.score;

    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"your code here"<<endl;

    cout<<"id = "<<d.ID<<endl;
    cout<<"judul = "<<d.name<<endl;
    cout<<"isbn ="<<d.isbn<<endl;
    cout<<"score = "<<d.score<<endl;
    cout<<"============================"<<endl;

    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"your code here"<<endl;

        cout<<"ID anda adalah = "<<d.ID<<endl;
        cout<<"-----------edit data---------------"<<endl;
        cout<<"Masukkan judul baru = ";
        cin>>d.name;
        cout<<"Masukkan isbn baru = ";
        cin>>d.isbn;
        cout<<"Masukkan reviewed score baru = ";
        cin>>d.score;

    // ===========================
}

