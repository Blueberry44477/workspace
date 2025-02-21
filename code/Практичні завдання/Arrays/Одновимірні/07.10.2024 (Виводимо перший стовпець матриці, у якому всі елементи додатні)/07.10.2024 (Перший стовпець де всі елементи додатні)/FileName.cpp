//Вивести номер першого стовпчика матриці, у якому всі елементи додатні матриці.
#include <iostream>
#include <random>
#include <windows.h>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);

	const int n = 2; // рядки 
	const int m = 10; // колонки
	int A[n][m]{};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(-50, 50);
			int random_number = distrib(gen);
			A[i][j] = random_number;

			cout << setw(5) << A[i][j];
		}
		cout << endl;
	}
	for (int j = 0; j < m; j++) 
	{
		bool allPositive = true;
		for (int i = 0; i < n; i++) 
		{
			if (A[i][j] < 0) 
			{
				allPositive = false;
				break;
			}
		}
		if (allPositive==true)
		{
			cout << "Перший стовпець, де всі елементи додатні: " << j + 1 << endl;
			return 0;
		}
	}
	cout << "Немає стовпців, де всі елементи додатні." << endl;
	system("pause");
	return 0;
}