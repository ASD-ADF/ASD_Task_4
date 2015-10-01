#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

struct music
{
    int id;
    string name;
    string location;
};

struct element
{
    music info;
    element *next;
    element *prev;
};

struct List
{
    element *head;
    element *tail;
};

//Create List
void create_list(List &L);

//Empty List Checker
bool EmptyData(List L);

//Menu
void menu(List &L, element *m);
void insert_menu();
void delete_menu();

//Allocate / Deallocate
element *allocate(music m);
void deallocate(element *p);

//Inserts
void insert_first(List &L, element *p);
void insert_last(List &L, element *p);
void insert_after(List &L);

//Deletes
void delete_first(List &L, element *p);
void delete_last(List &L, element *p);
void delete_after(List &L);

//Other
element *find_element(List L, string name);
void searching(List L,element *&m);


#endif // LIST_H_INCLUDED
