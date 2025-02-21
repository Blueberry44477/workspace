#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double base, exp;
	int count = 0;
	double result = 1;
	cout << "Enter base ";
	cin >> base;
	cout << "Enter exp ";
	cin >> exp;
	while (count < exp)
	{
		result *= base;
		count++;
	}
	cout << "result = " << result << endl;

	system("pause");
	return 0;
}