#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double base, exp = 1;
	int count = 0;
	double result = 1;
	cout << "Enter x ";
	cin >> base;
	while (count < exp)
	{
		result = result * base;
		count++;
		exp++;
	}
	cout << result;
	system("pause");
	return 0;
}
