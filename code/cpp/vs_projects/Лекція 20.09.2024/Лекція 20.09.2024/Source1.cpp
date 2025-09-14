#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number, dobutok = 1;
	for (int i = 0; i < 10;i++)
	{
		cout << "Input 0 to end" << endl;
		cin >> number;
		if (number != 0)
		dobutok *= number;
	}
	cout << "Добуток = " << dobutok << endl;
	system("pause");
	return 0;
}

