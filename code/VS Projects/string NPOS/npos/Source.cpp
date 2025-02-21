#include <iostream>
using namespace std;
int main() {
	string str{ "Well, look at you" };
	cout << str.size() << '\n';
	cout << "String: " << str << '\n';
	cout << "Enter a word to find: ";
	string word;
	cin >> word;
	size_t pos = str.find(word);
	if (pos != string::npos)
		 cout << "Found \"" << word << "\" at position " << pos;
	else
		cout << "Not found \"" << word << '\"';
	return 0;
}