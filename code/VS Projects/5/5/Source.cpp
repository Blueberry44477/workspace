#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	//swap(c, d);
	//buf, temp
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x, y, z, c, d;
	float v;
	cout << "¬вед≥ть x" << endl;
	cin >> x;
	cout << "¬вед≥ть y" << endl;
	cin >> y;
	cout << "¬вед≥ть z" << endl;
	cin >> z;
	cout << "¬вед≥ть c" << endl;
	cin >> c;
	cout << "¬вед≥ть d" << endl;
	cin >> d;
	if (c > d)
	{
		swap(c, d);
	}
	if (c < x && x < d)
	{
		v = max(x, max(y, z));
	}
	else if (x < c)
	{
		v = pow(x, y);
	}
	else
	{
		v = (x + y) / c;
	}
	cout << "v=" << v << endl;
	system("pause");
	return 0;
}

