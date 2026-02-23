#include <iostream>
using namespace std;
class Something {
private:
	int m_a = 5;
public:
	int get_value() {
		return m_a;
	}
};

const int rows = 3;
const int columns = 3;

int main() {
	Something smth;
	Something& ref = smth;
	Something* ptr = &smth;
	cout << ref.get_value() << '\n';
	cout << (*ptr).get_value() << '\n';
	cout << ptr->get_value();

	int a = 5;
	int* ptr_a = &a;
	int** null_ptr = nullptr;
	int** double_ptr = &ptr_a;
	cout <<"\ndouble ptr: " << **double_ptr;

	char* array = new char[20]{ "Hello, World!" };
	cout << '\n';
	for (int i = 0; i < 20; i++)
		cout << array[i];
	cout << "\n\n";

	int** d_array = new int*[rows];
	for (int i = 0; i < rows; i++) 
		d_array[i] = new int[columns];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			d_array[i][j] = 0;
	for (int i = 0; i < rows; i++) {
		cout << '\n';
		for (int j = 0; j < columns; j++)
			cout << d_array[i][j] << " ";
	}
	for (int i = 0; i < columns; i++)
		delete[]d_array[i];
	delete[]array;
}