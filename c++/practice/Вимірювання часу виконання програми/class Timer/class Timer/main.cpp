#include <iostream>
#include "Timer.h"
using namespace std;
void sort_array(int array[], int size);
void show(const int array[], const int size);
int main() {
	Timer t;
	int array[] = { 5,3,1,2,93,21 };
	int n = size(array);
	sort_array(array, n);
	cout << "Time elapsed: " << t.elapsed() << '\n';
	show(array, n);
	return 0;
}
void sort_array(int array[], int size) {
	for (int i = 0; i < size - 1; i++) 
		for (int j = 0; j < size - 1 - i; j++) 
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
}
void show(const int array[], int size) {
	for (int i = 0; i < size; i++) {
			cout << i << ' ' << array[i] << '\n';
	}
}