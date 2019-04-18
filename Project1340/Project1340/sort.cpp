#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <array>
#include "delete.h"
#include "add.h"
using namespace std;
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return;
}

data_template sort_by_name(data_template data, int size) {
	data_template new_data(size);
	//greet 
	system("cls");
	int mode = 0;
	cout << "sort by name" << endl;
	cout << "***1->Ascending Order***" << endl;
	cout << "***2->Descending Order***" << endl;
	cout << "Mode :" << endl;
	cin >> mode;
	cout << endl;
	int* save = new int[size];

	int save_to_data = 0;
	//initialize the int list
	for (int i = 0; i < size; i++) {
		save[i] = i;
	}

	int i, j, idx;
	int min;
	string current;
	for (i = 0; i < size; ++i)
	{
		current = data.name[save[i]];
		min = save[i];
		idx = i;
		for (j = i + 1; j < size; ++j)
		{
			if (data.name[save[j]][0] == current[0]) {
				if (data.name[save[j]].length() < current.length() and mode == 1) {
					current = data.name[save[j]];
					min = save[j];
					idx = j;
				}
				else if (data.name[save[j]].length() > current.length() and mode == 2) {
					current = data.name[save[j]];
					min = save[j];
					idx = j;
				}
			}
			if (data.name[save[j]] < current and mode == 1)
			{
				current = data.name[save[j]];
				min = save[j];
				idx = j;
			}
			else if (data.name[save[j]] > current and mode == 2) {
				current = data.name[save[j]];
				min = save[j];
				idx = j;
			}
		}
		if (idx != i) {
			swap(save[i], save[idx]);
		}
	}
	cout << "save list" << endl;
	for (int i = 0; i < size; i++) {
		cout << save[i] << endl;
	}
	//test
	
	for (int i = 0; i < size; i++) {
		save_to_data = save[i];
		new_data.name[i] = data.name[save_to_data];
		new_data.no[i] = data.no[save_to_data];
		new_data.price[i] = data.price[save_to_data];
	}
	delete [] data.name, data.no, data.price;
	return new_data;
}
data_template sort_by_num(data_template data, int size) {
	//greet
	system("cls");
	cout << "Sort by item" << endl;
	int mode = 0;
	cout << "***1 Ascending Order***" << endl;
	cout << "***2 Descending Order***" << endl;
	cout << "Mode :";
	cin >> mode;
	cout << endl;


	data_template new_data(size);
	int* save = new int[size];
	int save_to_data = 0;
	//initialize the int list
	for (int i = 0; i < size; i++) {
		save[i] = i;
	}

	int i, j, idx;
	int min;
	int current;
	for (i = 0; i < size; ++i)
	{
		current = data.no[save[i]];
		min = save[i];
		idx = i;
		for (j = i + 1; j < size; ++j)
		{
			if (data.no[save[j]] < current and mode == 1)
			{
				current = data.no[save[j]];
				min = save[j];
				idx = j;
			}
			else if (data.no[save[j]] > current and mode == 2)
			{
				current = data.no[save[j]];
				min = save[j];
				idx = j;
			}
		}
		if (idx != i) {
			swap(save[i], save[idx]);
		}
	}
	//test

	for (int i = 0; i < size; i++) {
		save_to_data = save[i];
		new_data.name[i] = data.name[save_to_data];
		new_data.no[i] = data.no[save_to_data];
		new_data.price[i] = data.price[save_to_data];
	}
	delete[] data.name, data.no, data.price;
	return new_data;
}
data_template sort_by_price(data_template data, int size) {
	//greet
	system("cls");
	cout << "Sort by price" << endl;
	int mode = 0;
	cout << "***1 Ascending Order***" << endl;
	cout << "***2 Descending Order***" << endl;
	cout << "Mode :";
	cin >> mode;
	cout << endl;
	

	data_template new_data(size);
	int* save = new int[size];
	int save_to_data = 0;
	//initialize the int list
	for (int i = 0; i < size; i++) {
		save[i] = i;
	}
	int i, j, idx;
	int min;
	double current;
	for (i = 0; i < size; ++i)
	{
		current = data.price[save[i]];
		min = save[i];
		idx = i;
		for (j = i + 1; j < size; ++j)
		{

			if (data.price[save[j]] < current and mode == 1)
			{
				current = data.price[save[j]];
				min = save[j];
				idx = j;
			}
			else if (data.price[save[j]] > current and mode == 2)
			{
				current = data.price[save[j]];
				min = save[j];
				idx = j;
			}
		}
		if (idx != i) {
			swap(save[i], save[idx]);
		}
	}
	//test

	for (int i = 0; i < size; i++) {
		save_to_data = save[i];
		new_data.name[i] = data.name[save_to_data];
		new_data.no[i] = data.no[save_to_data];
		new_data.price[i] = data.price[save_to_data];
	}
	delete[] data.name, data.no, data.price;
	return new_data;
}
void sortmenu() {
	cout << "1. food" << endl;
	cout << "2. transportation" << endl;
	cout << "3. toy" << endl;
	cout << "4. stationary" << endl;
	cout << "5. others" << endl;
	cout << "6. gain" << endl;
}
int sort(string name, string date) {
	system("cls");
	int scope = 0;
	string line;
	string confirm;
	string addmenu[] = { "food","transportation","toy","stationary","others","gains" };
	string str[] = { "food.txt","transportation.txt","toy.txt","stationary.txt","others.txt","gains.txt" };
	double sum = 0;
	int mode = 0;
	int iterator= 0;
	int no = 0;
	int filesize = 0;
	double price = 0;
	//greet
	//choice
	sortmenu();
	cin >> scope;
	cout << endl;
	//file
	string filename = name + date + str[scope - 1];
	filesize = print_filetext(filename);
	int length_of_text = length_check(filename);
	cout << "length of test " << filesize << endl;
	data_template data(filesize);
	data_template new_data(filesize);
	ifstream fread(filename.c_str());
	if(fread.fail()){
		cout << "error" << endl;
		exit(1);
	}
	getline(fread, line);
	while (1) {
		//getting the price information
		fread >> no;
		fread >> data.name[iterator];
		fread >> data.no[iterator];
		fread >> data.price[iterator];
		iterator++;
		if (iterator == filesize - 1) {
			break;
		}
	}
	fread.close();
	cout << "***1 -> Sort by name***" << endl;
	cout << "***2 -> Sort by number of item***" << endl;
	cout << "***3 -> Sort by number of price***" << endl;
	cin >> mode;
	if (iterator == 1) {
		return 0;
	}
	if (mode == 1) {
		cout << " iterator " << iterator << endl;
		new_data = sort_by_name(data, iterator);
	}
	else if (mode == 2) {
		new_data = sort_by_num(data, iterator);
	}
	else {
		new_data = sort_by_price(data, iterator);
	}
	//file make and print
	cout << "Updataed Version" << endl;
	string* passage = new string[filesize+1];
	passage[0] = "\tName\tno\tprice";
	cout << passage[0] << endl;
	for (int i = 1; i < filesize; i++) {
		passage[i] = to_string(i) + "\t" + new_data.name[i-1] + "\t" + to_string(new_data.no[i-1]) + "\t" + to_string(new_data.price[i - 1]) ;
		sum += new_data.price[i-1];
		cout << passage[i] << endl;
	}
	
	passage[filesize] = "total " + addmenu[scope-1] + " "  + to_string(sum);
	cout << passage[filesize] << endl;
	//greet
	cout << "Update it (Y/N) ??";
	cin >> confirm;
	cout << endl;
	if (confirm == "Y") {
		ofstream fwrite(filename.c_str());
		if (fwrite.fail()) {
			cout << "error" << endl;
			exit(1);
		}
		for (int i = 0; i < filesize; i++) {
			fwrite << passage[i] << endl;
		}
		fwrite.close();
	}
	delete[] passage, new_data.name, new_data.no, new_data.price;
	return 0;
}