
#ifndef LOGIN_H
#define LOGIN_H

#include <ncurses.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdbool.h>
#include <map>
#include <sstream>
#include <fstream>



using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::map;
using std::stringstream;

    
    class logIn {
    
    private:
    string username = "";
    string gmail = "";
    string password = "";
    string tempId = "";

    public: 

    bool showLogIn(const vector<string>& options);
    bool isAuthenticated();

    




    



    };













#endif
