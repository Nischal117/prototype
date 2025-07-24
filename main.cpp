#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <vector>
#include <ncurses.h>


#include "signUp.h"

#define ACODE 117

using namespace std;


void print_menu(WINDOW* win , const vector<string>& options , int highlight)
    {
         int y , x;
         getmaxyx(win , y , x);

         int start_y = (y - options.size()) / 2;

         for(int i = 0 ; i < options.size() ; ++i)
             {
              int start_x = (x - options[i].length()) / 2;
              wmove(win , start_y + i , start_x);
              if(i == highlight) wattron(win , A_REVERSE);
              wprintw(win ,"%s" , options[i].c_str());
              if(i == highlight) wattroff(win , A_REVERSE);
             }
          wrefresh(win);



    }


int main()
    {
  vector<string> menu_option = {"SIGN UP" , "LOG IN" , "ADMIN PANEL" , "EXIT"};

    initscr();
    cbreak();
    noecho();
    keypad(stdscr , TRUE);
    curs_set(0);



    vector<string> airLine = {
  "Emirates", "Delta", "British", "American", "Lufthansa" , "LockHeed.PVT"}; 
    
   while(true){


 WINDOW* menu_win =newwin(12,50,(getmaxy(stdscr)-12)/2,(getmaxx(stdscr)-50)/2);
 int highlight = 0;
 int choice = -1;

    while(true) {
    wclear(menu_win);
    print_menu(menu_win ,menu_option , highlight);
    int input = getch();

    switch(input)
     {
     case KEY_UP:
     highlight = (highlight-1 + menu_option.size()) % menu_option.size();
     break;

     case KEY_DOWN:
     highlight = (highlight + 1 ) % menu_option.size();
     break;

     case 10:
     choice = highlight;
     break;

      }

    if(input == 10) break;

    }
      delwin(menu_win);

  switch(choice) {
    
    case 0 :
    {
    vector<string> signUpOptions = {"Username : " , "Gmail : " , "Password : " , "Submit" , "Cancel"};   
    SignUp activate;
    if(activate.showSignUp(signUpOptions))
        {
         clear();
         refresh();
         WINDOW* statusWin = newwin(5 , 30 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 30 ) /2);
         wmove(statusWin , 2 , 2);
         wprintw(statusWin , "Sign Up Successful.");
         wrefresh(statusWin);
          
         getch();
         delwin(statusWin);
         
        }
        else{
            clear();
            refresh();
          WINDOW* statusWin = newwin(5, 30 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 30 ) /2);
          wmove(statusWin , 2 , 2);
          wprintw(statusWin , "Sign Up was Unsuccessful.");
          wrefresh(statusWin);
          getch();
          delwin(statusWin);
        }
    }
      break;
    
    case 1: 
        continue;
        break;

    case 2:
       continue;    
       break;

    case 3:
    endwin();
    break;
 }

if(choice == 3) break;

    }

  
    
    return 0;


 }
