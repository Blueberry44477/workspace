#include <iostream>
#include <array>
#include <vector>
using namespace std;
int func(int x) {
	return x + 2;
}
int* new_array(const int size) {
	return new int[size];
}
int& get_element(vector<int>vec, const int index) {
	return vec[index];
}
int main() {
	int* arr = new_array(5);
	delete[]arr;

	vector <int> vec{ 1,2,3,4,5 };
	get_element(vec, 2) = 7;
	cout << vec[2] << '\n';

	int a = 5;
	cout << func(a) << '\n';
	int (*ptr)(int) = func;
	cout << ptr(10);
	return 0;
}