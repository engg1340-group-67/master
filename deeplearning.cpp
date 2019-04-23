#include <vector>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <numeric>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <sstream>
#include<fstream>
#include "predict.h"
using namespace std;

//affine->relu->affine->relu->softmax
//backward propagation, i want convolution layer + adam oringinally
//no xaiver , only standard libaray,
// what can i say
// hardcore
//function use
void initialize(vector<vector<double>> &params_1, vector<double> &const_1,
	vector<vector<double>>& params_2, vector<double>& const_2);
//struct used
struct Grad {
	vector<vector<double>> dw2; vector<double> db2; vector<vector<double>> dw1; vector<double> db1;
	Grad(vector<vector<double>> dw2, vector<double> db2, vector<vector<double>> dw1, vector<double> db1) :dw2(dw2), db2(db2), dw1(dw1), db1(db1){}
};
//Class used, affine layer
class affine {
private:
	vector<vector<double>>  params;
	vector<double> constant;
	vector<double> input;
	vector<double> sum;
	vector<vector<double>> dweight;
	vector<double> dconst;
public:
	affine(vector<vector<double>>  params_1,vector<double> const_1) :
		params(params_1), constant(const_1){}
	vector<double> forward(vector<double>input1) {// no cross product in stl
		input = input1;//we need this for backward propagation
		//cross product
		for (int i = 0; i < 6; i++) {
			sum[i] = inner_product(input1.begin(), input1.end(), params[i].begin(), 0);
			sum[i] += constant[i];
		}
		return sum;
	}
	vector<double> backward(vector<double>dout) {// no cross product in stl
		for (int i = 0; i < 6; i++) {
			sum[i] = inner_product(dout.begin(), dout.end(), params[i].begin(), 0);
		}
		// dw db not yet done
		//dw
		for (int i = 0; i < 6; i++) {
			for (int k = 0; k < 6; k++) {
				dweight[i][k] = inner_product(params[i].begin(), params[i].end(), dout.begin(), 0);
			}
		}
		//db
		for (int i = 0; i < 6; i++) {
			dconst[i] = dout[i];
		}
		return sum;
		
	}
	vector<double> getdb() {
		return dconst;
	}
	vector<vector<double>> getdw(){
		return dweight;
	}
};
//Class relu
class Relu {
private:
	vector<double> save;
public:
	vector<double> forward(vector<double> x) {
		for (int i = 0; i < 6; i++) {
			if (x[i] <= 0) {
				x[i] = 0;
			}
			save[i] = x[i];
		}
		return x;
	}
	vector<double> backward(vector<double> dout) {
		for (int i = 0; i < 6; i++) {
			if (save[i] != 0) {
				save[i] = 1;
			}
		}
		return save;
	}
};
//class entrophy
vector<double> entrophy(vector<double> y, vector<double>target) {
	vector <double> reply;
	for (int i = 0; i < 6; i++) {
		reply[i] = -target[i] * log(y[i]+0.00001);
	}
	return reply;
}
//class softmax
vector<double>softmax(vector<double> a) {
	double sum = accumulate(a.begin(), a.end(), 0);
	for (int i = 0; i < 6; i++) {
		a[i] /= sum;
	}
	return a;
}
//Class used, softmax
class Softmaxloss {
private:
	vector<double>loss;
	vector<double> y;
	vector<double> target;
	vector<double> reply;
public:
	vector<double> forward(vector<double>input,vector<double> target1) {
		target = target1;
		y = softmax(input);	
		loss = entrophy(y, target);
		return target;
	}
	vector<double> backward(vector<double>input) {
		for (int i = 0; i< 6; i++) {
			reply[i] = (y[i] - target[i]) / 6;
		}
		return reply;
	}
	
};
//major class
class two_layer_network{
public:
	//constructor
	two_layer_network(
		vector<vector<double>>  params_1,vector<double> const_1,
		vector<vector<double>> params_2,vector<double>  const_2):
		params_1(params_1),const_1(const_1),
		params_2(params_2),const_2(const_2){}
	//create layer
	void layer() {
		affine* A1 = new affine(params_1, const_1);
		Relu* R1 = new Relu;
		affine* A2 = new affine(params_2, const_2);
		Softmaxloss* final_layer = new Softmaxloss;
	}
	//predict
	vector<double> predict(vector<double> x) {
		x = A1->forward(x);
		x = R1->forward(x);
		x = A2->forward(x);
	}
	// find loss under softmass and cross entrophy
	vector<double> loss(vector<double> x, vector<double> target) {
		x = predict(x);
		return final_layer->forward(x, target);
	}
	// indeed no use, just small datas tbh.
	double accuracy(vector<double> x, vector<double> target) {
		vector < double> save;
		double acc;
		x = predict(x);
		save = final_layer->forward(x, target);
		for (int i = 0; i < 6; i++) {
			if (save[i] != 1) {
				acc += 1;
			}
		}
		return acc / 6;
	}
	// gradient
	Grad* gradient(vector<double> x, vector<double> target) {
		layer();//initialize the layer
		loss(x, target);//do forward and the help storing data
		vector<double> dout = { 1,1,1,1,1,1};
		dout = final_layer->backward(dout);
		dout = A2->backward(dout);
		dout = R1->backward(dout);
		dout = A1->backward(dout);

		dw2 = A2->getdw();
		db2 = A2->getdb();
		dw1 = A1->getdw();
		db1 = A1->getdb();
		
		Grad* grad = new Grad(dw2, db2, dw1, db1);
		return grad;
	}
	vector<double> getb(int mode) {
		if (mode == 2) {
			return const_2;
		}
		return const_1;
	}
	vector<vector<double>> getw(int mode) {
		if (mode == 2) {
			return  params_2;
		}
		return  params_1;
	}
	
private:
	vector<double> input;//6
	vector<double>  hidden;//6
	vector<double>  output;//6
	vector<vector<double>>  params_1;//6 6
	vector<double> const_1;// 6 
	vector<vector<double>> params_2;//6 6
	vector<double>  const_2;// 6
	vector<vector<double>> layer_1;//6 6
	vector<vector<double>> relu_1;// 6 6
	vector<vector<double>> layer_2;// 6 6
	vector<vector<double>> relu_2; // 6 6
	vector<double>  fin_layer;// 6
	vector<vector<double>>  dw1;//6 6
	vector<double> db1;// 6 
	vector<vector<double>> dw2;//6 6
	vector<double>  db2;// 6
	affine* A1 = NULL;
	Relu* R1 = NULL;
	affine* A2 = NULL;
	Relu* R2 = NULL;
	Softmaxloss* final_layer = NULL;

};
void initialize(vector<vector<double>> &params_1, vector<double> &const_1,
	vector<vector<double>>& params_2,vector<double>& const_2){
	vector<double> param1_size;//size of 2
	vector<double> param2_size;//size of 2
	int r_num = 0;
	for (int i = 0; i < 6; i++) {
		srand(time(0));
		r_num = (rand() % 10) + 1;
		param1_size[0] = (r_num);
		param1_size[1] = (r_num % 5 + 3);
		param2_size[0] = (r_num%3);
		param2_size[1] = (r_num/3 + 3);
		params_1.push_back(param1_size);
		params_2.push_back(param2_size);
		const_1.push_back(r_num % 5 + 1);
		const_2.push_back(r_num/2);
	}
}
Grad* DL_main(vector<vector<double>> params_1, vector<double> const_1,
	vector<vector<double>> params_2, vector<double> const_2, vector<vector<double>> x, vector<vector<double>> y){//backward
		
		int size_data = x.size();
		Grad* grad = new Grad(params_2, const_2, params_1, const_1);
		two_layer_network *mydl = new two_layer_network(params_1, const_1, params_2, const_2);
		double learning_rate = 0.1;//tbh, stl cannot use adam is hardcore,
						//i mean i dun want to type from the beginning
		//it depends on users, give him 0.1, practical won't!

		for (int i = 0; i < size_data; i++) {
			grad = mydl->gradient(x[i], y[i]);////important, input data area
			vector<vector<double>>w1 = mydl->getw(1);
			vector<vector<double>>w2 = mydl->getw(2);
			vector<double>b1 = mydl->getb(1);
			vector<double>b2 = mydl->getb(2);
			for (int j = 0; j < 6; j++) {
				const_2[j] -= learning_rate * (grad->db2)[j];
				const_1[j] -= learning_rate * grad->db1[j];
				for (int k = 0; k < 6; j++) {
					params_2[k][j] -= learning_rate * grad->dw2[k][j];
					params_1[k][j] -= learning_rate * grad->dw1[k][j];
				}
			}
		}
		//double acc = mydl->accuracy(x, y);
		//cout << acc;
		delete mydl;
		// write to dl sheet
		ofstream fwrite("deeplearning.txt");
		for (int i = 0; i < 6; i++) {
			fwrite << const_1[i] << " ";
		}
		for (int i = 0; i < 6; i++) {
			fwrite << const_2[i] << " ";
		}
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				fwrite << params_1[k][j] << " ";
			}
		}
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				fwrite << params_2[k][j] << " ";
			}
		}
		fwrite.close();
		// end of training
		
		return grad;
}
vector<double> DL_forward(vector<vector<double>> params_1, vector<double> const_1,
	vector<vector<double>> params_2, vector<double> const_2, vector<double> x) {
	two_layer_network *myforward = new two_layer_network(params_1, const_1, params_2, const_2);
	vector<double>x = myforward->predict(x);
	delete myforward;
	return x;
}
vector<vector<double>> get_data(string name, string from, string to) {
	int month, day, end_day, end_month;
	string calander[32] = { "00","01","02","03","04","05","06","07","08","09","10","11","12","13" };
	for (int i = 14; i<32; i++) {
		calander[i] = to_string(i);
	}
	vector<double> temp;
	vector<vector<double>> ans;
	string filename;
	istringstream iss1(from.substr(0,2));//month
	iss1 >> month;
	istringstream iss2(from.substr(2, 2));//day
	iss2 >> end_month;
	istringstream iss3(to.substr(0, 2));//month
	iss3 >> month;
	istringstream iss4(to.substr(2, 2));//day
	iss4 >> end_day;
	for (int i = month; i < end_month+1; i++) {
		for (int j = 1; j < 31; j++) {
			filename = name + calander[i] + calander[j];
			for (int k = 0; k < 6; k++) {
				temp[i] = reporter(filename, i);
			}
			ans.push_back(temp);
		}
		if (month == end_month) {
			for (int j = 1; j < end_day; j++) {
				filename = name + calander[i] + calander[j];
				for (int k = 0; k < 6; k++) {
					temp[i] = reporter(filename, i);
				}
				ans.push_back(temp);
			}
		}
	}
	return ans;
}
vector<double> DL() {
	string name;
	string from;
	string to;
	vector<vector<double>> w1; vector<double> b1;
	vector<vector<double>> w2; vector<double> b2;
	vector<vector<double>> x; vector<vector<double>> y;
	vector<double> ans;
	x = get_data(name,from,to);
	y = get_data(name,from,to);
	int size = 0;
	ifstream fopen("deeplearning.txt");
	if (fopen.fail()) {
		fopen.close();
		exit(1);
	}
	for (int i = 0; i < 6; i++) {
		fopen >> b1[i];
	}
	for (int i = 0; i < 6; i++) {
		fopen >> b2[i];
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fopen >> w1[k][j];
		}
	}
	for (int j = 0; j < 6; j++) {
		for (int k = 0; k < 6; k++) {
			fopen >> w2[k][j];
		}
	}
	
	Grad* grad = DL_main(w1, b1, w2, b2, x, y);
	ans = DL_forward(grad->dw1, grad->db1, grad->dw2, grad->db2, x[x.size()-1]);
	delete grad;
	return ans;
}
int main() {
	vector<double> mypredict = DL();
	for (int i = 0; i < 6; i++) {
		cout << mypredict[i] << endl;
	}
	return 0;
}