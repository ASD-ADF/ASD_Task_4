
#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : Nuurshadieq
    STUDENT ID : 1301171087
**/

mytype create_data1() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"ID: ";
    cin>>d.id;
    cout<<"Judul: ";
    cin>>d.judul;
    cout<<"Genre: ";
    cin>>d.genre;
    cout<<"Harga Tiket: ";
    cin>>d.price;



    // ===========================
    return d;
}

void view_data1(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID: "<<d.id<<endl;
    cout<<"Judul: "<<d.judul<<endl;
    cout<<"Genre: "<<d.genre<<endl;
    cout<<"Harga Tiket: "<<d.price<<endl;





    // ===========================
}


void edit_data1(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        mytype temp;
        string new_judul;
        string new_genre;
        float new_harga;
        temp.id = d.id;
        cout<<"Old Judul: "<<d.judul<<endl;
        cout<<"New Judul: ";
        cin>>new_judul;
        temp.judul = new_judul;
        cout<<endl;
        cout<<"Old Genre: "<<d.genre<<endl;
        cout<<"New Genre: ";
        cin>>new_genre;
        temp.genre = new_genre;
        cout<<endl;
        cout<<"Old Harga: "<<d.price<<endl;
        cout<<"New Harga: ";
        cin>>new_harga;
        temp.price = new_harga;
        cout<<endl;

        d = temp;






    // ===========================
}

