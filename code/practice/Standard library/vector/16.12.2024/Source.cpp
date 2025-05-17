#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <ranges>
using namespace std;
void temp() {
	vector <double> temperatures;
	cout << "Введіть необхідні показники температури(щоб завершити, введіть \"/\"): ";
	for (double temp;cin >> temp;)
		temperatures.push_back(temp);
	cout << "Отримані показники: ";
	for (int i = 0;i < temperatures.size();i++)
		cout << temperatures[i] << " ";
	double sum = 0;
	for (int x : temperatures)
		sum += x;
	cout << "\nВідсортовані показники : ";
	sort(temperatures.begin(), temperatures.end());
	for (int x : temperatures)
		cout << x << " ";
	cout << "\nСередня температура: " << sum / temperatures.size() << "\n";
	if (temperatures.size() % 2 == 0) {
		double center = (temperatures[temperatures.size() / 2] + temperatures[(temperatures.size() / 2) - 1]) / 2.0;
		cout << "Медіана: " << center << "\n";
	}
	else {
		cout << "Медіана: " << temperatures[temperatures.size() / 2] << "\n";
	}
}
void dictionary() {
	vector <string> words;
	cout << "Введіть слова: ";
	for (string temp; cin >> temp;)
		words.push_back(temp);
	cout << "К-сть слів: " << words.size() << "\n";
	sort(words.begin(), words.end());
	cout << "Відсортовані слова:\n";
	for (int i = 0;i < words.size();i++) {
		if (i==0||words[i-1]!=words[i])
			cout << words[i] << "\n";
	}
}
int main() {
	SetConsoleOutputCP(1251);
	int k = 0;
	int a = 0;
	int b = 0;
	do {
		cout << "Виберіть пункт:\n1. Температура\n2. Словник\n3. Програма\n Вибір: ";
		cin >> k;
		switch (k) {
		case 1:
			system("cls");
			temp();
			break;
		case 2:
			system("cls");
			dictionary();
			break;
		case 3:
			system("cls");
			
		default:
			cout << "Такого пункту немає";
			break;
		}
	} while (cin>>k);
	return 0;
}