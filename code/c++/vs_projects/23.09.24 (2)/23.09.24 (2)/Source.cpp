#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int x, y, z;
	int sum = 0;
	for (int i = 100; i <= 999; i++)
	{
		x = i / 100;
		y = i / 10 % 10;
		z = i % 10;
		sum = x + y + z;
		if (sum % 9 == 0)
			cout << i << endl;
	}
	cout << "x = " << x << " y = " << y << " z = " << z << endl;
	

	cout << "Sum = " << sum << endl;
	system("pause");
	return 0;
}