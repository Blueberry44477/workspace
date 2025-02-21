#include <iostream>
#include <fstream>
using namespace std;

void bubble_sort(int array[], const int size);
void show(const int array[], const int size);
void add_one(int array[], const int size, int number);
void add_several(int array[], const int size, int number_of);
void delete_number(int array[], const int size, int number);
int main() {
	enum Menu {
		ADD_SEVERAL,
		ADD_ONE,
		DELETE,
		EXIT,
	};
	const int size = 20;
	int numbers[size] = {};
	int choice{};
	do {
		cout << "Меню:"
			<< "1. Додати декілька (вказати число)\n"
			<< "2. Додати одне\n"
			<< "3. Видалити одне\n"
			<< "4. Вихід\n"
			<< " Вибір: ";
		cin >> choice;
		switch (choice) {
		case ADD_SEVERAL:

		}
	} while (choice);
	

	return 0;
}
void bubble_sort(int array[], const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}	
}
void show(const int array[], const int size) {
	for (int i = 0; i < size; i++) {
		if (array[i] != 0)
			cout << array[i] << '\n';
	}
}
void add_number(int array[], const int size, int number) {
	bool not_zero = false;
	for (int i = 0; i < size; i++) {

	}
}