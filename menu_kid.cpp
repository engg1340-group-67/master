#include "edit_menu.h"
#include "search.h"
#include "sort.h"
#include "add.h"
#include "predict.h"
#include "deeplearning.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include <string>
#include <limits>
//#include"login.h"
using namespace std;

void our_group();
void no_of_tasks();
void create_task();
//string username;
int menu_main(string name)
{	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string Filename;
	string Date;
	char ch;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); // program outputs decimal number to two decimal places
	our_group();
	create_task();
	//cout << username;
	do
	{	
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. EDIT YOUR WALLET";
	  cout<<"\n\n\t02. REPORT";
		cout<<"\n\n\t03. SEARCH";
		cout<<"\n\n\t04. TASKS";
		no_of_tasks();
		cout << "\n\n\t05. SORT";
		cout << "\n\n\t06. INITIALIZE";
		cout << "\n\n\t07. Deep Learning";
		cout<<"\n\n\t00. EXIT";
		cout<<"\n\n\tPlease Select Your Option (0-6) ";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout << "\n\n\t MMDD(0101)";
				cout << "DATE :"; cin >> Date;
				edit_menu_main(name,Date);
				break;
			case '2':
				cout << "\n\n\t MMDD(0101)";
				cout << "DATE :"; cin >> Date;
				predict_main(name, Date);
				break;
			case '3':
				search(name);
				break;
			case '4':
				break;
			case '5':
				cout << "\n\n\t MMDD(0101)";
				cout << "DATE :"; cin >> Date;
				sort(name,Date);
				break;
			case '6':
				cout << "\n\n\t MMDD(0101)";
				cout << "DATE :"; cin >> Date;
				Filename = name+Date;
				initialization(Filename);
				break;
			case '7':
				system("cls");
				deep_learning_main(name);
				break;
			default :cout<<"\a";
		}
    }while(ch!='0');
	return 0;
}

void our_group(){
	cout<<"\n\n\n\t  ENGG1340 Group Project";
	cout<<"\n\n\t    Accounting system";
	cout<<"\n\n\t Your Financial Majordomo";
	cout<<"\n\n\n\tGroup : 67";
	cout<<"\n\tMADE BY : Chu Wai Kit ";
	cout<<"\n\tMADE BY : Yam Chak Fung Wesley";
	cin.get();
}
void create_task(){
	ofstream fout;
	fout.open("task.txt");
	if (fout.fail()){
		cout << " Error in file opening!"<<endl;
		exit(1);
	}
	fout.close();
}
void no_of_tasks(){
	int n=0;
	string line;
	ifstream fin("task.txt");
	if (fin.fail()){
		cout<< " Error in file opening!"<<endl;
		exit(1);
	}
	while( getline(fin,line)){
		n++;
	}
	if (n/3>1)
		cout <<" - "<< n << " tasks waiting you to finish";
	else
		cout <<" - "<< n << " task waiting you to finish";
}
