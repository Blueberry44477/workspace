#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float m, x, y, z;
	cout << "Enter x,y,z" << endl;
	cin >> x >> y >> z;
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	m = max(fabs(x), max(fabs(y), fabs(z)));
	cout << "m = " << m;
	return 0;
}