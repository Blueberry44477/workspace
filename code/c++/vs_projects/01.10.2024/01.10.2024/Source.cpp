#include <iostream>
#include <windows.h>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 4;//к-сть стовпців
	const int m = 4;//к-сть рядків
	int matrix[n][m];
	int sum = 0;
	cout << "Matrix = " << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(-50, 50);
			int random_number = distrib(gen);
			matrix[i][j] = random_number;
			//cout.width(4); те саме, але бібліотека не потрібна
			cout <<setw(5)<< matrix[i][j] << " ";
			//елементи діагоналі мають однакові i,j(у квадратній матриці)
		}
		cout << endl;
	}
	/*
	cout << "Елементи головної діагоналі: ";
	for (int i = 0; i < n;i++)
	{
		sum += matrix[i][i];
		cout << matrix[i][i] << " ";
	}
	cout << endl << sum << endl;
	*/
	
	/*
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (i < j)
			{
				matrix[i][j] = 2;
			}
			else if (j > j)
			{
				matrix[i][j] = 3;
			}
			else matrix[i][j] = 4;
		}
	}
	cout << endl << endl;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cout << setw(5) << matrix[i][j] << " ";
		}
		cout << endl;
	}
	*/


	system("pause");
	return 0;
}

