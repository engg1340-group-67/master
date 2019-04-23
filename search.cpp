#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
void txt_produce(int mode, string namedate) {
	bool break_confirm = 0;
	string filename;
	string line;
	string confirm;
	string addmenu[] = { "food.txt","transportation.txt","toy.txt","stationary.txt","others.txt","gains.txt" };
	if (mode != 7) {
		filename = namedate + addmenu[mode - 1];
		cout << "f" << filename << endl;
		ifstream fread(filename.c_str());
		if (fread.fail()) {
			cout << "error on reading " << filename << endl;
			fread.close();
		}
		while (getline(fread, line)) {
			cout << line << endl;
		}
		while (1) {
				cout << "Quit(Y/N): "; cin >> confirm;
				if (confirm == "Y") {
					system("cls");
					break;
				}
				else if (confirm == "N") {

				}
			}
				
		fread.close();
	}
	else {
		for (int i = 1; i < 7; i++) {
			filename = namedate + addmenu[i - 1];
			ifstream fread(filename.c_str());
			if (fread.fail()) {
				cout << "error on reading " << filename << endl;
				fread.close();
			}
			while (getline(fread, line)) {
				cout << line << endl;
			}
			fread.close();
			while (1) {
				cout << "Next file(Y/N): "; cin >> confirm;
				if (confirm == "Y") {
					system("cls");
					break;
				}
				else if (confirm == "N") {
					system("cls");
					break_confirm = 1;
					break;
				}
			}
			if (break_confirm == 1) {
				break;
			}
		}
	}
}
int search(string name) {
	string Date;
	int scope = 0;
	cout << "***\tSearch\t***  " << endl;
	cout << "Date: ";
	cin >> Date;
	cout << endl;
	
	cout << "***Scope***" << endl;
	cout << "0. leave" << endl;
	cout << "1. food" << endl;
	cout << "2. transportation" << endl;
	cout << "3. toy" << endl;
	cout << "4. stationary" << endl;
	cout << "5. others" << endl;
	cout << "6. gain" << endl;
	cout << "7. All" << endl;
	cout << "Scope: ";
	cin >> scope;
	txt_produce(scope,name+Date);
	return 0;
}
