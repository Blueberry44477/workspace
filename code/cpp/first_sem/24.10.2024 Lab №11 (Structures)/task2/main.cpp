/* 1. Створити структуру з ім'ям MARSHRUT, яка містить
наступні поля:
• назва початкового пункту маршруту;
• назва кінцевого пункту маршруту;
• номер маршруту.
2. Розробити програму, яка виконує такі дії:
• ввести з клавіатури дані в масив, що містить 4 елементи 
(структури) типу MARSHRUT; записи мають бути впорядковані 
за назвою початкового пункту;
• вивести на екран інформацію про номер маршруту, 
номер якого введено з клавіатури;
• вивести не екран відповідне повідомлення, якщо таких 
записів не знайдено */

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

struct MARSHRUT {
	string start_point;
	string end_point;
	int route_num;
};

void sortByStartPoint(MARSHRUT routes[], int size) 
{
	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = i + 1; j < size; j++) 
		{
			if (routes[i].start_point > routes[j].start_point) 
			{
				MARSHRUT temp = routes[i];
				routes[i] = routes[j];
				routes[j] = temp;
			}
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 4;
	int number = 1;

	MARSHRUT* a = new MARSHRUT[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Маршрут " << number << endl;
		cout << "Початковий пункт маршруту: ";
		cin >> a[i].start_point;
		cout << "Кінцевий пункт маршруту: ";
		cin >> a[i].end_point;
		cout << "Номер маршруту: ";
		cin >> a[i].route_num;
		cout << endl;
		number++;
	}
	sortByStartPoint(a, n);
	cout <<"--------------------"<< endl << "Упорядкований маршрут: ";
	for (int i = 0; i < n; i++) {
		cout <<endl<< "Маршрут " << a[i].route_num << endl;
		cout << "Початковий пункт маршруту: " << a[i].start_point << endl;
		cout << "Кінцевий пункт маршруту: " << a[i].end_point << endl;
	}
	cout << "--------------------";

	int search_number;
	cout << endl << "Введіть номер маршруту: ";
	cin >> search_number;
	cout << endl;
	bool found = false;
	for (int i = 0; i < n; i++) 
	{
		if (search_number == a[i].route_num) 
		{
			cout << "Маршрут " << a[i].route_num << endl;
			cout << "Початковий пункт маршруту: " << a[i].start_point << endl;
			cout << "Кінцевий пункт маршруту: " << a[i].end_point << endl;
			found == true;
			break;
		}
		if (found == false) {
			cout << "Такого маршруту немає:(" << endl;
		}
	}
	return 0;
}
