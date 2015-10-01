void insertFirst(List &L, address P)
{
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
        P->prev = L.last;
        P->next = L.first;
    }
    else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
        L.first->prev = L.last;
        L.last->next = L.first;
    }
}

void insertLast(List &L, address P)
{
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        L.last->next = L.first;
        L.first->prev = L.last;
    }
}

void insertAfter(List &L, address P, address Prec)
{
    // P tuh Element Baru yang akan diinsert,
    // Sesudah Elemen Prec
    address S = L.first;
    for (int i = 1; i <= countElm(L); i++){
        if (Prec->info.ID == S->info.ID) {
            break;
        }
        S = S->next;
    }
    Prec = S;

    P->next = Prec->next;
    P->prev = Prec;

    P->next->prev = P;
    Prec->next = P;
}

void deleteFirst(List &L, address &P)
{
    if (L.first == NULL) {
        cout << "List Kosong" <<endl;
    }
    else if (L.first->next == NULL) {
        P = L.first;
        P->prev = NULL;
        P->next = NULL;
        L.first = NULL;
        L.last = NULL;
        dealokasi(P);
    }
    else {
        P = L.first;
        L.first = P->next;
        L.last->next = L.first;
        L.first->prev = L.last;
        P->next = NULL;
        P->prev = NULL;
        dealokasi(P);
    }
}
