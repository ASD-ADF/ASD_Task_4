
#include "my_data2.h"

/**
    CLASS      :if-40-int
    NAME       :muhamad rikbal ikhsani
    STUDENT ID :1301163598
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
   cout<<"Inputan Data Of Users 2"<<endl;

    cout<<"Input your ID : ";
    cin>>d.yid2;
    cout<<"Input your address : ";
    cin>>d.yaddr;
    cout<<"Input your blood type : ";
    cin>>d.yblood;




    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
   cout<<"Data Of Users 2"<<endl;

   cout<<"ID of user is : "<<d.yid2<<endl;
   cout<<"address user is : "<<d.yaddr<<endl;
   cout<<"blood user is : "<<d.yblood<<endl;





    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"Data 2 Change"<<endl;

        cout<<"Input your new data of address : ";
        cin>>d.yaddr;
        cout<<"Input your new data of Blood type: ";
        cin>>d.yblood;


    // ===========================
}

