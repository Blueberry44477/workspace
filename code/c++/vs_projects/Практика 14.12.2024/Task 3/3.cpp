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
	int hundreds = random_number / 100;
	int tens = random_number / 10 % 10;
	int units = random_number % 10;
	int numbers[] = { hundreds, tens, units };
	//cout << random_number << "\n";
	int right_digits = 0;
	int right_positions = 0;
	/*for (int i = 0;i <= 2;i++) {
		cout << numbers[i] << " ";
	}*/
	//cout << hundreds << " " << tens << " " << units << "\n";
	cout << "Комп'ютер загадав число від 0 до 999, вгадайте його! \nПісля чергового числа вам буде повідомлено, скільки цифр вгадано і скільки з них знаходиться на своїх місцях.";
	int count = 0;
	do {
		count++;
		right_digits = 0;
		right_positions = 0;
		cout << "\nВаш варіант: ";
		cin >> number;
		int	number_hundreds = number / 100;
		int number_tens = number / 10 % 10;
		int number_units = number % 10;
		for (int i = 0;i <= 2;i++) {
			if (number_hundreds == numbers[i])
				right_digits++;
			if (number_tens== numbers[i] && number_hundreds != tens)
				right_digits++;
			if (number_units == numbers[i] && number_units != tens && number_units != hundreds)
				right_digits++;
		}
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
	cout << "\n\nВи вгадали!\n";
	cout << "Та ще й за " << count << " спроб!\n";
	system("pause");
	return 0;
}