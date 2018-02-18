
#include "my_data2.h"

/**
    CLASS      : IF39INT
    NAME       : Pertiwang Sismananda
    STUDENT ID : 1301153614
**/

mytype2 create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype2 d;
    // ===========================
    // YOUR CODE HERE
	std::cout << "ID : ";
	std::cin >> d.id;
	std::cout << "Height : ";
	std::cin >> d.height;
	std::cout << "Weight : ";
	std::cin >> d.weight;
    // ===========================
    return d;
}

void view_data(mytype2 d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
	std::cout << "ID : " << d.id
		<< "\nHeight : " << d.height
		<< "\nWeight : " << d.weight
		<< std::endl;
    // ===========================
}


void edit_data(mytype2 &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
        cout<<"your code here"<<endl;
		std::cout << "Height : ";
		std::cin >> d.height;
		std::cout << "Weight : ";
		std::cin >> d.weight;
    // ===========================
}

