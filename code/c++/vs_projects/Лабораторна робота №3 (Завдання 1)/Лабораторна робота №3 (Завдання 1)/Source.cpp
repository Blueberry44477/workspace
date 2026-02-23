#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float m, x, y;
	cout << "Enter x,y" << endl;
	cin >> x >> y;
	cout << "x = " << x << ", y = " << y << endl;
	m = max(fabs(x), fabs(y));
	cout << "m= " << m;
	return 0;
}