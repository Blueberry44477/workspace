#include <iostream>
#include <windows.h>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	int n, m;
	cout << " Введіть к-сть рядків та стовпчиків масиву ";
	cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(-50, 50);
			int random_number = distrib(gen);
			*(*(a + i) + j) = random_number;
			cout << setw(5) << *(*(a + i) + j);
		}
		cout << endl;
	}
	int row1, row2;
	
	//Перевірка
	do
	{
		cout << "Введіть індекси двох рядків: ";
		cin >> row1 >> row2;
		if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
		{
			cout << "Некоректні індекси" << endl;
		}
	} while (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n);


	for (int j = 0; j < m; j++) {
		int temp = *(*(a + row1) + j);
		*(*(a + row1) + j) = *(*(a + row2) + j);
		*(*(a + row2) + j) = temp;
	}

	cout << endl << "Масив після обміну рядків: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(5) << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
	system("pause");
	return 0;
}