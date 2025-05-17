#include <iostream>
#include <random>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>distrib(0, 999);
	int random_number = distrib(gen);
	int number = 0;
	int hundreds = random_number/100;
	int tens = random_number/10%10;
	int units = random_number%10;
	int numbers[] = { hundreds, tens, units };
	cout << random_number << "\n";
	//cout << hundreds << " " << tens << " " << units << "\n";
	cout << "Комп'ютер загадав число від 0 до 999, вгадайте його! Після чергового числа вам буде повідомлено, скільки цифр вгадано і скільки з них знаходиться на своїх місцях.\n";
	do {
		int right_digits = 0;
		int right_positions = 0;
		cout << "\nВаш варіант : ";
		cin >> number;
		for (int i = 0;i < sizeof(numbers);i++) {
			if (hundreds == numbers[i])
				right_digits++;
			if (tens == numbers[i])
				right_digits++;
			if (units == numbers[i])
				right_digits++;
		}
		if (right_digits == 3)
			break;
		if (number / 100 == hundreds) {
			right_positions++;
		}
		if (number / 10 % 10 == tens) {
			right_positions++;
		}
		if (number % 10 == units) {
			right_positions++;
		}
		cout << "Відгадано: " << right_digits << ". На своїх позиціях: " << right_positions;
	} while (random_number != number);
	cout << "\nВи вгадали!\n";
	system("pause");
	return 0;
}