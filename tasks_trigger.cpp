
#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include<iomanip>
//#include"login.h"

using namespace std;

struct Node{
	string info;
	int info_2;
	bool info_3;
	Node * next;
};


void assign_tasks(Node * & head,	Node * & tail);
void tail_insert(Node * & head,	Node * & tail, string task, int bonus,bool done);
void remove_tasks(Node * & head,	Node * & tail);
void Sort_tasks(Node * & head);
void Initialize_task(Node * &head);
//string username;
void write_file(Node * &head);
void read_task(Node *& head,	Node * & tail);
void MergeSort(Node** headRef);
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,	Node** frontRef, Node** backRef);
int print_list(Node * head);
void view_tasks(Node * & head,	Node * & tail);
bool confirm();
bool keep_going();
/* sorts the linked list by changing next pointers (not data) */

//***************************************************************
//    	Task trigger for parents part
//****************************************************************
int  parents_task_main(){
	char ch;
	string task="";

	Node * head = NULL, * tail = NULL;
	read_task(head, tail);
	do{
	system("cls");
	cout<<"\n\n\n\tTasks Trigger";
	cout<<"\n\n\n\t1. Assign Tasks";
	cout<<"\n\n\t2. Remove Tasks";
	cout<<"\n\n\t3. Sort Tasks";
	cout<<"\n\n\t4. Initialize Tasks";
	cout<<"\n\n\t0. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (0-4)? ";
	cin>>ch;

	switch(ch)
	{
	case '1' :assign_tasks( head,	tail); break;
	case '2' :remove_tasks(head,	tail); break;
	case '3' :Sort_tasks(head);	 break;
	case '4' :Initialize_task(head);	break;
	case '0' :break;
	default:	cout<<"\a";
}}while(ch!='0');
 write_file(head);
return 0;
}

void assign_tasks(Node * & head,	Node * & tail){

	string task;
	char ch,ch_2;
	int bonus;
	bool done;
	do{
	cout<<"\n\n==========================================================\n";
	cout<<"\n\tEnter enter the task : ";
	getline(cin>>ws,task);
	cout<<"\n\tEnter bonus for completeing all tasks : $";
	(cin >> bonus).get();
	cout << "\n\tConfirm ? (y/n)";
	cin>>ch;
if (ch=='y')
	tail_insert(head,	tail,  task, bonus, done=false);
cout <<"\n\tContinue? (y/n)";
cin>>ch;
if (ch !='y'&& ch !='n')
	cout<<'\a';
}while(ch!='n');

}

void remove_tasks(Node * & head, Node * & tail) {
	int remove_line, count;
	char ch;
	if (head == NULL) {
		cout << "\n\n==========================================================\n";

		cout << "\n\tThere is no task.";
		cin.get();
	}
	else {
		count = print_list(head);
		cout << "\n\n==========================================================\n";
		cout << "\n\tWhich line you wish to remove? (0-" << count - 1 << ")";
		cin >> remove_line;
		if (remove_line == 0)
			return;
		else if (remove_line == 1) {
			cout << "\n\n\tConfirm ? (y/n) ";
			cin >> ch;
			if (ch == 'y') {
				Node * current = head;
				head = head->next;
				delete current;
			}
		}
		else if (remove_line < count&&remove_line>1) {
			//cout<<"1";
			cout << "\n\n\tConfirm ? (y/n) ";
			cin >> ch;
			if (ch == 'y') {
				Node * current = head;
				for (int i = 0; i < remove_line - 2; i++) {
					current = current->next;
					//cout<<"2";
				}
				Node * p = current->next;
				current->next = p->next;
				delete p;

			}
		}
		if (ch == 'y') {
			if (head != NULL) {
				cout << "\n\n==========================================================\n";
				count = print_list(head);

				cout << "\n\n==========================================================\n";
				cout << "\n\n\tRemoved successfully ";

				cout << "\n\n\tContinue ? (y/n) ";
				cin >> ch;
				if (ch == 'y')
					remove_tasks(head, tail);
				else
					return;
			}
			else {
				cout << "\n\n==========================================================\n";
				cout << "\n\n\tRemoved successfully ";
				count = print_list(head);
				cin.get();
				return;
			}
		}
	}
}


void Initialize_task(Node *& head){
	cout<<"\n\n==========================================================\n";
	cout<<"\n\tConfirm ? (y/n) ";
	char ch;
	cin>>ch;
	if (ch=='y'){
		ofstream fout("task.txt");
		if (fout.fail()){
			cout<< " Error in file opening!"<<endl;
			exit(1);
		}
		while (head != NULL){
				Node * p = head;
				fout << p->info<<"\n"<<p->info_2<<"\n"<<p->info_3<<endl;
				head = head->next;
				delete p;
		}
		fout.close();
	cout<<"\n\tTasks are cleared.";
	cin.get();
}
else
	return;
}

//***************************************************************
//    	Task trigger for kids part
//****************************************************************

int kids_task_main(){
	char ch;
	string task="";

	Node * head = NULL, * tail = NULL;
	read_task(head, tail);
	do{
	system("cls");
	cout<<"\n\n\n\tTasks Trigger";
	cout<<"\n\n\n\t1. View Tasks";
	cout<<"\n\n\t2. Sort Tasks";
	cout<<"\n\n\t0. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (0-4)? ";
	cin>>ch;

	switch(ch)
	{
	case '1' :view_tasks(head,	tail); break;
	case '2' :Sort_tasks(head);	 break;
	case '0' :break;
	default:	cout<<"\a";
}}while(ch!='0');
 write_file(head);
return 0;
}

void view_tasks(Node * & head,	Node * & tail){
	int done_line,count;
	char ch;
	if (head == NULL){
		cout<<"\n\n==========================================================\n";
		cout<<"\n\tThere is no task.";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();

	}else{
		count= print_list(head);
		cout<<"\n\n==========================================================\n";
		cout<<"\n\tWhich line of task you have done? (0-"<<count-1<<")";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>done_line;
		if (done_line==0)
			return;
		else{
				//cout<<"1";
			cout<<"\n\n\tConfirm ? (y/n) ";
			cin>>ch;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (ch=='y'){
				Node * current = head;
			for (int i = 0;i<done_line-1;i++){
				current=current->next;
				//cout<<"2";
			}
			current->info_3=true;

			count= print_list(head);
			cout<<"\n\n==========================================================\n";
			cout<<"\n\n\tGood job";
			cin.get();
							return;
			}
		}
		}
	}

//***************************************************************
//    	Task trigger general part
//****************************************************************

bool confirm(){
	char ch;
	cout<<"\n\n\tConfirm ? (y/n) ";
	do{
		cin >> ch;
		switch(ch){
			case 'y' :return true; break;
			case 'n' :return false;	 break;
			default:	cout<<"\a";
		}
	}while(true);
}
bool keep_going(){
	char ch;
	cout<<"\n\n\tContinue ? (y/n) ";
	do{
		cin >> ch;
		switch(ch){
			case 'y' :return true; break;
			case 'n' :return false;	 break;
			default:	cout<<"\a";
		}
	}while(true);
}

void write_file(Node *& head){
	ofstream fout("task.txt");
	if (fout.fail()){
		cout<< " Error in file opening!"<<endl;
		exit(1);
	}
	while (head != NULL){
			Node * p = head;
			fout << p->info<<"\n"<<p->info_2<<"\n"<<p->info_3<<endl;
			head = head->next;
			delete p;
	}

	fout.close();
	return;
}
void MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;
	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}


Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->info_2 <= b->info_2) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,	Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

int print_list(Node * head)
{ int count = 1;
	if (head==NULL){
		cout<<"\n\tThere is no task.";
	}else{
	system("cls");
	cout<<"\n\n\n\tTasks\n\n";
  Node * current = head;
	while (current != NULL)
	{
		// process the current node, e.g., print the content
		cout << "\t"<<count<<". "<<current->info<< " $"<<current->info_2<<" "<<
		((current->info_3) ? "Done" : "Doing")<<"\n\n";
		current = current->next;
		count++;
	}
	cout << "\t0. Back to last page";

	return count;
	//cout << "NULL\n";
	}
}

void Sort_tasks(Node * &head){
	char ch;
	cout<<"\n\n==========================================================\n";
	cout<<"\n\tConfirm ? ";
  if (ch='y'){
		MergeSort(&head);
		cout<<"\n\n\tSorted by price successfully. ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin.get();
	}

}
void tail_insert(Node * & head,	Node * & tail, string task, int bonus, bool done = false){
	Node * p = new Node;
	p->info = task;
	//cout<< p->info;
	p->info_2=bonus;
	p->info_3=done;
	p->next = NULL;
	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}
void read_task(Node *& head,	Node * & tail){
	string task;
	int bonus;
	bool done;
	ifstream fin("task.txt");
	while (getline(fin>>ws,task)){
		fin>>bonus>>done;
		tail_insert(head,	tail,  task, bonus, done);
	}
}
