#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	float x, y, z;
	bool v, p, q;
	cout << "¬вед≥ть x, y, z" << endl;
	cin >> x >> y >> z;
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << "¬вед≥ть p, q (true and false)" << endl;
	cin >> p >> q;
	if (p==q)
	{
		cout << "p = q" << endl;
		system("pause");
		return 0;
	}
	cout << "p = " << p << ", q = " << q << endl;
	
	if (max(fabs(x), max(fabs(y), fabs(z))) > 2 * pow(x, 2))
	{
		v = p;
		cout << "v = " << p << endl;
	}
	else if (min(fabs(x), min(fabs(y), fabs(z))) <= 2 * pow(x, 2))
	{
		v = q;
		cout << "v = " << q << endl;
	}
	system("pause");
	return 0;
}