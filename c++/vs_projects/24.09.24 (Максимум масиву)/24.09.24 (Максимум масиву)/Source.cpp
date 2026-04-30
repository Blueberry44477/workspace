#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 5;
	int arr[n], maximum;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (20) - 10; //генерація від 0 до 19 - 10
	}
	maximum = arr[0];
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		if (arr[i] > maximum)
			maximum = arr[i];

	}
	cout << "\n maximum = " << maximum;
	system("pause");
	return 0;
}

