#include <iostream>
#include <windows.h>
#include <random>
using namespace std;
void random_initialize(int* arr, const int size);
void show(const int* arr, const int size);
void selection_sort(int* arr, const int size);
void bubble_sort(int* arr, const int size);
void insertion_sort(int *arr, const int size);
template <typename T>
bool binary_search(const T* arr, const int size, T key);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int SIZE = 10;
	int arr[SIZE];

	random_initialize(arr, SIZE);
	show(arr, SIZE);
	cout << '\n';
	//selection_sort(arr, SIZE);
	bubble_sort(arr, SIZE);
	show(arr, SIZE);
	//insertion_sort(arr, SIZE);
	int key = 0;
	cout << "\nEnter a number: ";
	cin >> key;
	if (binary_search(arr, SIZE, key) == true)
		cout << "Array has your number (" << key << ")";
	else
		cout << "Array doesn`t have your number";
	cout << "\nВпорядкований масив: " << endl;
	show(arr, SIZE);
	cout << '\n';
	system("pause");
	return 0;
}
void random_initialize(int* arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> distrib(-50, 50);
		int random_number = distrib(gen);
		arr[i] = random_number;
	}
}
void selection_sort(int* arr, const int size) {
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[i])
				swap(arr[j],arr[i]);
}
void bubble_sort(int* arr, const int size) {
	for (int i = 0; i < size; i++)
		for (int j = size - 1; j > i; j--)
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
}
void insertion_sort(int* arr, const int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}
template <typename T>
bool binary_search(const T* arr, const int size, T key) {
	int left_bound = 0;
	int right_bound = size - 1;
	do {
		T middle = (left_bound + right_bound) / 2;
		if (key == arr[middle])
			return true;
		else if (key < arr[middle])
			right_bound = middle - 1;
		else if (key > arr[middle])
			left_bound = middle + 1;
	} while (left_bound <= right_bound);
	return false;
}
void show(const int* arr, const int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}