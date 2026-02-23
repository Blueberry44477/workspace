//Записати в файл інформацію про власників автомобілів такої
//структури : марка автомобіля, номер, колір, рік випуску, прізвище та ініціали
//власника, адреса власника(вулиця, номер будинку).
//
//Розробити програму, яка дозволяє : а) створити список записів власників
//автомобілів, б) додавати в файл записи про нових власників автомобілів у
//кінець списку, в) переглядати список власників автомобілів, г) вносити зміни у
//запис про власника автомобіля, д) обробляти певним чином інформацію про
//власників автомобілів і виводити результат.
//
//15. Знайти і вивести за алфавітним порядком список власників автомобілів,
//заданого кольору.
#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include "functions.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 100;
	int k = 0;
	Cars_Owners_Information* info = new	Cars_Owners_Information[n];

	enum Menu {
		EXIT,
		INIT,
		SHOW1,
		SHOW2,
		SAVE_TO_FILE,
		READ_FROM_FILE,
		ADD_NEW,
		CHANGE_INFO,
		SHOW_CARS_OF_THE_SELECTED_COLOR,
	};
	do {
		cout << "Натисність:\n";
		cout << "0, щоб ЗАВЕРШИТИ роботу\n";
		cout << "1, щоб ЗАПИСАТИ інформацію про власників авто (якщо вже є, то ДОДАТИ НОВІ ЗАПИСИ)\n";
		cout << "2, щоб ПОКАЗАТИ інформацію про власників авто ПЕРШИМ способом\n";
		cout << "3, щоб ПОКАЗАТИ інформацію про власників авто ДРУГИМ способом\n";
		cout << "4, щоб ЗБЕРЕГТИ інформацію у файл\n";
		cout << "5, щоб ЗЧИТАТИ інформацію з файлу\n";
		cout << "6, щоб ДОДАТИ запис про нового власника авто\n";
		cout << "7, щоб ВНЕСТИ ЗМІНИ у запис про власника авто\n";
		cout << "8, щоб ПОКАЗАТИ власників автомобілів ЗАДАНОГО КОЛЬОРУ ЗА АЛФАВІТНИМ ПОРЯДКОМ\n\n";
		cin >> k;
		
		switch (k) {
		case EXIT:
			system("cls");
			cout << "Завершення роботи\n";
			delete[]info;
			return 0;
		case INIT:
			system("cls");
			int c;
			do {
				cout << "Введіть кількість власників авто, яких потрібно записати: ";
				cin >> c;
			} while (c == 0 || c < 0 || c > n || c == n);
			c--;
			Init(info, n, c);
			break;
		case SHOW1:
			system("cls");
			if (!already_initialized)
				cout << "Немає інформації\n\n";
			else
				Show_info_1(info, n);
			break;
		case SHOW2:
			system("cls");
			if (!already_initialized)
				cout << "Немає інформації\n\n";
			else
				Show_info_2(info, n);
			break;
		case SAVE_TO_FILE:
			if (!already_initialized) {
				system("cls");
				cout << "Немає інформації\n\n";
			}
			else
				Save(info, n);
			break;
		case READ_FROM_FILE:
			system("cls");
			Read_from_file(info, n);
			break;
		case ADD_NEW:
			system("cls");
			Show_info_1(info, n);
			Add_new_info(info, n);
			break;
		case CHANGE_INFO:
			if (!already_initialized) {
				system("cls");
				cout << "Немає інформації\n\n";
			}
			else
				system("cls");
				Change_info(info, n);
			break;
		case SHOW_CARS_OF_THE_SELECTED_COLOR:
			if (!already_initialized) {
				system("cls");
				cout << "Немає інформації\n\n";
			}
			else
				Show_cars_of_the_selected_color_in_alphabetic_order(info, n, owner_number);
			break;
		default:
			system("cls");
			cout << "Введіть наявний номер пункту меню\n\n";
		}
	} while (k);
	delete[]info;
	return 0;
}
