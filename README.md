# Task_4
Introduction to Double Circular Linked List  <br>
Create a music player application to implement the double circular linked list data structure

##list.h
modify the elemenList and List structure to implement Double Circular linked list
	
##list.cpp
modify each function
* createList
* alokasi
* insertFirst, insertLast, insertAfter
* deleteFirst, deleteLast, deleteAfter
to implement Double Circular Linked List mechanism
	
##player.cpp
create function according to the header defined in player.h
* function to play the previous song on the list <br>
  ```cpp void playPrev(address &P);```
* function to shuffle the song list <br>
  ```void shuffleList(List &);```
* function to sort the song list by some condition <br>
  ```void sortList(List &, int condition) example: if condition = 1, then sort by ID```  <br>
		```//          if condition = 2, then sort by name```  <br>
* function to play the song list from the first song and repeat the list n times  <br>
	```void playRepeat(List &, int n);```
	
		
##main.cpp
modify the main prorgam, add these menus into the main program
* menu to search song by name and play it <br>
	( you can create a new function to search or modify the findElm function )
* menu play the previous song on the list
* menu play again this song (the last played song)
* menu shuffle the song list
* menu sort the song list
* menu play repeat all songs
	
