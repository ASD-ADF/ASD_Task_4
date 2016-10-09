#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct elmlist{
     infotype info;
     address next;
     address prev;
};

struct List{
     address first;
     address last;
};

void createList(List &);
void createList(List &L);
address alokasi(infotype );
void dealokasi(address &);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &, address );
void insertLast(List &, address );
void insertAfter(address , address);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void deleteFirst(List &, address &);
void deleteLast(List &, address &);
void deleteAfter(address, address &);
address findElm(List, infotype );
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
address findElm(List L, infotype x);
int countElm(List L);

#endif // LIST_H_INCLUDED
