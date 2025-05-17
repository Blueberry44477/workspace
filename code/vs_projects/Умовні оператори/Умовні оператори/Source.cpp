#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int a;
	cout << "Enter a[5;10] " << endl;
	cin >> a;
	if (a >= 5 && a <= 10)
	{
		a *= 10;
		cout << "a=" << a << endl << "Right" << endl;
	}
	else {
		cout << "Not right" << endl;
	}
	system ("pause");
	return 0;
}