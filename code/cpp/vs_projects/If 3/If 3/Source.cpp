#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	for (int i = 10, int j = 90; i <= j; i += 5, j -= 10)
	{
		cout << i << " " << j << endl;
	}
	system("pause");
	return 0;
}

