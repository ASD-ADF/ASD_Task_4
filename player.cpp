#include "list.h"
#include "player.h"
#include <stdlib.h>

void input_song(music &m)
{
    cout<<"Input Song ID          : "; cin>>m.id;
    cout<<"Input Song Name (.wav) : "; cin>>m.name;
    cout<<"input Song Location ( - for default location ) : "; cin>>m.location;
    if(m.location == "-") { m.location = ""; }
}

void current_song(element *m)
{
    if (m != NULL)
    {
        cout<<m->info.name;
    }
    else
    {
        cout<<"  ";
    }
}

void view_music_list(List L)
{
    cout<<"  Playlist     : "<<endl<<endl;
    element *p = L.head;
    if(EmptyData(L))
    {
            cout<<"  Empty Playlist"<<endl;
    }
    else if(EmptyData(L) == false)
    {
        cout<<"  Name     : "<<p->info.name<<endl
            <<"  Location : ";
        if(p->info.location == "")
        {
            cout<<"Default Location"<<endl<<endl;
        }
        else
        {
            cout<<p->info.location<<endl<<endl;
        }
        if(p->next != p)
        {
            p = p->next;
        }

        while(p != L.head)
        {
            cout<<"  Name     : "<<p->info.name<<endl
                <<"  Location : ";
                if(p->info.location == "")
                {
                    cout<<"Default Location"<<endl<<endl;
                }
            p = p->next;
        }
    }
    _getch();
}

void play_song(element *m)
{
    if (m != NULL)
    {
        string filename = m->info.location + m->info.name;
        cout<<"Playing : "<<filename<<endl;
        PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME );
        _sleep(1000); //delay 1 second
    }
}

void play_next(element *&m)
{
    if (m != NULL)
    {
        m = m->next;
        play_song(m);
    }
}

void play_prev(element *&m)
{
    if (m != NULL)
    {
        m = m->prev;
        play_song(m);
    }
}

void sort_list(List &L, int condition)
{
    cout<<"Sort Playlist"<<endl<<endl
        <<"1. Sort by ID"<<endl
        <<"2. Sort by Name"<<endl<<endl
        <<"Input Condition : ";
    cin>>condition;
    int x;
    element *p;
    element *q = L.head;
    if(condition == 1)
    {
        q = L.head->next;
        bool stop = false;
        while(stop == false)
        {
            stop = true;
            while(q->next != L.head->next) {
                if(q->prev->info.id > q->info.id)
                {
                    element *tmp = new element;
                    tmp->info = q->prev->info;
                    q->prev->info = q->info;
                    q->info = tmp->info;
                    stop = false;
                    delete tmp;
                }
                q = q->next;
            }
        }
    }
    else if (condition == 2)
    {
        q = L.head->next;
        bool stop = false;
        while(stop == false)
        {
            stop = true;
            while(q->next != L.head->next) {
                if(q->prev->info.name > q->info.name)
                {
                    element *tmp = new element;
                    tmp->info = q->prev->info;
                    q->prev->info = q->info;
                    q->info = tmp->info;
                    stop = false;
                    delete tmp;
                }
                q = q->next;
            }
        }
    }
    cout<<endl<<"List Sorted!";
    _getch();
}

void shuffle_list(List &L)
{
    List N;
    int x; int rands;
    if(EmptyData(L))
    {
        cout<<"No List to shuffle!";
    }
    else
    {
        element *p = L.head;
        element *q;
        x = 1;
        while(p->next != L.head)
        {
            p = p->next;
            x++;
        }
        bool awal = true;
        while(x > 0)
        {
            rands = rand() % x + 1;
            p = L.head;
            while(rands > 1) //get the element
            {
                p = p->next;
                rands--;
            }
            if(awal)
            {
                element *tmp = new element;
                tmp->info = p->info;
                p->next->prev = p->prev;
                p->prev->next = p->next;
                if(p == L.head)
                {
                    L.head = p->next;
                }
                N.head = tmp;
                awal = false;
                q = tmp;
                q->next = q;
                q->prev = q;
            }
            else
            {
                element *tmp = new element;
                tmp->info = p->info;
                p->next->prev = p->prev;
                p->prev->next = p->next;
                if(p == L.head)
                {
                    L.head = p->next;
                }
                q->next = tmp;
                q->next->prev = q;
                q = q->next;
            }
            x--;
        }
        q->next = N.head;
        q->next->prev = q;
        N.tail = q;
        L = N;
    }
    cout<<"Playlist Shuffled!";
    _getch();
}

void repeat_all_song(List L,element *m)
{
    cout<<"Repeat All Song"<<endl<<endl;
    if (EmptyData(L))
    {
        cout<<"No Song to Repeat!";
    }
    else
    {
        int many;
        cout<<"Repeat Many Times : "; cin>>many; cout<<endl;
        if (many <= 0)
        {
            cout<<"Input must be bigger than 0!";
        }
        else
        {
            m = L.head;
            int x = 0;
            do
            {
                play_song(m);
                m = m->next;
                if(m == L.head)
                {
                    x++;
                }
            } while(x != many);
        }
    }
}
