#include <iostream>
using namespace std;
void func(int* ptr) {
	if (!ptr)
		return;
	*ptr = 10;//перейшли за адресою та змінили value 
	ptr = nullptr;//не розіменували та не змінили value

}
void set_to_null (int*& ptr) {
	ptr = nullptr;
}
void show_array(const int* arr, const int size) {
	cout << '\n';
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}
int main() {
	int value = 5;
	int* ptr = &value;
	func(ptr);//вказівник у функцію за адресою, то значення цього вказівника копіюється з аргументу в параметр функції. 
	cout << value << '\n' << ptr;
	set_to_null(ptr);
	if (ptr)
		cout << *ptr;
	else
		cout << "\nptr is null";

	int array[]{ 1,2,3,4,5 };
	const int array_size = size(array);
	const int* arr_ptr = array;
	show_array(arr_ptr, array_size);
	cout << &array[0] << '\n';
	cout << &array;

	return 0;
}