#include "signUp.h"




bool showSignUp(const vector<string>& options){
    

    WINDOW* win = newwin(12 , 50 , (getmaxy(stdscr) - 12) / 2 , (getmaxx(stdscr)-50) / 2 );
    string username , gmail , password;
    int active_input = 0;

    while(true) {
    wclear(win);
    for(int i = 0 ; i < options.size(); ++i)
        {
         wmove(win , 2 + i*2 , 2);
         if(i == active_input) wattron(win , A_REVERSE);
         wprintw(win , "%s" , options[i].c_str());
         if(i == 0) wprintw(win , "%s%s" , username.c_str() , i == active_input ? "|" : "");
         if(i == 1) wprintw(win , "%s%s" , gmail.c_str() , i == active_input ? "|" : "");
         if(i == 2) wprintw(win , "%s%s" , string(password.length(),'*').c_str() , i ==active_input ? "|" : "");
         wattroff(win , A_REVERSE);
        }   
        wrefresh(win);
        wrefresh(win);

        int inC  = getch();
//(ch == KEY_UP || (ch == '\t' && active_field > 0)) 
//(ch == KEY_DOWN || (ch == '\t' && active_field < labels.size() - 1))
//(ch == 27)  // esc ascii value
//(ch == '\n' && active_field == 3) //submit
//(ch == '\n' && active_field == 4) // exit
//(ch == KEY_BACKSPACE && active_field < 3)
//(ch >= 32 && ch <= 126 && active_field < 3)


if(inC == KEY_UP || (inC == '\t' && active_input > 0))
{
active_input = (active_input - 1 + options.size()) % options.size();
}
else if(inC == KEY_DOWN || (inC == '\t' && active_input < options.size() - 1) || (inC == 10 && active_input < 3))
{
active_input = (active_input + 1) % options.size();
}
else if(inC == 27) // esc
{
WINDOW* cancelWin = newwin(12 ,50,(getmaxy(stdscr)-12)/2 ,(getmaxx(stdscr)-50)/2 );
wmove(cancelWin , 2 ,2);
wprintw(cancelWin , "Cancelled signUp, press any key to continue..");
wrefresh(cancelWin);
getch();
delwin(cancelWin);
delwin(win);
refresh();
return false;
}
else if(inC == '\n' && active_input == 3) // check if empty and gmail..
{
    if(username.empty() || gmail.empty() || password.empty() )
    {
     WINDOW* msg_win = newwin(12 , 50 , (getmaxy(stdscr)-12)/2 , (getmaxx(stdscr)-50)/2);
     wmove(msg_win , 2 , 2);
     wprintw(msg_win , "Any fields cannot be empty press any key to continue");
     wrefresh(msg_win);
     getch();
     delwin(msg_win);
     continue;
    }
     if(gmail.find("@gmail.com") == std::string::npos)
     {
      WINDOW* msg_win = newwin(12 , 50 , (getmaxy(stdscr)-12)/2 , (getmaxx(stdscr)-50)/2);
      wmove(msg_win , 2 , 2);
      wprintw(msg_win , "Invalid gmail format, press any key to continue");
      wrefresh(msg_win);
      getch();
      delwin(msg_win);
      continue; 
    }

   WINDOW* msg_win = newwin(12 , 50 , (getmaxy(stdscr)-12)/2 , (getmaxx(stdscr)-50)/2);
   wmove(msg_win , 1 , 2);
   wprintw(msg_win , "Submitted: ");
   wmove(msg_win , 2 , 2);
   wprintw(msg_win , "Username: %s",username.c_str());
   wmove(msg_win , 3 , 2);
   wprintw(msg_win , "Gmail: %s",gmail.c_str());
   wmove(msg_win , 4 , 2);
   wprintw(msg_win , "Press any key to continue");
   wrefresh(msg_win);
   getch();
   delwin(msg_win);
   delwin(win);
   refresh();
  return true;
   }


   else if(inC == '\n' && active_input == 4)
   {   
 WINDOW* msg_win = newwin(12 , 50 , (getmaxy(stdscr)-12)/2 , (getmaxx(stdscr)-50)/2);
 wmove(msg_win , 2 , 2);
 wprintw(msg_win , "Canceled! press any key to exit");
 wrefresh(msg_win);
 getch();
 delwin(msg_win);
 delwin(win);
 refresh();
 return false;
   }  


   
   else if((inC == KEY_BACKSPACE || inC == 8 || inC == 127)  && active_input < 3)
   {
    if(active_input == 0 && !username.empty()) username.pop_back();
    else if(active_input == 1 && !gmail.empty()) gmail.pop_back();
    else if(active_input == 2 && !password.empty()) password.pop_back();
   }
   
   else if(inC >=32 && inC <=126 && active_input < 3)
   {
       if(active_input == 0) username += inC;
       else if(active_input == 1) gmail += inC;
       else if(active_input == 2) password += inC;
   }

  }



}





