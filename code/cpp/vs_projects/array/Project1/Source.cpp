#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
void show(const array<int, 5>& arr);
template <typename T>
void show_v(const vector<T> &vec);
bool contains_nut(const string& str);
bool even_number(const int &number) {
	return (number % 2 == 0);
}

int main() {
	//find();
	/*array<int, 5> arr{ 1, 2, 3, 4, 5 };
	show(arr);
	cout << "Enter a value to search and replace with: ";
	int search = 0;
	int replace = 0;
	cin >> search >> replace;
	auto element{ find(arr.begin(), arr.end(), search) };
	if (element == arr.end())
		cout << "Could not find " << search;
	else {
		*element = replace;
		show(arr);
	}*/

	//find_if();
	/*vector<string>words{ "Apple","Banana","Lemon","Walnut", "Peanut"};
	show(words);
	auto found{ find_if(words.begin(),words.end(),contains_word) };
	if (found == words.end())
		cout << "No nuts";
	else
		cout << "Found " << *found << '\n';*/

	//count_if();
	/*vector<string>words{ "Apple","Walnut","Lemon","Walnut", "Peanut" };
	show_v(words);
	auto nuts_counted{ count(words.begin(),words.end(),"Walnut")};
	auto nuts_counted_if{ count_if(words.begin(),words.end(),contains_nut) };
	cout << "Walnuts counted: " << nuts_counted << '\n';
	cout << "Nuts counted: " << nuts_counted_if;
	return 0;*/

	vector <int> numbers{ 1,2,3,4,5,6,7,8 };
	auto even_count{ count_if(numbers.begin(),numbers.end(),even_number) };
	cout << even_count;
}

void show(const array<int, 5>& arr) {
	cout << "Array: ";
	for (const auto& x : arr)
		cout << x << ' ';
	cout << '\n';
}
template <typename T>
void show_v(const vector<T>& vec) {
	cout << "Vector: ";
	for (const auto& word : vec)
		cout << word << ' ';
	cout << '\n';
}
bool contains_nut(const string& str) {
	return (str.find("nut") != string::npos);
}