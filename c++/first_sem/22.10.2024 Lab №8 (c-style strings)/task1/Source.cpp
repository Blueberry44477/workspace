#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <windows.h>
#include <cctype>
#include <iomanip>
/*Задано деякий текст. Перерахувати всі слова заданого рядка, які 
починаються з тієї ж букви, що і перше слово рядка.*/
using namespace std;
int main(){
	
	const int size = 200;
	SetConsoleOutputCP(1251);

	char st[size] = {"Sun shone softly, spreading its serene light across the silent scene. "};
	char delim[] = " ";
	cout << st;
	char *token = strtok(st, delim);
	if (token == nullptr) {
		cout << "Рядок порожній!" << endl;
		return 0;
	}
	char first_letter = tolower(*token);
	cout << endl << "Перша буква: " << first_letter;

	int count = 0;
	int i = 0;
	cout << endl;
	while (token != NULL) {
		count++;
		cout << count << " " << token;
		if (tolower(*token) == first_letter) {
			cout <<" ---> починається з: " << first_letter << " ";
			i++;
		}
		cout << endl;
		token = strtok(NULL, delim);
		
	}
	cout << endl<< "Слів, що починаються з тієї ж букви, що й перше слово рядка: " << i << endl;
	system("pause");
	
	return 0;
}
