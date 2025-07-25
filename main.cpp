#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <vector>
#include <ncurses.h>


#include "signUp.h"
#include "logIn.h"

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
        string loggedUser;
        string pass;
  vector<string> menu_option = {"SIGN UP" , "LOG IN" , "ADMIN PANEL" , "EXIT"};

    initscr();
    cbreak();
    noecho();
    keypad(stdscr , TRUE);
    curs_set(0);



    vector<string> airLine = {
  "Emirates", "Delta", "British", "American", "Lufthansa" , "LockHeed.PVT"}; 
    

    clear();
    refresh();
    WINDOW* welcome = newwin(5 , 50 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr)-50)/2);
    wmove(welcome , 2 , 2);
    wprintw(welcome , "WELCOME THE THE FLIGHT RESERVATION");
    wmove(welcome , 4 , 2);
    wprintw(welcome , "Press any key to get started");
    wrefresh(welcome);
    getch();
    delwin(welcome);
    


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
    
    case 1 : {
        logIn activateLog;
        int choice;
        vector<string> status = {"Customer" , "Admin" };

        choice = activateLog.customerOrAdmin(status);

        if(choice == 0)
        {
    //     clear();
    //     refresh();
         WINDOW* msg_win = newwin(5 , 40 , (getmaxy(stdscr)-5)/2 , (getmaxx(stdscr)-40) / 2);
         wmove(msg_win , 2 , 2 );
         wprintw(msg_win , "Press any key to continue to User login");
         wrefresh(msg_win);
         getch();
         delwin(msg_win);

        }

        else if(choice== 1)
        {
   //      clear();
   //      refresh();
         WINDOW* msg_win = newwin(5 , 40 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 40) / 2);

         wmove(msg_win , 2 , 2);
         wprintw(msg_win , "Press any key to continue to Admin Login");
         wrefresh(msg_win);
         getch();
         delwin(msg_win);
         goto adminLogIn;
        }
        else if(choice == 2)
        {
        continue;
        }


        vector<string> logInOptions = {"Username/Gmail : " , "Password : " , "Submit" , "Cancel"};
        
        
        if(activateLog.showLogIn(logInOptions))
        {
            loggedUser = activateLog.getUsername();
            clear();
            refresh();
  WINDOW* status_win = newwin(5 , 50 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 50) / 2 );
        wmove(status_win , 2 , 2);
        wprintw(status_win , "Log in Successful.");
        wmove(status_win , 5 , 2);
        wprintw(status_win , "Press any key to continue");
        wrefresh(status_win);
        getch();
        delwin(status_win);
       
        }
        else
        {
        clear();
        refresh();
  WINDOW* status_win = newwin(5 , 50 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 50) / 2);
        wmove(status_win , 2 , 2);
        wprintw(status_win , "Log In Unsuccessful.");
        wmove(status_win , 5 , 2);
        wprintw(status_win , "Press any key to continue");
        wrefresh(status_win);
        getch();
        delwin(status_win);

        }
       
        }
        break;
       
    case 2:
    {

        adminLogIn:
            
        vector<string> logInOptions = {"Admin ID: " , "CODE: " , "Submit" , "Cancel" };
        logIn adminActivate;
      
          if(adminActivate.adminLogIn(logInOptions))
        {
            pass = adminActivate.getAdmin();
            clear();
            refresh();
  WINDOW* status_win = newwin(5 , 50 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 50) / 2 );
        wmove(status_win , 2 , 2);
        wprintw(status_win , "Log in Successful.");
        wmove(status_win , 5 , 2);
        wprintw(status_win , "Press any key to continue");
        wrefresh(status_win);
        getch();
        delwin(status_win);
       
        }
        else
        {
        clear();
        refresh();
  WINDOW* status_win = newwin(5 , 50 , (getmaxy(stdscr) - 5) / 2 , (getmaxx(stdscr) - 50) / 2);
        wmove(status_win , 2 , 2);
        wprintw(status_win , "Log In Unsuccessful.");
        wmove(status_win , 5 , 2);
        wprintw(status_win , "Press any key to continue");
        wrefresh(status_win);
        getch();
        delwin(status_win);

        }

  }
  break;

    case 3:
    endwin();
    break;
 }

if(choice == 3) break;

    }

  
  
    cout << loggedUser << endl;
    cout << pass << endl;
    return 0;


 }
