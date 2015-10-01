#include "list.h"
#include "player.h"
#include <time.h>

int main()
{
    /*Variable Declaration*/
    List L;
    element *p, *music;
    char choose,subchoose;
    int condition;

    //Seed Random
    srand(time(NULL));

    /*Main Program*/
    create_list(L); // List L Head and Tail assigned NULL
    music = NULL; // Pointer Music assigned NULL

    while(choose != '0') // 0 to Exit
    {
        subchoose = 'a'; // Reset the value of subchoose
        system("cls");
        menu(L,music); //Output Menu
        choose = _getch();
        system("cls");
        switch(choose)
        {
            case '1' : /* Insert Menu */
                {
                    while(subchoose != '0') // 0  to Exit
                    {
                        insert_menu();
                        subchoose = _getch();
                        system("cls");
                        switch(subchoose)
                        {
                            case '1' : insert_first(L,p); subchoose = '0'; break;
                            case '2' : insert_last(L,p); subchoose = '0'; break;
                            case '3' : insert_after(L); subchoose = '0'; break;
                            default  : break;
                        }
                    }
                    if (L.head == L.tail)
                        {
                            music = L.head;
                        }
                        break;
                }
            case '2' : /* Delete Menu */
                {
                    while(subchoose != '0')
                    {
                        delete_menu();
                        subchoose = _getch();
                        system("cls");
                        switch(subchoose)
                        {
                            case '1' : delete_first(L,p); subchoose = '0'; break;
                            case '2' : delete_last(L,p); subchoose = '0'; break;
                            case '3' : delete_after(L); subchoose = '0'; break;
                            default  : break;
                        }
                    } music = (L).head; break;

                }
            case '3' : view_music_list(L); break;
            case '4' : play_song(music); break;
            case '5' : play_next(music); break;
            case '6' : play_prev(music); break;
            case '7' : searching(L,music); break;
            case '8' : shuffle_list(L); break;
            case '9' : sort_list(L,condition); break;
            case '-' : repeat_all_song(L,music); break;
            default  : break;

        }
    }
    cout<<"Closing HM Player.."<<endl;
    return 0;
}
