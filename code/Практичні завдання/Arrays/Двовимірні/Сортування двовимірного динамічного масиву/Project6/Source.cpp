//Напишіть програму, яка:
//-запитує у користувача, скільки імен він хоче ввести;
//-просить користувача ввести кожне ім’я;
//-викликає функцію для сортування імен в алфавітному порядку;
//-виводить відсортований список імен на екран.
#include <iostream>
#include <windows.h>
using namespace std;

char **arr_create(int number_of_names, int name_length) {
	char** a = new char*[number_of_names];
	for (int i = 0; i < number_of_names; i++) {
		a[i] = new char[name_length];
	}
	return a;
}
void arr_init(char**a,int number_of_names, int name_length) {
	for (int i = 0; i < number_of_names; i++) {
		cout << "Введіть ім'я #" << i+1 << ": ";
		cin >> a[i];
	}
	cout << endl;
}
void arr_out(char** a, int number_of_names, int name_length) {
	for (int i = 0; i < number_of_names; i++) {
		cout << "Ім'я #" << i+1 << ": " << a[i] << endl;
	}
}
void sort_array(char** a, int number_of_names, int name_length) {
	for (int i = 0; i < number_of_names - 1; i++) {
		for (int j = 0; j < number_of_names - i - 1; j++) {
			if (strcmp(a[j], a[j + 1]) > 0) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void delete_array(char** a, int number_of_names, int name_length){
	for (int i = 0; i < number_of_names; i++) {
		delete[] a[i];
	}
	delete[] a;
}
int main()
{
	SetConsoleOutputCP(1251);
	const int name_length = 100;
	int number_of_names;
	cout << "Введіть кількість імен: ";
	cin >> number_of_names;
	char **names = arr_create(number_of_names, name_length);
	arr_init(names, number_of_names, name_length);
	sort_array(names, number_of_names, name_length);
	cout << "Відсортований масив:";
	arr_out(names, number_of_names, name_length);
	delete_array(names, number_of_names, name_length);
	return 0;
}