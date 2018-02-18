#include <conio.h>
#include <stdio.h>
#include <string>
#include "my_data2.h"

/**
    CLASS      : IF-41-08
    NAME       : Arbi Nourman Baruni
    STUDENT ID : 1301174030
**/

mytype2 create_data2() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"ID                 :  ";
    cin>>d.ID;
    cin.get();
    cout<<"SKS         :  ";
    gets(d.sks);
    cout<<"Mata Kuliah :  ";
    gets(d.matkul);




    // ===========================
    return d;
}

void view_data2(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"ID           : "<<d.ID<<endl;
    cout<<"SKS          : "<<d.sks<<endl;
    cout<<"Mata Kuliah  : "<<d.matkul<<endl;
    cout<<endl;




    // ===========================
}


void edit_data2(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cin.get();
    cout<<"SKS         :  ";
    gets(d.sks);
    cout<<"Mata Kuliah :  ";
    gets(d.matkul);




    // ===========================
}

