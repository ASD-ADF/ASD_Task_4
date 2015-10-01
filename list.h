#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#include <string>
#include <windows.h>
using namespace std;

struct MUSIC
{
    int id;
    string name;
    string location;
};
typedef MUSIC infotype;

typedef struct element_list *address;
struct element_list
{
    infotype info;
    address next;
    address prev;
};

struct list
{
    address first;
    address last;
};

address allocate(infotype x);
void deallocate(address &P);
void create_list(list &L);
void insert_first(list &L, address P);
void insert_after(list &L, address P, address Prec);
void insert_last(list &L, address P);
void delete_first(list &L, address &P);
void delete_after (list &L, address &P, address &Prec);
void delete_last(list &L, address &P);
address find_elm(list L, infotype x);
void search_data (list L, address P);
void sorting (list &L, int temp1);

#endif // LIST_H_INCLUDED
