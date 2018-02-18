#include "doublelist.h"
#include "operation.h"
#include "my_data.h"
#include "my_data2.h"


void insertAndSort(List &L, address P) {
    /**
    * IS : List may be empty
    * PR : insert an element pointed by P into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID
    *      procedure must also check if such ID is already exists (No Duplicate ID)
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    infotype info = create_data();
	P = allocate(info);
	if (L.first == NULL)
    {
		insertFirst(L, P);
	}
	else
    {
		bool duplicate = false;
		address addr = L.first;
		while (addr != NULL && !duplicate)
		{
			if (addr->info.id == info.id)
				duplicate = true;
			addr = addr->next;
		}
		if (!duplicate)
		{
			addr = L.first;
			while (addr != NULL && addr->info.id != info.id)
			{
				if (addr->info.id < info.id && addr->next->info.id > info.id)
					insertAfter(L, addr, P);
			}
		}
	}
    //----------------------------------------
}


void deletebyID(List &L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = x.id is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    address Prec, P;
    P = findElm(L,x);
    deleteAfter(L,Prec,P);
    //----------------------------------------
}
