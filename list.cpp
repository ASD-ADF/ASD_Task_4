#include "list.h"
#include "player.h"

void create_list(List &L)
{
    L.head = NULL;
    L.tail = NULL;
}

bool EmptyData(List L)
{
    if( L.head == NULL ) {return true;}
    else {return false;}
}

void menu(List &L, element *m)
{
    cout<<"HIDE Music Player"<<endl<<endl
        <<"  1. Insert Song"<<endl
        <<"  2. Delete Song"<<endl
        <<"  3. View Playlist"<<endl
        <<"  4. Play Current Song ("; current_song(m); cout<<")"<<endl
        <<"  5. Play Next Song    "<<endl
        <<"  6. Play Previous Song"<<endl
        <<"  7. Search Song to Play"<<endl
        <<"  8. Shuffle Playlist"<<endl
        <<"  9. Sort Playlist"<<endl
        <<"  -. Repeat All Song"<<endl
        <<"  0. Exit"<<endl;
}

void insert_menu()
{
    cout<<"Insert Song on : "<<endl<<endl
        <<"1. First"<<endl
        <<"2. Last"<<endl
        <<"3. After"<<endl
        <<"0. Back to Main Menu"<<endl;
}

void delete_menu()
{
    cout<<"Delete Song on : "<<endl<<endl
        <<"1. First"<<endl
        <<"2. Last"<<endl
        <<"3. After"<<endl
        <<"0. Back to Main Menu"<<endl;
}

element *allocate(music m)
{
    element *p = new element;
    p->info = m;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void deallocate(element *p) { delete p; }

void insert_first(List &L, element *p)
{
    cout<<"Insert Music on First List"<<endl<<endl;
    music m;
    input_song(m);
    p = allocate(m);
    if (EmptyData(L))
    {
        L.head = p;
        L.tail = p;
        p->next = p;
        p->prev = p;
    }
    else
    {
        p->next = L.head;
        (p->next)->prev = p;
        p->prev = L.tail;
        (p->prev)->next = p;
        L.head = p;
        L.tail = p->prev;
    }
    cout<<endl<<"Insert Success!"<<endl;
    _getch();
}

void insert_last(List &L, element *p)
{
    cout<<"Insert Music on Last List"<<endl<<endl;
    music m;
    input_song(m);
    p = allocate(m);
    if(EmptyData(L))
    {
        L.head = p;
        L.tail = p;
        p->next = p;
        p->prev = p;
    }
    else
    {
        p->prev = L.tail;
        (p->prev)->next = p;
        p->next = L.head;
        (p->next)->prev = p;
        L.tail = p;
        L.head = p->next;
    }
    cout<<endl<<"Insert Success!"<<endl;
    _getch();
}

void insert_after(List &L)
{
    element *p, *q;
    string name;
    cout<<"Insert After"<<endl<<endl;
    if(EmptyData(L))
    {
        cout<<"Must have at least 1 Element first!";
    }
    else
    {
        cout<<"Insert Music after Music Name : ";
        cin>>name;
        q = find_element(L,name);
        if(q == NULL)
        {
            cout<<"Music Not Found!";
        }
        else
        {
            music m;
            input_song(m);
            p = allocate(m);
            p->next = q->next;
            p->prev = q;
            q->next = p;
            p->next->prev = p;
            cout<<endl<<"Insert Success!"<<endl;
        }
    }
}

void delete_first(List &L, element *p)
{
    cout<<"Delete Music on First List"<<endl<<endl;
    p = L.head;
    if (EmptyData(L))
    {
        cout<<"No Music to Delete from List!";
    }
    else if(p->next == p)
    {
        L.head = NULL;
        L.tail = NULL;
        cout<<"Deleted Music"<<endl<<endl;
        cout<<"ID       : "<<p->info.id<<endl;
        cout<<"Name     : "<<p->info.name<<endl;
        cout<<"Location : "<<p->info.location<<endl<<endl;
        deallocate(p);
        cout<<"Delete Success!";
    }
    else
    {
        p = L.head;
        L.head = p->next;
        (p->next)->prev = L.tail;
        (p->prev)->next = p->next;
        if ((p->next)->next == p)
        {
            (p->next)->next = p->next;
        }
        p->next = NULL;
        p->prev = NULL;
        cout<<"Deleted Music"<<endl<<endl;
        cout<<"ID       : "<<p->info.id<<endl;
        cout<<"Name       : "<<p->info.name<<endl;
        cout<<"Location : "<<p->info.location<<endl<<endl;
        deallocate(p);
        cout<<"Delete Success!";
    }
    _getch();
}

void delete_last(List &L, element *p)
{
    cout<<"Delete Music on Last List"<<endl<<endl;
    p = L.head;
    if(EmptyData(L))
    {
        cout<<"No Music to Delete from List!";
    }
    else if(p->next == p)
    {
        L.head = NULL;
        L.tail = NULL;
        cout<<"Deleted Music"<<endl;
        cout<<"ID       : "<<p->info.id<<endl;
        cout<<"Name     : "<<p->info.name<<endl;
        cout<<"Location : "<<p->info.location<<endl<<endl;
        deallocate(p);
        cout<<"Delete Success!";
    }
    else
    {
        p = L.tail;
        L.tail = p->prev;
        (p->prev)->next = L.head;
        (p->next)->prev = p->prev;
        if ((p->prev)->prev == p)
        {
            (p->prev)->prev = p->prev;
        }
        p->prev = NULL;
        p->next = NULL;
        cout<<"Deleted Music"<<endl;
        cout<<"ID       : "<<p->info.id<<endl;
        cout<<"Name     : "<<p->info.name<<endl;
        cout<<"Location : "<<p->info.location<<endl<<endl;
        deallocate(p);
        cout<<"Delete Success!";
    }
    _getch();
}

void delete_after(List &L)
{
    cout<<"Delete After"<<endl<<endl;
    if(EmptyData(L))
    {
        cout<<"No Music to Delete from List!";
    }
    else
    {
        string name;
        element *p, *prec;
        cout<<"Delete Music after Music Name : "; cin>>name;
        prec = find_element(L,name);
        if(prec == NULL)
        {
            cout<<"Music not Found!";
        }
        else
        {
            p = prec->next;
            prec->next = p->next;
            p->next->prev = prec;
            p->next = NULL;
            p->prev = NULL;
            cout<<"Deleted Music"<<endl;
            cout<<"ID       : "<<p->info.id<<endl;
            cout<<"Name     : "<<p->info.name<<endl;
            cout<<"Location : "<<p->info.location<<endl<<endl;
            deallocate(p);
        }
        cout<<"Delete Success!";
    }
    _getch();
}

element *find_element(List L, string name)
{
    if(L.head == NULL)
    {
        return NULL;
    }
    else
    {
        element *p, *q;
        p = L.head;
        q = L.head;
        bool loop = true;
        while(loop)
        {
            if(p->info.name == name)
            {
                return p;
            }
            if(p->next == q)
            {
                return NULL;
            }
            else
            {
                p = p->next;
            }
        }
    }
}

void searching(List L,element *&m)
{
    element *p; string name;
    cout<<"Search Music"<<endl<<endl;
    cout<<"Input Music Name to Play : "; cin>>name;
    p = find_element(L,name);
    if(p == NULL)
    {
        cout<<endl<<"Music not found!";
    }
    else
    {
        m = p;
        play_song(m);
    }
}
