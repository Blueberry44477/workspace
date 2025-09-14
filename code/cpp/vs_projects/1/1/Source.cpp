#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "Enter a" << endl;
	cin >> a;
	b = a+ ++a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}