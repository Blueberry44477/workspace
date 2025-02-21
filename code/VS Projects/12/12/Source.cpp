#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double base, exp;
	int counter = 0;
	double result = 1;
	cout << "Enter base ";
	cin >> base;
	cout << "Enter exp ";
	cin >> exp;
	while (counter < exp)
	{
		result *= base;
		counter ++;
	}


	cout << "Result = " << result << endl;
	system("pause");
	return 0;
}