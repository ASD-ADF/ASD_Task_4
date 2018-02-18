
#include "my_data.h"

/**
    CLASS      : IF39INT
    NAME       : Pertiwang Sismananda
    STUDENT ID : 1301153614
**/

mytype create_data() {
    /**
     TODO:  receive input from user
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
	std::cout << "ID : ";
	std::cin >> d.id;
	std::cout << "Item : ";
	std::cin >> d.item;
	std::cout << "Price : ";
	std::cin >> d.price;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
    */

    // ===========================
    // YOUR CODE HERE
	std::cout << "ID : " << d.id << "\nItem : " << d.item << "\nPrice : " << d.price;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     TODO:  edit the value of data d,
            the ID must not be modified
    */

    // ===========================
    // YOUR CODE HERE
	std::cout << "Item : ";
	std::cin >> d.item;
	std::cout << "Price : ";
	std::cin >> d.price;
    // ===========================
}

