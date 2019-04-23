#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "delete.h"
#include "dl.h"
using namespace std;
double reporter(string, int);//for connector use only
vector<double> connector(string filename) {
	vector<double> predict_array;
	double sum = 0;
	for (int i = 0; i<6; i++) {
		predict_array.push_back(reporter(filename, i));
	}
	return predict_array;
}
vector<double> predict_mean(string name, string Date) {
	vector<vector<double>> sum;
	vector<double> predict_day;
	string calander[32] = { "00","01","02","03","04","05","06","07","08","09","10","11","12","13" };
	string big_small[12] = { "31","28","31","30","31","30","31","31","30","31","30","31" };
	for (int i = 14; i<32; i++) {
		calander[i] = to_string(i);
	}
	string month_s = Date.substr(0, 2);
	string filename;
	double price = 0;
	int day_arr[3];
	string day_s = Date.substr(2, 2);
	int day = atoi(day_s.c_str());
	int month = atoi(month_s.c_str());

	if (day < 2) {
		if (day == 2) {
			filename = name + Date;
			sum.push_back(connector(filename));
			filename = name + month_s + "01";
			sum.push_back(connector(filename));
			filename = name + calander[month - 1] + big_small[month - 2];
			sum.push_back(connector(filename));
		}
		else if (month == 1) {
			filename = name + Date;
			sum.push_back(connector(filename));
			sum.push_back(connector(filename));
			sum.push_back(connector(filename));
		}
		else {
			filename = name + Date;
			sum.push_back(connector(filename));
			filename = name + calander[month - 1] + big_small[month - 2];
			sum.push_back(connector(filename));
			day = atoi((big_small[month - 2]).c_str());
			filename = name + calander[month - 1] + to_string(day - 1);
			sum.push_back(connector(filename));
		}
	}
	else {

		filename = name + Date;
		sum.push_back(connector(filename));

		filename = name + month_s + calander[day - 1];
		sum.push_back(connector(filename));

		filename = name + month_s + calander[day - 2];
		sum.push_back(connector(filename));
	}

	for (int i = 0; i<6; i++) {
		price = sum[0][i] + sum[1][i] + sum[2][i];
		price /= 3;
		predict_day.push_back(price);
	}
	return predict_day;
}
double reporter(string filename, int mode) {

	string str[6] = { "food.txt","transportation.txt","toy.txt","stationary.txt","others.txt","gains.txt" };
	filename = filename + str[mode];
	ifstream fvalid(filename.c_str());
	if (fvalid.fail()) {
		fvalid.close();
		return 0;
	}
	fvalid.close();
	int filesize = print_filetext(filename.c_str(), 0);
	string line;
	double sum = 0;
	int no, size, price;
	// read

	ifstream fread(filename.c_str());
	if (fread.fail()) {
		fread.close();
		return 0;
	}
	for (int i = 0; i < filesize; i++) {
		getline(fread, line);
	}
	fread >> line >> line >> sum;
	fread.close();
	//cout << "sum " << sum << endl; 
	return sum;
}

double predict_main(string name, string Date) {
	system("cls");
	//storing
	string confirm;
	double price = 0;
	double sum = 0;
	vector <double> v;
	vector <double> p = predict_mean(name, Date);
	vector <double> dl = deep_learning_main(name);
	string filename = name + Date;
	ofstream fout((filename + "report.txt").c_str());
	ifstream fread((filename + "report.txt").c_str());
	if (fread.fail()) {
		cout << "Not such a day infomation" << endl;
		return 0;
	}
	cout << "\n\n\t\t REPORT \n\n";
	fout << "\n\n\t\t REPORT \n\n";
	cout << "NAME: " << name << endl;
	fout << "NAME: " << name << endl;
	cout << "=================================================================================\n";
	fout << "=================================================================================\n";
	cout << "Date Food(%) Transportation(%) Toy(%) Stationary(%) Other(%) Expense(%) Income(%)" << endl;
	fout << "Date Food(%) Transportation(%) Toy(%) Stationary(%) Other(%) Expense(%) Income(%)" << endl;
	cout << "=================================================================================\n";
	fout << "=================================================================================\n";
	cout << Date << " ";
	for (int i = 0; i < 5; i++) {
		price = reporter(filename, i);
		sum += price;
		v.push_back(price);
	}
	v.push_back(reporter(filename, 5));
	for (int i = 0; i < 5; i++) {
		cout << fixed << setprecision(2) << v[i];
		cout << "(" << v[i] / sum * 100 << "%" << ")";
		cout << "  ";
		fout << fixed << setprecision(2) << v[i];
		fout << "(" << v[i] / sum * 100 << "%" << ")";
		fout << "  ";
	}
	cout << fixed << setprecision(2) << v[5];
	cout << "(100%)";
	fout << fixed << setprecision(2) << v[5];
	fout << "(100%)";
	cout << endl;
	fout << endl;
	cout << "=================================================================================\n";
	fout << "=================================================================================\n";
	cout << "\n";
	fout << "\n";
	cout << "=================================================================================\n";
	fout << "=================================================================================\n";
	cout << "NET: "; cout << sum - v[5] << endl;
	fout << "NET: "; fout << sum - v[5] << endl;
	cout << "PREDICTION(NEXT DAY)\n";
	fout << "PREDICTION(NEXT DAY)\n";
	cout << "============================================================================\n";
	fout << "============================================================================\n";
	fout << "TYPE Food(%) Transportation(%) Toy(%) Stationary(%) Other(%) Expense(%) Income(%)" << endl;
	cout << "TYPE Food(%) Transportation(%) Toy(%) Stationary(%) Other(%) Expense(%) Income(%)" << endl;
	cout << "============================================================================\n";
	fout << "============================================================================\n";
	//mean
	sum = 0; //reinitialize
	price = 0;
	for (int i = 0; i < 5; i++) {
		price = p[i];
		sum += price;
	}
	cout << "MEAN";
	fout << "MEAN";
	for (int i = 0; i < 5; i++) {
		cout << fixed << setprecision(2) << p[i];
		cout << "(" << p[i] / sum * 100 << "%" << ")";
		cout << "  ";
		fout << fixed << setprecision(2) << p[i];
		fout << "(" << p[i] / sum * 100 << "%" << ")";
		fout << "  ";
	}
	cout << fixed << setprecision(2) << p[5];
	cout << "(100%)";
	fout << fixed << setprecision(2) << p[5];
	fout << "(100%)";
	cout << endl;
	fout << endl;
	cout << "=================================================================================\n";
	fout << "=================================================================================\n";
	cout << "\n";
	fout << "\n";
	cout << "=================================================================================\n";
	fout << "=================================================================================\n";
	cout << "NET: "; cout << sum - p[5] << endl;
	fout << "NET: "; fout << sum - p[5] << endl;
	//DL
	sum = 0; //reinitialize
	price = 0;
	for (int i = 0; i < 5; i++) {
		price = dl[i];
		sum += price;
	}
	cout << "============================================================================\n";
	fout << "============================================================================\n";
	fout << "TYPE Food(%) Transportation(%) Toy(%) Stationary(%) Other(%) Expense(%) Income(%)" << endl;
	cout << "TYPE Food(%) Transportation(%) Toy(%) Stationary(%) Other(%) Expense(%) Income(%)" << endl;
	cout << "============================================================================\n";
	fout << "============================================================================\n";
	cout << "DL";
	fout << "DL";
	//abs sum
	sum = abs(sum);
	for (int i = 0; i < 5; i++) {
		cout << fixed << setprecision(2) << abs(dl[i]);
		cout << "(" << abs(dl[i]) / abs(sum) * 100 << "%" << ")";
		cout << "  ";
		fout << fixed << setprecision(2) << abs(dl[i]);
		fout << "(" << abs(dl[i]) / abs(sum) * 100 << "%" << ")";
		fout << "  ";
	}
	cout << fixed << setprecision(2) << abs(dl[5]);
	cout << "(100%)";
	fout << fixed << setprecision(2) << abs(dl[5]);
	fout << "(100%)";
	cout << endl;
	fout << endl;
	cout << "============================================================================\n";
	fout << "============================================================================\n";
	cout << "\n";
	fout << "\n";
	cout << "============================================================================\n";
	fout << "============================================================================\n";

	cout << "NET: "; cout << sum - dl[5] << endl;
	fout << "NET: "; fout << sum - dl[5] << endl;
	while (1) {
		cout << "QUIT(Y/N): "; cin >> confirm;
		if (confirm == "Y") {
			system("cls");
			break;
		}
		else if (confirm == "N") {
		}
	}
	fout.close();
	return 0;
}