#include <iostream>
#include <windows.h>
#include <random>
#include <iomanip>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	int n, a;
	cout << "К-сть елементів масиву ";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(-50, 50);
		int random_number = distrib(gen);
		*(mas + i) = random_number;
		cout << setw(1) << *(mas + i) << " ";
	}
	cout << endl;
	do {
		cout << "Номер елементу, який потрібно видалити: ";
		cin >> a;
		if (a < 0 || a >= n)
			cout << "Некоректний індекс!" << endl;
	}
	while (a < 0 || a >= n);

	for (int i = a; i < n - 1; i++) 
	{
		*(mas + i) = *(mas + i + 1);
	}
	n--;
	cout << "Масив після видалення елемента: ";
	for (int i = 0; i < n; i++) {
		cout << setw(1) << *(mas + i) << " ";
	}

	cout << endl;

	delete[] mas;
	system("pause");
	return 0;
}