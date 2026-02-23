#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	cout << "¬вед≥ть a" << endl;
	cin >> a;
	if ((a % 3) == 0 and a > 0)
	{
		cout << "„исло а = " << a << " кратне трьом" << endl;
	}
	else {
		cout << "„исло a = " << a << " не кратне трьом" << endl;
	}
	system("pause");
	return 0;
}