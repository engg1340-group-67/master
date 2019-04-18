#include "add.h"
#include "search.h"
#include "edit.h"
#include "delete.h"
#include "sort.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include<limits>
using namespace std;

int main() {
	string Date;
	string name;
	cout << "すみません" << endl;
	cout << "Name: ";
	cin >> name;
	cout << endl;
	system("cls");
	int options;
	while (1) {
		cout << "Name: " << name << endl;
		cout << "1: add" << endl;
		cout << "2: delete" << endl;
		cout << "3: edit" << endl;
		cout << "4: search file" << endl;
		cout << "5: sort" << endl;
		cout << "6: leave" << endl;
		cin >> options;
		if (options == 1) {
			cout << "Date: ";
			cin >> Date;
			cout << endl;
			add_main(Date, name);
		}
		else if (options == 2) {
			cout << "Date: ";
			cin >> Date;
			cout << endl;
			delete_main( Date, name);
		}
		else if (options == 3) {
			cout << "Date: ";
			cin >> Date;
			cout << endl;
			edit_main(Date,name);
		}
		else if (options == 4) {
			cout << endl;
			search(name);
		}
		else if (options == 5) {
			cout << "Date: ";
			cin >> Date;
			cout << endl;
			sort(name,Date);
		}
		else if (options == 6) {
			break;
		}
	}
	return 0;
}