//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
//***************************************************************
//    	Used class
//****************************************************************
class data_template {
	int size = 0;

public:
	data_template(int length) :size(length) {};
	int* no = new int[size];
	string* name = new string[size];
	double* price = new double[size];
};

//***************************************************************
//    	function declaration
//****************************************************************
//***************************************************************
//   Check file_size
//****************************************************************
int length_check(string filename) {
	int i = 0;
	string line;
	ifstream fwrite(filename.c_str());
	while (getline(fwrite, line)) {
		i++;
	}
	return i;
}
//***************************************************************
//    	Filetxt creator
//****************************************************************
string filetxt(string name, string date, int mode) {
	string addmenu[] = { "food.txt","transportation.txt","toy.txt","stationary.txt","others.txt","gains.txt" };
	string filename = name + date + addmenu[mode - 1];
	return filename;
}
//***************************************************************
//    	Initialization
//****************************************************************
void initialization(string filename) {
	string file;
	string addmenu[] = { "food","transportation","toy","stationary","others","gains" };
	for (int i = 0; i < 6; i++) {
		file = filename + addmenu[i] + ".txt";
		ofstream fwrite (file.c_str());
		if (fwrite.fail()) {
			cout << "??" << endl;
			exit(1);
		}
		fwrite << "\t" << "Name\t" << "Number\t" << "Price" << endl;
		fwrite << "1" << endl;
		fwrite << "Total " << addmenu[i] << " 0";
		fwrite.close();
	}
}
//***************************************************************
//    	Double check 
//****************************************************************
int double_validation_double(double &num) {

	string confirm;
	while (1) {
		if (num >= 100) {
			cout << "Confirm $" << num << "(Y/N): ";    cin >> confirm;
			cout << endl;
			cout << endl;
			if (confirm == "Y") {
				return 0;
			}
			else if (confirm == "N") {
				cout << "Delete $" << num << "(Y/N): "; cin >> confirm;
				cout << endl;
				cout << endl;
				if (confirm == "N") {
					cout << "Enter a new price: ";      cin >> num;
					cout << endl;
					return 0;
				}
				else if (confirm == "Y") {
					return 1;
				}
			}
		}
		else {
			return 0;
		}
	}
}
int double_validation_int(int &num) {

	string confirm;
	while (1) {
		if (num >= 10) {
			cout << "Confirm " << num << "item(Y/N): ";  cin >> confirm;
			if (confirm == "Y") {
				return 0;
			}
			else if (confirm == "N") {
				cout << "Delete size: " << num << "(Y/N): "; cin >> confirm;
				cout << endl;
				if (confirm == "N") {
					cout << "Enter a new size: ";      cin >> num;
					cout << endl;
					return 0;
				}
				else if (confirm == "Y") {
					return 1;
				}
			}
		}
		else {
			return 0;
		}
	}
}
//***************************************************************
//    copy temp to targeted file
//****************************************************************
void filecopy(string filename) {
	string line;
	ifstream fread("temp.txt");
	if (fread.fail()) {
		cout << "cannot open temp file" << endl;
		exit(1);
	}
	ofstream fwrite(filename);
	if (fread.fail()) {
		cout << "cannot open " << filename << " file" << endl;
		exit(1);
	}
	while (getline(fread, line)) {
		fwrite << line << endl;
	}
	fwrite.close();
	fread.close();
}
//***************************************************************
//    	write the data to temp
//****************************************************************
void add_write(int mode, data_template data, string filename, int iter) {
	string lastline_obj;
	string line;
	string lastline;
	string key;
	string addmenu[] = { "food","transportation","toy","stationary","others","gains" };
	double previous_sum = 0;
	double sum = 0;
	int last_num = 0;
	//greeting
	cout << "We are processing sector of " << addmenu[mode - 1] << "..." << endl;
	key = "Total " + addmenu[mode - 1];//lastline Total food xxx
	char c;//char
	int count = 0;//breaking point counter
	int i;//iteration
	std::ifstream myFile(filename.c_str(), std::ios::ate);
	std::streampos size = myFile.tellg();
	for (i = 1; i <= size; i++) {
		myFile.seekg(-i, std::ios::end);
		myFile.get(c);
		if (c == '\n') {
			count++;
		}
		if (count == 5) {
			break;
		}
	}
	
	system("pause");
	myFile.seekg(-i + 1, std::ios::end);
	getline(myFile, line);
	//cout << "line" << line << endl;
	istringstream is(line);
	is >> last_num;
	//cout << "helpp" << last_num << endl;
	//cout << "last num" << last_num << endl;
	myFile.close();
	//reading the previous file and then pass it to temp file
	ifstream fread(filename.c_str());//must able to open
	if (fread.fail()) {
		cout << "cannot open fread " << endl;
		exit(1);
	}
	ofstream fwrite("temp.txt");
	if (fwrite.fail()) {
		cout << "cannot open fread " << endl;
		exit(1);
	}
	//writing first line
	getline(fread, line);
	fwrite << line << endl;
	//checking second line
	getline(fread, line);
	if (line != "1") {
		fwrite << line << endl;
	}
	else {
		//ignore writing this initialized line
		cout << "line size" << line.size() << endl;
		if (line.size() < 2) {
			last_num = 0;
		}
		//system("pause");
	}
	//find last line and write before last line
	while (getline(fread, line)) {
		if (line.find(key) != -1) {
			lastline = line;
		}
		else {
			fwrite << line << endl;
		}
	}
	fread.close();
	//taging 123456... for items and writing
	for (int i = 0; i < iter; i++) {
		last_num++;
		fwrite << last_num << "\t" << data.name[i] << "\t" << data.no[i] << "\t" << data.price[i] << endl;
		sum += data.price[i];
	}
	istringstream iss(lastline);
	while (iss >> line) {
		iss >> line;
		iss >> previous_sum;
	}
	fwrite << key << " " << (sum + previous_sum);
	fwrite.close();
	filecopy(filename);
}
//***************************************************************
//    	add function
//****************************************************************
void add(int mode, string filename) {
	//variable used
	int size_of_array = 0;
	int iterator = 0;
	string addmenu[] = { "food","transportation","toy","stationary","others","gains" };

	//Heading
	cout << "Number of data: ";
	cin >> size_of_array;
	cout << endl;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a number" << endl;
			cout << endl;
			cin >> size_of_array;
		}
		if (!cin.fail()) {
			break;
		}
	}
	if (!size_of_array) {
		return;
	}
	//construct a data block
	data_template data(size_of_array);

	//Content
	while (1) {

		cout << "No." << iterator + 1 << " data of " << addmenu[mode - 1];
		cout << endl;
		cout << endl;
		cout << "Name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		std::getline(cin, data.name[iterator]);
		cout << endl;

		//no
		cout << "No of item "; cin >> data.no[iterator];
		cout << endl;
		//check input
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number" << endl;
				cout << endl;
				cin >> data.no[iterator];
			}
			if (!cin.fail()) {
				break;
			}
		}

		//price
		cout << "Price: ";
		cin >> data.price[iterator];
		cout << endl;
		//check input
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number" << endl;
				cout << endl;
				cin >> data.price[iterator];
			}
			if (!cin.fail()) {
				break;
			}
		}
		//check if number >= 100 
		if (!double_validation_int(data.no[iterator]) and !double_validation_double(data.price[iterator])) {
			iterator++;
		}
		if (iterator == size_of_array) {
			break;
		}
	}
	add_write(mode, data, filename, iterator);
}
//***************************************************************
//    	Print addmenu 
//****************************************************************
void addmenu() {
	cout << "0. leave" << endl;
	cout << "1. food" << endl;
	cout << "2. transportation" << endl;
	cout << "3. toy" << endl;
	cout << "4. stationary" << endl;
	cout << "5. others" << endl;
	cout << "6. gain" << endl;
	cout << "7, re-Initialization" << endl;
}
int add_main(string Date, string Name) {
	string name = "wesley";
	string filename;
	
	filename = "wesley0412";//later modify
	int mode = 0;
	do {
		cout << endl;
		system("cls");
		//heading
		cout << "Date: " << Date << endl;
		cout << "***\tScope\t***" << endl;
		
		//print menu
		addmenu();

		//Scope
		cout << "Scope: "; cin >> mode; cout << endl;
		
		filename = name + Date;
		//entering mode
		while (1) {
			if (mode > 7 or mode < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter number within range(0-7)" << endl;
				cout << endl;
				cin >> mode;
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number" << endl;
				cout << endl;
				cin >> mode;
			}
			if (!cin.fail() or (mode<8 and mode>0)) {
				break;
			}
		}

		//handler
		if (mode == 0) {
			break;
		}
		else if (mode == 7) {
			initialization(filename);
			continue;
		}
		//file comprosing
		filename = filetxt(name, Date, mode);
		//add major colume
		add(mode, filename);


		//
	} while (1);
	//system("pause");
	system("pause");
	return 0;
}

