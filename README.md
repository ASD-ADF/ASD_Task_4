# Task_4 [2017/2018-II]
Task 4 : Double Linked List Introduction

# DEADLINE = FEBRUARY 18TH, 2018 - 23:59

## Reading Material
* [git cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)
* [markdown cheat sheet](https://enterprise.github.com/downloads/en/markdown-cheatsheet.pdf)

## Workflow
1. FORK this repositori ASD_Task_4 to your GitHub account
2. CLONE ASD_Task_4 repository from YOUR OWN ACCOUNT
3. open and modify codes in *.cpp and *.h files inside project ASD_Task_4
4. write your code inside the provided space in each functions/procedures 
5. COMMIT and PUSH your project to your account
6. create a Pull Request


Create a program to store and manage a data using Double linear linked list


## TO DO  
## [SHOULD YOU HAVE ALREADY DONE TASK 3, THEN YOU JUST HAVE TO  COPY-PASTE YOUR CODES AND MODIFY SOME OF THEM ]


### my_data.h *(From Previous Task_2)*
TODO:  create a new Data type with specification:
		- an integer variable acted as an ID
		- two other variables
		- a float variable
		
### my_data2.h 	***[NEW]***
TODO:  create a new Data type, DIFFERENT FROM THE FIRST ONE with specification:
		- an integer variable acted as an ID
		- two other variables


### my_data.cpp *(From Previous Task_2)*
* `mytype create_data()`<br>
	TODO: receive input from user and assign the value of new data
* `view_data(mytype d)`<br>
	TODO:  view the content of data d
* `edit_data(mytype &d)`<br>
	TODO:  edit the value of data d, the ID must not be modified

	
### my_data2.cpp 	***[NEW]***
* `mytype2 create_data()`<br>
	TODO: receive input from user and assign the value of new data
* `view_data(mytype2 d)`<br>
	TODO:  view the content of data d
* `edit_data(mytype2 &d)`<br>
	TODO:  edit the value of data d, the ID must not be modified

	
You may just copy your previous result


### doublelist.h	***[NEW]***
Create ADT of single linked list
* define a function and a procedure to allocate and deallocate an element list
  * `function allocate(in: x : infotype) : address`
  * `procedure deallocate( i/o: P : address )`
  
* define insert and delete procedure
  * `procedure insertFirst( i/o: L : List, i: P : address )`
  * `procedure insertLast( i/o: L : List, i: P : address )`
  * `procedure insertAfter( i/o: L : List,i: Prec : address, P : address )`
  * `procedure deleteFirst( i/o: L : List, i/o: P : address )`
  * `procedure deleteLast( i/o: L : List, i/o: P : address )`
  * `procedure deleteAfter( i/o: L : List,i: Prec : address, i/o: P : address )`

* define search-by-ID function and view procedure
  * `function findElm( i: L : List, x : infotype ) : address`
  * `procedure viewList( i: L : List )`
  

### operation.h *(From Previous Task_3)*
* define insertion procedure
  * `procedure insertionSort( i: L : List )`<br>
	TODO: insert an element pointed by P into an already sorted-by-ID List L, <br>
	so that the elements inside List L is still sorted by ID<br>
	procedure must also check if such ID is already exists (No Duplicate ID)
* define deletebyID function
  * `procedure deletebyID( i/o : L : List, x : infotype )`

  
### doublelist.cpp	***[NEW]***
Implement function and procedure defined in `list.h`


### operation.cpp *(From Previous Task_3)*
Implement function and procedure defined in `operation.h`

### main.cpp *(From Previous Task_3)*
Create a main menu to run your application <br>
Menu Application:
   1. insert new data
   2. print all data
   3. find and print a data by ID
   4. edit data by ID
   5. delete data by ID
   0. exit
  
   
### CRITERIA
* ID is unique, check whether ID is already exsits when inserting new element
* try to change the infotype in `doublelist.h` from `mytype` into `mytype2`
