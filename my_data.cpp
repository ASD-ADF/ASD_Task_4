
#include "my_data.h"

/**
    CLASS      :if-40-int
    NAME       :muhamad rikbal ikhsani
    STUDENT ID :1301163598
**/

mytype create_data(mytype X) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
   // cout<<"your code here"<<endl;
    cout<<"Inputan Data Of Users"<<endl;

    cout<<"Input your Name : ";
    cin>>d.yname;
    cout<<"Input your ID : ";
    cin>>d.yid;
    cout<<"Input your Class : ";
    cin>>d.yclas1;
    cout<<"Input your Score : ";
    cin>>d.yscore;



    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Data Of Users"<<endl;

    cout<<"Your Name is : "<<d.yname<<endl;
    cout<<"Your ID is   : "<<d.yid<<endl;
    cout<<"Your Class is: "<<d.yclas1<<endl;
    cout<<"Your Score is: "<<d.yscore<<endl;




    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"Data Change"<<endl;

        cout<<"Input your new data of name : ";
        cin>>d.yname;
        cout<<"Input your new data of Class: ";
        cin>>d.yclas1;
        cout<<"Input your new data of Score: ";
        cin>>d.yscore;
        cout<<"THIS IS YOUR NEW DATA "<<d.yname<<endl;
        cout<<endl;


    // ===========================
}

