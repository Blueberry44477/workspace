/*
Задано масив дійсних чисел A[n], n <= 500. Розробити програму,
яка обчислює добуток всіх чисел, які повтoрюються, і суму всіх
чисел, які не повторюються. Якщо чисел, що повторюються, або не
повторюються немає, то виводить відповідне повідомлення.*/
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <random>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	int n;

	bool found_repeated = false;
	bool found_non_repeated = false;
	bool first_mult = true;

	double product = 1;
	double sum = 0;
	
	cout << "Введіть к-сть ---> ";
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(-5, 5);
		int random_number = distrib(gen);
		*(mas + i) = random_number;
		cout << setw(3) << *(mas + i) << " ";
	}
	cout << endl;
	cout << "Множимо: ";
	for (int i = 0; i < n; ++i) 
	{
		bool isRepeated = false;
		for (int j = 0; j < n; ++j) 
		{
			if (i != j && *(mas + i) == *(mas + j))
			{
				isRepeated = true;
				break;
			}
		}
		if (isRepeated == true)
		{
			found_repeated = true;
			product *= *(mas + i);
			if (!first_mult) {
				cout << " * ";
			}
			cout << setw(1) << *(mas + i);
			first_mult = false;
		}
		else 
		{
			found_non_repeated = true;
			sum += *(mas+i);
		}
	}
	cout << endl;
	if (found_repeated == true) 
	{
		cout << "Добуток повторюваних чисел: " << product << endl;
	}
	else
	{
		cout << "Повторюваних чисел немає." << endl;
	}

	if (found_non_repeated == true) 
	{
		cout << "Сума неповторюваних чисел: " << sum << endl;
	}
	else 
	{
		cout << "Неповторюваних чисел немає." << endl;
	}
	delete[]mas;
	cout << endl;
	system("pause");
	return 0;
}

