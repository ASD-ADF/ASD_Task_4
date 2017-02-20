# Task_4
Introduction to Double Circular Linked List  <br>
Create a music player application to implement the double circular linked list data structure

##library integration
1. on Code::Blocks, go into menu project->Build Option
2. go to Linker Settings tab
3. click Add to add new lib function
4. type winmm 
5. click OK

##list.h
modify the elemenList and List structure to implement Double Circular linked list
	
##list.cpp
modify each function to fit the data structure
* createList
* alokasi
* insertFirst, insertLast, insertAfter
* deleteFirst, deleteLast, deleteAfter
to implement Double Circular Linked List mechanism
	
##player.cpp
<i>these function are already defined:
* function to produce random integer
  ```int randomInt(int  max_int);```
* function to print music list inserted
  ```void printInfo(List L);```
* function to play current music pointed by P
  ```void playMusic(address P);```  
</i>
TODO : 
create function according to the header defined in player.h<br>
* function to shuffle the music list <br>
  ``` void shuffleList(List &);```<br>
  simple logic example: <br>
  ```
	loop n times
		P <- first
		x = randomInt
		for i to x, 
			move P to next element
		delete after P
		insert first P
  ```
* function to sort the music list by ID <br>
  ``` void sortListByID(List &L); ```
* function to play the music list from the first music and repeat the list n times  <br>
  ```void playRepeat(List &, int n);```
* function to delete any music defined by its ID<br>
  ```void deleteMusicByID(List &L, infotype x);```
	
		
##main.cpp
* modify the main menu progam
* run the application
	
