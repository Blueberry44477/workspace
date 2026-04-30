#include <windows.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	double number = 0;
	string unit;
	vector <double> values;
	const vector <string> valid_units = { "m", "cm", "in", "ft" };
	bool already_initialized = false;
	double the_smallest = 0;
	double the_biggest = 0;
	double sum = 0;
	cout << "Please, enter a value and a unit (m, cm, in, ft): ";
	while (cin >> number && number > 0) {
		cin >> unit;
		while (find(valid_units.begin(), valid_units.end(), unit) == valid_units.end()) {
			cout << "Invalid unit. Please enter a valid unit (m, cm, in, ft): ";
			cin >> unit;
		}
		system("cls");
		if (unit != "m")
			cout << number << " " << unit << " == ";
		if (unit == "cm")
			number *= 0.01;
		else if (unit == "in")
			number *= 0.03;
		else if (unit == "ft")
			number *= 0.3045;
		cout << number << " m\n";
		if (!already_initialized) {
			the_smallest = number;
			the_biggest = number;
		}
		if (the_smallest > number)
			the_smallest = number;
		if (the_biggest < number)
			the_biggest = number;
		values.push_back(number);
		if (values.size() >= 2) {
			cout << "The smallest so far: " << the_smallest << '\n';
			cout << "The biggest so far: " << the_biggest << '\n';
		}
		sort(values.begin(), values.end());
		cout << "\nNumber of values: " << values.size() << "\nAll sorted values (converted in m): ";
		for (int i = 0;i < values.size();i++)
			if (i == 0 || values[i - 1] != values[i])
				cout << values[i] << " ";
		sum += number;
		cout << "\nSum: "<< sum << "\n\nВведіть число та одиницю вимірювання(cm, m, in, ft): ";
		already_initialized = true;
	}
	cout << "Goodbye\n";
	return 0;
}