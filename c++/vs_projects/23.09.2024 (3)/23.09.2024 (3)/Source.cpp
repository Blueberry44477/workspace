#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float a = 1; 
	float epsilon, dod, s = 0.0;
	cout << "enter epsilon" << endl;
	cin >> epsilon;
	while (s>epsilon)
	{
		a *= 5;
		dod = 1 / a;
		s += dod;
	}
	cout << "s = " << s << endl;
	

	system("pause");
	return 0;
}