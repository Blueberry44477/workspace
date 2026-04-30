#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << 3 * j + i << "\t";
		}
		cout << endl;
	}
	cout << "\n";

	system("pause");
	return 0;
}

