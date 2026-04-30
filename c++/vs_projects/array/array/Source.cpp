#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void print(array<int, 4>& arr) {
	for (int i : arr)
		cout << i << " ";
}
void print_vector(vector<int>& obj) {
	cout << '\n';
	for (int i : obj)
		cout << i << " ";
}
int main() {
	array data{ 1,2,3 };
	for (auto* ptr = &data[0]; ptr < (&data[0] + data.size()); ptr++)
		cout << *ptr << " ";
	auto* begin = &data[0];
	auto* end = begin + data.size();
	cout << '\n';

	array<int, 4> arr{ 1,2,3,4 };
	for (auto i{ arr.begin() }; i != arr.end(); i++)
		cout << *i << ' ';
	for (auto i{ std::begin(arr) }; i != std::end(arr); i++)
		cout << *i << ' ';

	array<int, 3> arr{ 1,2,3 };
	for (int x : arr)
		cout << x << ' ';
}