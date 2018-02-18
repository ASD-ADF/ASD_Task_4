#include "my_data2.h"

mytype2 create_data2()
{
    mytype2 d;

    cout<<"Insert ID: ";
    cin>>d.id;
    cout<<"Insert Faculty: ";
    cin>>d.fct;
    cout<<"Insert Majoring: ";
    cin>>d.mjr;
    cout<<endl;

    return d;
}

void view_data(mytype2 d)
{
    cout<<"ID         : "<<d.id<<endl;
    cout<<"Faculty    : "<<d.fct<<endl;
    cout<<"Majoring   : "<<d.mjr<<endl;
    cout<<endl;
}

void edit_data(mytype2 &d)
{
    cout<<"ID         : "<<d.id<<endl;
    cout<<"Faculty    : ";
    cin>>d.fct;
    cout<<"Majoring   : ";
    cin>>d.mjr;
    cout<<endl;
}
