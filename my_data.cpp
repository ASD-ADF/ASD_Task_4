#include "my_data.h"

/**
    CLASS      : IF-41-08
    NAME       : Rachmansyah Adhi Widhianto
    STUDENT ID : 1301170066
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Player ID         : ";
    cin>>d.player_id;
    cout<<"Name              : ";
    cin>>d.player_name;
    cout<<"Position          : ";
    cin>>d.player_position;
    cout<<"Player Efficiency : ";
    cin>>d.efficiency;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Player ID         : "<<d.player_id<<endl;
    cout<<"Name              : "<<d.player_name<<endl;
    cout<<"Position          : "<<d.player_position<<endl;
    cout<<"Player Efficiency : "<<d.efficiency<<endl<<endl;
    // ===========================
}

void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Name              : ";
    cin>>d.player_name;
    cout<<"Position          : ";
    cin>>d.player_position;
    cout<<"Player Efficiency : ";
    cin>>d.efficiency;
    // ===========================
}
