#include <iostream>
using namespace std;
int main()
{
	// ++a, a++ називається інкрементом; --a, a-- декремент
	// Постфіксна форма a++, a-- спочатку робить дію, а потім змінює значення
	// Префіксна форма ++a, --a спочатку змінює значення на 1, а потім робить дію
	int a = 1, b;
	cout << "Normal a=" << a << endl;
	b = +1 + ++a;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}