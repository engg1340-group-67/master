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
bool user_check(string &username);
void sign_up();
void forget();
bool email_valid(string email);
bool fileExists(string fileName);
string setPass();
void headers();
bool pwd_valid(string password);
void login_main(string &username);
