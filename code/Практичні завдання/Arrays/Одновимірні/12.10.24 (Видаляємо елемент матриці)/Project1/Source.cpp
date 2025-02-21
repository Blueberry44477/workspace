#include <iostream>
#include <Windows.h>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	int n, a;
	cout << "Enter n ";
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<>distrib(-50, 50);
		int random_number = distrib(gen);
		*(arr + i) = random_number;
		cout <<setw(2)<< *(arr + i) << " ";
	}
	cout << endl;
	do 
	{
		cout << "Введіть номер елементу, який потрібно видалити ";
		cin >> a;
	} while (a < 0 || a >= n);
	for (int i = a; a < n-1; a++)
	{
		*(arr + i) = *(arr + i + 1);
	}
	
	cout << "Оновлений масив: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << *(arr + i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}