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
using namespace std;
#ifdef _MSC_VER
#define getch() _getch()
#endif
bool show_asterisk = true;
string password, password_check, username;
bool user_check(string & usr);
void sign_up();
void forget();
bool email_valid(string email);
bool fileExists(string fileName);
string setPass(bool show_asterisk);
void headers();
bool pwd_valid();
//void our_group();
//void result();
//void entry_menu();
string login_main();

int main() {
	int phony = 0;
	string name = login_main();
	system("cls");
	phony = menu_main(name);
	if (!phony){
		return 0;
		}
		return 1;
}

string login_main(){
	string usr;
	char a;
	bool check= false;
	do{
	headers();
	cin>>a;
  switch (a) {
    case '1': check=user_check(usr);
      break;
    case '2': sign_up();
		cout << "\nReturn to menu . . . ";
		getch();
      break;
    case '3': forget();
		cout << "\nReturn to menu . . . ";
		getch();
      break;
		case '0': break;
    default:
      cout << "\a";
    }
	}while (a!='0'&& !check);
	cout << "See you next time!\n";
	return usr;
}

bool user_check(string& usr) {
		string password_check,username_file;
		//char pass2[5];
		//int times_login;

    cout<<"enter username: ";
    cin >> username;
		username_file=username+".txt";
		if (fileExists(username_file)){
			cout<<"enter password: ";
			password= setPass(show_asterisk);

	    ifstream fin;
	    fin.open(username_file) ;
			if( fin.fail() )	{
		 		cout << "Error opening file";
		 		exit(1);
		 	}
			fin>> password_check;
			fin.close();
			if (password_check == password){
				usr = username;
				cout << "\nWelcome "<< username<<endl;
				getch();
				return true;
			}else{
				cout<<"\nInvalid username or password\n";
				cout << "\nReturn to menu . . . ";
				getch();
				return false;
			}

		}
		return false;
 }

 void sign_up(){
	 string username_2;
	 cout<<"Create username: ";
	 cin >> username_2;
	 username_2+=".txt";
	 ofstream fi;

	 while (fileExists(username_2)){
	   cout << "Username exists. Please enter another one: ";
	   cin >> username_2;
	   username_2+=".txt";
	 }
	 fi.open(username_2);

 	if( fi.fail() )	{
 		cout << "Error opening file";
 		exit(1);
 	}

 	cout<<"Enter your password: ";
	password= setPass(show_asterisk);
	while (!pwd_valid()){
		cout<<"Invalid password\nEnter your password: ";
		password= setPass(show_asterisk);
	}
	cout<<"Enter your password again: ";
	password_check = setPass(show_asterisk);
	while (password!=password_check){
		cout<<"Passwords do not match\nEnter your password: ";
		password= setPass(show_asterisk);
		while (!pwd_valid()){
			cout<<"Passwords do not match\nEnter your password: ";
			password= setPass(show_asterisk);
		}
		cout<<"Enter your password again: ";
		password_check = setPass(show_asterisk);
	}
 	cout << "Thank you\n";
 	fi<< password;
	fi.close();
 }

void forget(){
  string user_email;
  cout << "Please enter your email address: ";
  cin >> user_email;
  cout << (email_valid(user_email) ? "Check your email" : "Invalid email address") << endl;
}

bool fileExists(string fileName){
    ifstream infile(fileName);
    return infile.good();
}

bool email_valid(string email){
   const regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return regex_match(email, pattern);
}

string setPass(bool show_asterisk = true){
    const char BACKSPACE = 8;//ASCII code for BACKSPACE Key
    const char ENTER = 13;//ASCII code for ENTER Key
    string pass = "";
    char c = ' ';
    while ((c = _getch()) != ENTER) {
        if (c == BACKSPACE)  {
            if (pass.length() != 0)    {
                if (show_asterisk)
                   cout << "\b \b";
                pass.resize(pass.length() - 1);
            }
        }
        else if (c == 0 || c == 224){
            _getch();
            continue;
        } else{
            pass.push_back(c);
            cout << '*';
        }
    }
    cout << endl;
    return pass;
}

void headers(){
	system("cls");
	cout << "     ***************************************" << endl;
	cout << "     * Welcome to Your Financial Majordomo *" << endl;
	cout << "     ***************************************" << endl;
	cout<<"\n\n\tLogin/Register";
	cout<<"\n\n\t01. Login";
	cout<<"\n\n\t02. Register";
	cout<<"\n\n\t03. Forget my usernamne or password";
	cout<<"\n\n\t00. Exit";
	cout<<"\n\n\tPlease Select Your Option (0-3) ";

}

bool pwd_valid(){
	if (password.length()<6 || password.length()>20){
		return false;
	}else{
		return ((password.find_first_of("0123456789") != string::npos) && (password.find_first_of("abcdefghijklmnopqrstuvwxyz") != string::npos));
}}
