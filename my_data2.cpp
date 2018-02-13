#include "my_data2.h"

/**
    CLASS      : IF-41-08
    NAME       : Rachmansyah Adhi Widhianto
    STUDENT ID : 1301170066
**/

mytype2 create_data_team() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout<<"Team ID       : ";
    cin>>d.team_id;
    cout<<"Team Name     : ";
    cin>>d.team_name;
    cout<<"Team Homebase : ";
    cin>>d.team_homebase;
    // ===========================
    return d;
}

void view_data_team(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Team ID       : "<<d.team_id<<endl;
    cout<<"Team Name     : "<<d.team_name<<endl;
    cout<<"Team Homebase : "<<d.team_homebase<<endl<<endl;
    // ===========================
}

void edit_data_team(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"Team Name     : ";
    cin>>d.team_name;
    cout<<"Team Homebase : ";
    cin>>d.team_homebase;
    // ===========================
}
