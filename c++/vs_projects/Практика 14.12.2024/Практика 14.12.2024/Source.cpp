/*Напишіть програму, яка визначає найменше число в послідовності додатних чисел, 
які ввів користувач. Якщо в послідовності є від’ємні числа, то ви повинні повідомити
про це користувачеві і запропонувати повторити ввід ще раз.*/
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	int a = 0;
	int max = 0;
	cout << "Введіть к-сть чисел, які хочете ввести: ";
	cin >> a;
	int* numbers = new int[a]{};
	for (int i = 0;i < a;i++) {
		do {
			cout << "Введіть невід'ємне число #" << i << ": ";
			cin >> numbers[i];
			if (numbers[i] < 0)
				cout << "Ви ввели від'ємне число! ";
		} while (numbers[i] < 0);
		if (max <= numbers[i])
			max = numbers[i];
	}
	system("cls");
	cout << "Числа: ";
	for (int i = 0;i < a;i++) {
		cout << numbers[i] << " ";
	}
	cout << "\nНайбільше: " << max <<"\n";
	system("pause");
	return 0;
}