#include "add.h"
#include "search.h"
#include "edit.h"
#include "delete.h"
#include "sort.h"
#include "menu_kid.h"
#include "global.h"
#include <sstream>
#include<limits>
#include <fstream>
#include <conio.h>
#include <string>
#include <iostream>
#include <regex>
#include<iomanip>
#include <limits> 
#ifdef _MSC_VER
#define getch() _getch()
#endif
using namespace std;
string password, password_check, username;
bool user_check(string& usrname_return);
void sign_up();
void forget();
bool email_valid(string email);
bool fileExists(string fileName);
string setPass(bool show_asterisk);
void headers();
bool pwd_valid();
string login_main();
