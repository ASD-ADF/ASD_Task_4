#include<iostream>
#include "my_data2.h"

/** CLASS      : IF 41-08
    NAME       : Muhammad Rayhan Alifinzi Ghiffari
    STUDENT ID : 1301174145

**/

mytype2 create_data(mytype2 x){
/**
TODO : receive input from user
        and assign the value of new data
*/

mytype2 d;

//=================================//
// YOUR CODE HERE

    cout<<"Insert Name : ";
    cin>>d.nama;
    cout<<"Insert ID/ NIM :";
    cin>>d.nim;
    cout<<"Insert Class : ";
    cin>>d.kelas;

//================================//
return d;
}

void view_data(mytype2 d){
    cout<<" ID/ NIM :"<<d.nim<<endl;
    cout<<"Name : "<<d.nama<<endl;
    cout<<"Class :"<<d.kelas<<endl;
}

void edit_data(mytype2 &d){

    cout<<"Insert Name : ";
    cin>>d.nama;
    cout<<"Insert ID/ NIM :";
    cin>>d.nim;
    cout<<"SInsert Class : ";
    cin>>d.kelas;
}
