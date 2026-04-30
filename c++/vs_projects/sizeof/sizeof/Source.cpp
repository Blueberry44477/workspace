#include <iostream>
using namespace std;
int main()
{
	//sizeof (Тип даних)
	//sizeof (Вираз/Значення)
	//sizeof Вираз/Значення
	cout << "int: " << sizeof(int) << endl;
	cout << "long: " << sizeof(long) << endl;
	cout << "long long: " << sizeof(long long) << endl;
	cout << sizeof(3+2.0) << endl;

	return 0;
}