#include <iostream>
#include <windows.h>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	srand(time(NULL));
	const int n = 5;
	const int m = 3;
	const int SIZE = n * m;
	int arr[SIZE], maximum;
	
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (20) - 10; //генерація від 0 до 19 - 10
	}
	maximum = arr[0];
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	for (int i = 0; i < n; i++)
	{
		maximum = arr[i * m];
		for (int j = i * m; j < (i + 1) * m; j++)
		{
			maximum = max(maximum, arr[j]);
		}
	}
	cout << "\n maximum = " << maximum << endl;
	system("pause");
	return 0;
}

