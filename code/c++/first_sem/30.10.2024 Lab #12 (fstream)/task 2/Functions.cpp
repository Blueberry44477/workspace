#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <Windows.h>
using namespace std;

void Init(Cars_Owners_Information* info, int n, int c) {
	cout << "˜˜˜˜˜˜˜˜˜˜˜˜. ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜\n\n";
	for (int i = 0; i <= c; i++) {
		cout << "˜˜˜˜˜˜˜ # " << owner_number + 1 << '\n';
		cout << "˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
		cin >> info[i].brand;
		cout << "˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
		cin.ignore();
		cin.getline(info[i].number, sizeof(info[i].number));
		cout << "˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
		cin.getline(info[i].color, sizeof(info[i].color));
		cout << "ã˜ ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
		cin >> info[i].car_manufacture_year;
		cout << "˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: ";
		cin.ignore();
		cin.getline(info[i].owner_name, sizeof(info[i].owner_name));
		cout << "˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: ";
		cin.getline(info[i].address, sizeof(info[i].address));
		owner_number++;
		cout << '\n';
	}
	already_initialized = true;
}

void Show_info_1(Cars_Owners_Information* info, int n) {
	cout << "˜˜˜˜˜ ˜˜˜˜˜˜˜˜: " << owner_number << "\n";
	cout << "˜˜˜˜˜˜˜˜˜˜˜: " << n << "\n";
	cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜.\n\n";
	cout << "#\t"
		<< "˜˜˜˜˜\t"
		<< "˜˜˜˜˜\t"
		<< "˜˜˜˜\t"
		<< "ã˜\t"
		<< "˜˜˜˜˜˜˜\t\t"
		<< "˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜\t";
	cout << "\n-------------------------------------------------------------------------\n";
	for (int i = 0; i < owner_number; i++) {
		cout << i + 1 << "\t"
			<< info[i].brand << "\t"
			<< info[i].number << "\t"
			<< info[i].color << "\t"
			<< info[i].car_manufacture_year << "\t"
			<< info[i].owner_name << "\t"
			<< info[i].address << endl;
	}
	cout << endl;
}
void Show_info_2(Cars_Owners_Information* info, int n) {
	cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜:\n"
		<< "˜˜˜˜˜ ˜˜˜˜˜˜˜˜: " << owner_number << "\n\n";
	for (int i = 0; i < owner_number; i++) {
		cout << "˜˜˜˜˜˜˜ #" << i + 1 << endl;
		cout << "˜˜˜˜˜: " << info[i].brand << endl
			<< "˜˜˜˜˜: " << info[i].number << endl
			<< "˜˜˜˜: " << info[i].color << endl
			<< "ã˜ ˜˜˜˜˜˜˜˜˜˜˜˜: " << info[i].car_manufacture_year << endl
			<< "˜˜˜˜˜˜˜: " << info[i].owner_name << endl
			<< "˜˜˜˜˜˜: " << info[i].address << endl << endl;
	}
}
void Save(Cars_Owners_Information* info, int n) {
	system("cls");
	ofstream file_write("Cars owners information.txt");
	file_write << owner_number << endl;
	for (int i = 0; i < owner_number; i++) {
		file_write << info[i].brand << endl
			<< info[i].number << endl
			<< info[i].color << endl
			<< info[i].car_manufacture_year << endl
			<< info[i].owner_name << endl
			<< info[i].address << endl;
	}
	file_write.close();
	cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜\n\n";
}
void Read_from_file(Cars_Owners_Information* info, int n) {
	ifstream file_read("Cars owners information.txt");
	if (!file_read.is_open())
		cout << "No file\n\n";
	else {
		file_read.seekg(0, std::ios::end); //˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜ ˜˜˜˜˜
		if (file_read.tellg() == 0) // ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜. ˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜, ˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ tellg() ˜˜˜˜˜˜˜ 0.
		{
			cout << "˜˜˜˜ ˜˜˜˜˜˜˜˜\n\n";
			return;
		}
		else {
			file_read.seekg(0, std::ios::beg);
			file_read >> owner_number;
			for (int i = 0; i < n; i++) {
				file_read >> info[i].brand
					>> info[i].number
					>> info[i].color
					>> info[i].car_manufacture_year;
				file_read.ignore();
				file_read.getline(info[i].owner_name, sizeof(info[i].owner_name));
				file_read.getline(info[i].address, sizeof(info[i].address));
			}
			file_read.close();
			already_initialized = true;
			cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜\n\n";
		}
	}
}
void Change_info(Cars_Owners_Information* info, int n) {
	int i, k;
	bool* changed = new bool(false);

	system("cls");
	Show_info_1(info, n);
	cout << "˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜.\n\n";
	do {
		cout << "˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜, ˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜: ";
		cin >> i;
		i--;
	} while (i > owner_number - 1 || i <= -1);
	system("cls");
	do {
		cout << "˜˜˜˜˜˜˜ #" << i + 1 << ":" << endl
			<< "1. ˜˜˜˜˜ ˜˜˜˜: " << info[i].brand << endl
			<< "2. ˜˜˜˜˜: " << info[i].number << endl
			<< "3. ˜˜˜˜: " << info[i].color << endl
			<< "4. ã˜ ˜˜˜˜˜˜˜˜˜˜˜˜: " << info[i].car_manufacture_year << endl
			<< "5. ˜˜˜˜˜˜˜: " << info[i].owner_name << endl
			<< "6. ˜˜˜˜˜˜: " << info[i].address << endl << endl
			<< "0. ˜˜?˜\n\n";
		cout << "˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜, ˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜: ";
		cin >> k;
		system("cls");
		switch (k) {
		case 0:
			system("cls");
			if (*changed == true)
				cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜\n\n";
			delete[]changed;
			return;
		case 1:
			cout << "˜˜˜˜˜ ˜˜˜˜: ";
			cin >> info[i].brand;
			*changed = true;
			system("cls");
			break;
		case 2:
			cout << "˜˜˜˜˜: ";
			cin >> info[i].number;
			*changed = true;
			system("cls");
			break;
		case 3:
			cout << "˜˜˜˜: ";
			cin >> info[i].color;
			*changed = true;
			system("cls");
			break;
		case 4:
			cout << "ã˜ ˜˜˜˜˜˜˜˜˜˜˜˜: ";
			cin >> info[i].car_manufacture_year;
			*changed = true;
			system("cls");
			break;
		case 5:
			cout << "˜˜˜˜˜˜˜: ";
			cin >> info[i].owner_name;
			*changed = true;
			system("cls");
			break;
		case 6:
			cout << "˜˜˜˜˜˜: ";
			cin >> info[i].address;
			*changed = true;
			system("cls");
			break;
		default:
			system("cls");
			cout << "˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜\n";
		}
	} while (k);
}
void Add_new_info(Cars_Owners_Information* info, int n) {
	/*ofstream file_add_info("Cars owners information.txt", ios_base::app);*/
	cout << "\n˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜\n";
	cout << "˜˜˜˜˜˜˜ # " << owner_number + 1;
	cout << "\n\n˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
	cin >> info[owner_number].brand;
	cout << "˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
	cin.ignore();
	cin.getline(info[owner_number].number, sizeof(info[owner_number].number));
	cout << "˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
	cin.getline(info[owner_number].color, sizeof(info[owner_number].color));
	cout << "ã˜ ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜: ";
	cin >> info[owner_number].car_manufacture_year;
	cout << "˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: ";
	cin.ignore();
	cin.getline(info[owner_number].owner_name, sizeof(info[owner_number].owner_name));
	cout << "˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜: ";
	cin.getline(info[owner_number].address, sizeof(info[owner_number].address));
	/*file_add_info << info[owner_number].brand << endl
		<< info[owner_number].number << endl
		<< info[owner_number].color << endl
		<< info[owner_number].car_manufacture_year << endl
		<< info[owner_number].owner_name << endl
		<< info[owner_number].address << endl;
	file_add_info.close();*/
	system("cls");
	owner_number++;
	cout << "˜˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜\n";
	already_initialized = true;
}
void Show_cars_of_the_selected_color_in_alphabetic_order(Cars_Owners_Information* info, int n, int owner_number) {
	system("cls");
	Show_info_1(info, n);
	char* color = new char[20];
	bool* found_color = new bool(false);
	cout << "˜˜˜˜˜˜ ˜˜˜˜: ";
	cin >> color;

	char** a = new char* [owner_number];
	for (int i = 0; i < owner_number; i++)
	{
		a[i] = new char[20];
	}
	int count = 0;
	for (int i = 0; i < owner_number; i++)
	{
		if (_stricmp(color, info[i].color) == 0) {
			strcpy(a[count], info[i].owner_name);
			count++;
			*found_color = true;
		}
	}
	if (*found_color == false)
	{
		for (int i = 0; i < owner_number; i++)
			delete[]a[i];
		delete[]a;
		delete[]found_color;
		cout << "˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜\n\n";
		return;
	}
	for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			if (_stricmp(a[i], a[j]) > 0) {
				char temp[20];
				strcpy(temp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], temp);
			}
		}
	}
	cout << "\n˜˜˜˜˜˜˜˜:\n";
	for (int i = 0; i < count; ++i) {
		cout << a[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < owner_number; i++)
		delete[]a[i];
	delete[]a;
	delete[]found_color;
}