
#include "my_data2.h"

/**
    CLASS      : IF-40-INT
    NAME       : Hasna Fadhilah Hasya
    STUDENT ID : 1301164594
**/

mytype2 create_data(mytype2 x) {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
    cout << "==input student info==" << endl;
    cout << "input ID   : ";cin >> d.id_lec;
    cout << "input Name : ";cin >> d.name_lec;
    cout << "input Class: ";cin >> d.Class_lec;
    cout << "input Score: ";cin >> d.score_lec;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
    cout<<"==Student data=="<<endl;
    cout<<"ID   : "<<d.id_lec<<endl;
    cout<<"Name : "<<d.name_lec<<endl;
    cout<<"Class: "<<d.Class_lec<<endl;
    cout<<"Score: "<d.score_lec<endl;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
    string beforeUpdateName = d.name;
    cout<<" == Student New info == "<<endl;
    cout<<"Input ID   : ";
    cin>>d.id_lec;
    cout<<"Input Name : ";
    cin>>d.name_lec;
    cout<<"Input Class: ";
    cin>>d.Class_lec;
    cout<<"Input Score: ";
    cin>>d.score_lec;
    cout<<beforeUpdateName<<" == Edited to =="<<d.name<<endl;
    cout<<endl;
    // ===========================
}

