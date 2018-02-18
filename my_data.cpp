
#include "my_data.h"

/**
    CLASS      :IF-41-08
    NAME       :Muchtarom Yahya
    STUDENT ID :1301174052
**/

mytype create_data(mytype x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Masukan Kode Barang      =";cin>>d.id;
    cin.get();
    cout<<"Masukan Nama Barang      =";cin>>d.nama;
    cout<<"Masukan Kategori Barang  =";cin>>d.kategori;
    cout<<"Masukan Harga Barang     =Rp. ";cin>>d.harga;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"kode            ="<<d.id<<endl;
    cout<<"Nama Barang     ="<<d.nama<<endl;
    cout<<"kategori        ="<<d.kategori<<endl;
    cout<<"Harga           = Rp."<<d.harga<<endl;




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
        cout<<"Masukan nama barang baru     =";cin.getline(d.nama,30);
        cout<<"Masukan kategori barang baru =";cin.getline(d.kategori,25);
        cout<<"Masukan harga barang baru    = Rp.";cin>>d.harga;



    // ===========================
}

