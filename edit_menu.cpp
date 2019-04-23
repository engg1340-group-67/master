#include "add.h"
#include "edit.h"
#include "delete.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include<limits>

using namespace std;
int edit_menu_main(string name,string Date) {
	system("cls");
	int options;
	while (1) {
		cout << "Name: " << name << endl;
		cout << "0: leave" << endl;
		cout << "1: add" << endl;
		cout << "2: delete" << endl;
		cout << "3: edit" << endl;
		cin >> options;
		if (options == 1) {
			add_main(Date, name);
		}
		else if (options == 2) {
			delete_main(Date, name);
		}
		else if (options == 3) {
			edit_main(Date, name);
		}
		else if (options == 0) {
			break;
		}
	}
	return 0;
}
