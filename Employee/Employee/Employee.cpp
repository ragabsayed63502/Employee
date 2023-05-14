#include <iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>    
#include<iomanip>
using namespace std;
void speed_code() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/

string uppercase(string s) {
	transform(s.begin(), s.end(), s.begin(), ::toupper); return s;
}
string lowercase(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower); return s;
}
int max2(int a, int b) { if (a > b) return a; return b; }
int min2(int a, int b) { if (a < b)return a; return b; }
int max3(int a, int b, int c) { return max2(a, max2(b, c)); }
int min3(int a, int b, int c) { return min2(a, min2(b, c)); }
/*****************************Goobaa*******************************/
const int num = 1000000;
string names[num]; int ages[num], add = 0; double salares[num]; char gender[num];
void EmployeeSystem();
int Menu();
void readEmployee();
void print_all_Employee();
void update_salary_by_name();
void update_gendre_by_name();
void delete_by_age();
int main()
{
	speed_code();
	EmployeeSystem();
	return 0;
}
void EmployeeSystem() {
	//cout << "\nPlease,Enter choice number: " << endl;
	while (1) {
		int choice = Menu();
		if (choice == 1)readEmployee();
		else if (choice == 2)print_all_Employee();
		else if (choice == 3)delete_by_age();
		else if (choice == 4)update_salary_by_name();
		else if (choice == 5)update_gendre_by_name();
		else break;

	}
}
//menu
int Menu() {
	int choice = -1;
	while (choice == -1) {
		cout << "\nPlease,Enter choice number: " << endl;
		cout << "To Add Employee Enter 1: " << endl;
		cout << "To print Employees Enter 2: " << endl;
		cout << "To delete Employee by age Enter 3: " << endl;
		cout << "To update salary by name Employee Enter 4: " << endl;
		cout << "To update gendre by name Employee Enter 5: " << endl;
		cout << "To exit from applicatoin Enter 6: " << endl;
		cin >> choice;
		if (!(choice >= 1 && choice <= 6)) {
			cout << "please Enter number another ,becose the number invald\n";
			choice = -1;
		}
	}
	return choice;
}
void readEmployee() {
	cout << "Enter name: \n";
	cin >> names[add];
	cout << "Enter age: \n";
	cin >> ages[add];
	cout << "Enter salary: \n";
	cin >> salares[add];
	cout << "Enter gendre (m=male or f=famle ): \n";
	cin >> gender[add];
	add++;
}
void print_all_Employee() {
	for (size_t i = 0; i < add; i++) {
		if ((ages[i]) != -1) {
			cout << "Name: " << names[i] << endl << "Age: " << ages[i] << endl << "Salary: " << salares[i] << endl << "Gendre: " << gender[i] << endl;
		}
		if (i + 1 < add)cout << "***************************************\n";
	}
}
void update_salary_by_name() {
	cout << "please,Enter name and salary: ";
	string name; double salary; cin >> name >> salary;
	bool isFound = false;
	for (size_t i = 0; i < add; i++) {
		if (ages[i] != -1 && names[i] == name) {
			salares[i] = salary; isFound = true; break;
		}

	}
	if (isFound == false)
		cout << "No Employee with this name.\n";
}
//update gendre
void update_gendre_by_name() {
	cout << "please enter name and gendre: \n";
	string name; char g; cin >> name >> g;
	bool isFound = false;
	for (size_t i = 0; i < add; i++) {
		if (ages[i] != -1 && names[i] == name) {
			gender[i] = g; isFound = true; break;
		}
	}
	if (isFound == false)
		cout << "No Employee with this name.\n";
}
void delete_by_age() {
	cout << "please Enter start and end age: \n";
	int start, end; cin >> start >> end;
	for (size_t i = 0; i < add; i++) {
		if (!(start <= ages[i] && ages[i] <= end))
			ages[i] = -1;
	}
}